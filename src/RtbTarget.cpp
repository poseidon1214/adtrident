#include "im_query_filter.h"
#include "RtbUtil.h"
#include "RtbTarget.h"
#include "common.h"
#include <boost/format.hpp>  
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp> 
#include <sstream>

namespace ad {
namespace rtb {

int RtbTarget::init(ProcessData* process_data, ThreadData* thread_data, std::string config_path)
{
    _config_path = config_path;
    pd = process_data;
    td = thread_data;
    ct_res.reserve(MAX_ADLIST_LEN);
    ut_res.reserve(MAX_ADLIST_LEN);
    rt_res.reserve(MAX_ADLIST_LEN);
    _redis_handler = new RedisOp(_config_path);
    _redis_handler -> connect_db();

    return 0;
}

void RtbTarget::destroy()
{
    _redis_handler->disconnect_db();
    delete _redis_handler;
}

int RtbTarget::clear()
{
    ct_res.clear();
    ut_res.clear();
    rt_res.clear();
    ct_res_dict.clear();
    page_context.clear();
    return 0;
}

int RtbTarget::target()
{
    //ping request
    if(td->bid_request->is_ping()) {
        td->bid_response->set_id(td->bid_request->id());
        return 0;
    }
    
    //test request
    //if(td->bid_request->is_test()) {
    if(1) {
        const AdxRtb::BidRequest::AdSlot& adslot = td->bid_request->adslot(0);
        td->bid_response->set_id(td->bid_request->id());
        AdxRtb::BidResponse::Ad* ad = td->bid_response->add_ad();
        ad->set_sequence_id(adslot.sequence_id());
        ad->set_creative_id(12);
        ad->set_max_cpm(adslot.minimum_cpm());
        return 0;
    }

    int ret = 0;

    ret = pre_process();
    if(ret < 0) {
        WRITE_LOG(UL_LOG_WARNING, "pre_process failed.");
        return -1;
    }

    ret = context_target();
    if(ret < 0) {
        WRITE_LOG(UL_LOG_WARNING, "context_target failed. ");
    }

    ret = user_target();
    if(ret < 0) {
        WRITE_LOG(UL_LOG_WARNING, "user_target failed. ");
    } 

    ret = retarget();
    if(ret < 0) {
        WRITE_LOG(UL_LOG_WARNING, "retarget failed. ");
    }

    ret = merge_target_res();
    if(ret < 0) {
        WRITE_LOG(UL_LOG_WARNING, "merge_target_res failed. ");
    }


    fill_ad_info();
   
    ret = ad_filter();
    if(ret < 0) {
        WRITE_LOG(UL_LOG_WARNING, "ad_filter failed. ");
    }

    ret = select_idea();
    if(ret < 0) {
        WRITE_LOG(UL_LOG_WARNING, "select_idea failed. ");
    }

    ret = bidding();
    if(ret < 0) {
        WRITE_LOG(UL_LOG_WARNING, "bidding failed. ");
    }


    return 0;
}

int RtbTarget::bidding()
{
    td->bid_response->clear_ad();
    td->bid_response->set_id(td->bid_request->id());
    
    const AdxRtb::BidRequest::AdSlot& adslot = td->bid_request->adslot(0);
    ad->set_max_cpm(adslot.minimum_cpm());

    if(adv_list.size() == 0) {
        return 0;
    }
    base::hash_map<uint64_t, ad::rtb::adv_t>::iterator it = adv_list.begin();
    ad::rtb::adv_t* chosen = NULL;
    uint64_t max_bid = 0;
    while(it!=adv_list.end()) {
        if(it->second.base_bid > max_bid) {
            max_bid = it->second.base_bid;
            chosen = &(it->second);
        }
        ++it;
    }
    WRITE_LOG(UL_LOG_WARNING, "bidding select unitid[%lu] ideaid[%lu] bid[%lu]",
        chosen->unitid, chosen->idea_info.ideaid(), chosen->base_bid);

    if(adv_list.size() > 0) {
        //edit by shenguolong 20160103
        if(chosen->base_bid >= adslot.minimum_cpm()) {
            AdxRtb::BidResponse::Ad* ad = td->bid_response->add_ad();
            // 每次检索仅1个广告位
            //ad->set_sequence_id(1);
            ad->set_sequence_id(adslot.sequence_id());
            ad->set_creative_id(chosen->idea_info.ideaid());
            ad->set_max_cpm(chosen->base_bid);
        }
    }

    return 0;
}

int RtbTarget::select_idea_one_ad(const vector<uint64_t>& idea_list, ad::rtb::idea_info& selected) {
    vector<ad::rtb::idea_info> cand;
    const AdxRtb::BidRequest::AdSlot& adslot = td->bid_request->adslot(0);
    for(uint32_t i = 0; i < idea_list.size(); i ++) {
        ad::rtb::idea_info idea;
        if (xbuiltin::RESULT_FOUND != RtbDict::instance().idea_info_dict.seek(idea_list[i],
                &idea)) {
            WRITE_LOG(UL_LOG_WARNING, "idea [%lu] not existed. ", idea_list[i]);
            return -1;
        }
        bool valid_creative_type = false;
        for(int j = 0; j < adslot.creative_type_size(); j++) {
            if(adslot.creative_type(j) == int(idea.creative_type())) {
                valid_creative_type = true;
                break;
            }
        }
        if(!valid_creative_type) {
            WRITE_LOG(UL_LOG_WARNING, "creative type filtered idea[%lu]", idea_list[i]);
            continue;
        }

        if(adslot.height() != int(idea.height()) || adslot.width() != int(idea.width())) {
            WRITE_LOG(UL_LOG_WARNING, "slot size filtered idea[%lu]", idea_list[i]);
            continue;
        }
        if(excluded_url.find(idea.url()) != excluded_url.end()){
            WRITE_LOG(UL_LOG_WARNING, "url blacklist size filtered idea[%lu]", idea_list[i]);
            continue;
        }
        
        cand.push_back(idea);
    }
    if(cand.size() == 0) {
        return -1;
    }
    uint32_t index = rand() % (cand.size());
    selected = cand[index];
    return 0;
}

int RtbTarget::select_idea() {
    int ret = 0;
    base::hash_map<uint64_t, ad::rtb::adv_t>::iterator it = adv_list.begin();
    while(it!=adv_list.end()) {
        ad::rtb::adv_t& adv = it->second;
        ad::rtb::unit_idea unit_idea_list;
        vector<uint64_t> idea_list;
        if (xbuiltin::RESULT_FOUND == RtbDict::instance().unit_idea_dict.seek(adv.unitid,
                &unit_idea_list)) {
            for(int i = 0; i < unit_idea_list.ideaid_size(); i++) {
                idea_list.push_back(unit_idea_list.ideaid(i));
            }
            ret = select_idea_one_ad(idea_list, adv.idea_info);
            if(-1 == ret) {
                WRITE_LOG(UL_LOG_WARNING, "idea select filtered unit[%lu]", it->first);
                adv_list.erase(it++);
                continue;
            }
            WRITE_LOG(UL_LOG_WARNING, "idea select passed unitid[%lu] ideaid[%lu]", 
                adv.unitid, adv.idea_info.ideaid());
        }
        ++it;
    }
    return 0;
}


void RtbTarget::fill_ad_info() {
    for (target_res_t i:target_res) {
        ad::rtb::adv_t adv;

        adv.unitid = i.unitid;
        adv.base_bid = i.bid;

        if (xbuiltin::RESULT_FOUND != RtbDict::instance().unit_info_dict.seek(adv.unitid,
                &(adv.unit_info))) {
            continue;
        }
        if (xbuiltin::RESULT_FOUND != RtbDict::instance().user_info_dict.seek(adv.unit_info.userid(),
                &(adv.user_info))) {
            continue;
        }
        if (xbuiltin::RESULT_FOUND != RtbDict::instance().plan_info_dict.seek(adv.unit_info.planid(),
                &(adv.plan_info))) {
            continue;
        }
        adv_list[adv.unitid] = adv;
    }
    WRITE_LOG(UL_LOG_WARNING, "fill_ad_info get ads size[%lu]", adv_list.size());
}

//all ad have the region limit, so filter the ad set by region
void RtbTarget::ad_filter_region() {
    uint32_t ori_size = adv_list.size();
    if(td->bid_request->has_user_geo_info()) {
        const AdxRtb::BidRequest::Geo& user_geo_info = td->bid_request->user_geo_info();
        if(user_geo_info.has_user_location()) {
            const AdxRtb::BidRequest::Geo::UserLocation& user_location = user_geo_info.user_location();

            base::hash_map<uint64_t, ad::rtb::adv_t>::iterator it = adv_list.begin();
            while(it!=adv_list.end()) {
                if(it->second.plan_info.region().find_first_of(user_location.city()) !=
                    string::npos) {
                    WRITE_LOG(UL_LOG_WARNING, "region passed unit[%lu]: req_region[%s], ad_region[%s]", 
                        it->first, user_location.city().c_str(), it->second.plan_info.region().c_str());
                    it++;
                } else {
                    WRITE_LOG(UL_LOG_WARNING, "region filtered unit[%lu]: req_region[%s], ad_region[%s]", 
                        it->first, user_location.city().c_str(), it->second.plan_info.region().c_str());
                    adv_list.erase(it++);
                }
            }
        }
    }
    WRITE_LOG(UL_LOG_WARNING, "region filter ad. before size[%u], after size[%lu]",
        ori_size, adv_list.size());
}

void RtbTarget::ad_filter_blacklist() {
    uint32_t ori_size = adv_list.size();
    std::string val;
    _redis_handler -> get_redis_key(td->bid_request->ip(), val); 
    if(val == "ip_black_list") {
       adv_list.clear(); 
    }
    WRITE_LOG(UL_LOG_WARNING, "black_list filter ad. before size[%u], after size[%lu]",
        ori_size, adv_list.size());
}

void RtbTarget::ad_filter_flow_type() {
    uint32_t ori_size = adv_list.size();
    std::string _flow_type = "pc";

    const AdxRtb::BidRequest::AdSlot& adslot = td -> bid_request -> adslot(0);

    if(td -> bid_request -> has_mobile()) {
        _flow_type = "mobile";
    }
    if(td -> bid_request -> has_mobile() && td -> bid_request -> has_url()) {
        _flow_type = "wap";
    }
    if(td -> bid_request -> has_video()) {
        _flow_type = "video";
    }
    if(adslot.has_link_unit_info() && (adslot.creative_type(0) == 5)) {
        _flow_type = "lu";
    } 
    base::hash_map<uint64_t, ad::rtb::adv_t>::iterator it = adv_list.begin();
    while(it!=adv_list.end()) {
        if(it->second.plan_info.flowtype().find_first_of(_flow_type) != string::npos) {
            WRITE_LOG(UL_LOG_WARNING, "flow_type passed unit[%lu]: flow_type[%s], ad_flow_type[%s]", 
                it->first, _flow_type.c_str(), it->second.plan_info.flowtype().c_str());
            it++;
        } else {
            WRITE_LOG(UL_LOG_WARNING, "flow_type passed unit[%lu]: flow_type[%s], ad_flow_type[%s]", 
                it->first, _flow_type.c_str(), it->second.plan_info.flowtype().c_str());
            adv_list.erase(it++);
        }
    }
    WRITE_LOG(UL_LOG_WARNING, "flow_type filter ad. before size[%u], after size[%lu]",
        ori_size, adv_list.size());
}

//we only put our ads in first slot
void RtbTarget::ad_filter_slot() {
    uint32_t ori_size = adv_list.size();
    const AdxRtb::BidRequest::AdSlot& adslot = td -> bid_request -> adslot(0);
    int32_t _slot_visibility = adslot.slot_visibility();
    if(_slot_visibility != 1) {
        adv_list.clear();    
    }
    WRITE_LOG(UL_LOG_WARNING, "slot filter ad. before size[%u], after size[%lu]",
        ori_size, adv_list.size());
}

//we set the time window of every ad, out of time ,the ad will be fucked
void RtbTarget::ad_filter_timewindow() {
    uint32_t ori_size = adv_list.size();
    uint32_t wday = dayofweek();
    int32_t current_hour = hourofday();

    base::hash_map<uint64_t, ad::rtb::adv_t>::iterator it = adv_list.begin();
    while(it!=adv_list.end()) {
        std::vector<std::string> week_hour;
        split(it->second.plan_info.cyc(), ";", week_hour);
        if(week_hour.size() != DAY_OF_WEEK) {
            WRITE_LOG(UL_LOG_WARNING, "invalid plan cyc conf. [%s]", 
                it->second.plan_info.cyc().c_str());
            it++;
            continue;
        }

        std::vector<std::string> hour_range;
        split(week_hour[wday], "-", hour_range);
        
        if(hour_range.size() != 2) {
            it++;
            continue;
        }
        if(current_hour < str2int(hour_range[0]) || current_hour > str2int(hour_range[1])) {
            WRITE_LOG(UL_LOG_WARNING, "time filtered unit[%lu]: cur day[%u] hour[%u], ad_cyc[%s]", 
                it->first, wday, current_hour, it->second.plan_info.cyc().c_str());
            adv_list.erase(it++);    
        } else {
            WRITE_LOG(UL_LOG_WARNING, "time passed unit[%lu]: cur day[%u] hour[%u], ad_cyc[%s]", 
                it->first, wday, current_hour, it->second.plan_info.cyc().c_str());
            it++;
        }
    }
    WRITE_LOG(UL_LOG_WARNING, "time cyc filter ad. before size[%u], after size[%lu]",
        ori_size, adv_list.size());
}


int RtbTarget::ad_filter() {
    ad_filter_region();

    ad_filter_flow_type();

    ad_filter_timewindow();

    ad_filter_blacklist();
    return 0;
}

int RtbTarget::seek_user_ad(RedisOp* redis_handler, 
    pair<TYPE_REQUEST_ID, string>& id, 
    hash_map<uint64_t, uint64_t>& ad_set,
    const std::string& prefix)
{
    if (NULL == redis_handler) {
        WRITE_LOG(UL_LOG_FATAL, "seek_user_ad get NULL redis_handler.");
        return -1;
    }

    string key = prefix + "____" + int_to_string<int>(id.first) + "____" + id.second;

    string value;
    redis_handler->get_redis_key(key, value);
    WRITE_LOG(UL_LOG_DEBUG, "size:%lu, key=%s, value=%s", value.size(), key.c_str(),
        value.c_str());
    if(value.size() == 0 || value == "NULL") {
        return 0;
    }
    vector<string> out_array;
    split(value, ";", out_array);

    for(uint32_t i = 0; i < out_array.size(); i ++) {
        vector<string> one_ad;
        uint64_t unit_id;
        uint64_t bid;
        
        try {
            split(out_array[i], ":", one_ad);
            
            unit_id = string_to_int<uint64_t>(one_ad[0]);
            bid = string_to_int<uint64_t>(one_ad[1]);

            WRITE_LOG(UL_LOG_DEBUG, "test sstream. [%s][%s][%lu][%lu]", one_ad[0].c_str(),
                one_ad[1].c_str(), unit_id, bid);
            
        } catch(...) {
            WRITE_LOG(UL_LOG_WARNING, "bid format of user_target line. [%s]", value.c_str());
            return -1;
        }

        hash_map<uint64_t, uint64_t>::iterator it;
        it = ad_set.find(unit_id);
        if (it == ad_set.end()) {
            ad_set.insert(std::make_pair(unit_id, bid));
        } else if (ad_set[unit_id] < bid) {
            ad_set[unit_id] = bid;
        }
    }
    return 0;
}


int RtbTarget::user_target()
{
    ut_res.clear();
    int ret = 0;
    hash_map<uint64_t, uint64_t> unit_set;
    for (uint32_t i = 0; i < id_list.size(); i ++) {
        ret = seek_user_ad(_redis_handler, id_list[i], unit_set, "UT");
        if (ret < 0) {
            WRITE_LOG(UL_LOG_WARNING, "seek_user_ad failed. <%d, %s>", id_list[i].first,
id_list[i].second.c_str());
            continue;
        }
    }
    hash_map<uint64_t, uint64_t>::iterator iter;
    for(iter = unit_set.begin(); iter != unit_set.end(); ++iter) {
        target_res_t res;
        res.unitid = iter->first;
        res.score = 1.0;
        res.bid = iter->second;
        res.target_src = TARGET_SRC_UT;
        ut_res.push_back(res);
    }
    return 0;
}

int RtbTarget::retarget()
{
    rt_res.clear();
    int ret = 0;
    hash_map<uint64_t, uint64_t> unit_set;
    for (uint32_t i = 0; i < id_list.size(); i ++) {
        ret = seek_user_ad(_redis_handler, id_list[i], unit_set, "RT");
        if (ret < 0) {
            WRITE_LOG(UL_LOG_WARNING, "seek_user_ad failed. <%d, %s>", id_list[i].first,
id_list[i].second.c_str());
            continue;
        }
    }
    hash_map<uint64_t, uint64_t>::iterator iter;
    for(iter = unit_set.begin(); iter != unit_set.end(); ++iter) {
        target_res_t res;
        res.unitid = iter->first;
        res.bid = iter->second;
        res.score = 1.0;
        res.target_src = TARGET_SRC_UT;
        rt_res.push_back(res);
    }
    return 0;
}

int RtbTarget::context_target()
{
    ct_res.clear();
    int ret = 0;
    business_res_t* busi_res = NULL;
    ret = text_to_business(page_context.c_str(), busi_res);
    if(ret < 0) {
        WRITE_LOG(UL_LOG_WARNING, "text_to_business failed. text=%s", page_context.c_str());
        return -1;
    }
    if(NULL == busi_res) {
        WRITE_LOG(UL_LOG_WARNING, "text_to_business matched no business. text=%s", page_context.c_str());
        return 0;
    }

    ret = business_to_ad(*busi_res, ct_res);
    if(ret < 0) {
        WRITE_LOG(UL_LOG_WARNING, "business_to_ad failed. text=%s", page_context.c_str());
        return -1;
    }

    

    return 0;
}

int RtbTarget::merge_target_res() {
    target_res.clear();
    hash_set<uint64_t> unit_set;
    hash_set<uint64_t>::iterator iter;

    
    string all_rec;

    string rt_rec;
    for(uint32_t i = 0; i < rt_res.size(); i ++) {
        
        rt_rec += int_to_string<uint64_t>(rt_res[i].unitid) + ":" +
            int_to_string<uint64_t>(rt_res[i].bid) + ",";
        iter = unit_set.find(rt_res[i].unitid);
        if (iter == unit_set.end()) {
            all_rec += int_to_string<uint64_t>(rt_res[i].unitid) + ":" +
                int_to_string<uint64_t>(rt_res[i].bid) + ",";
            target_res.push_back(rt_res[i]);
            unit_set.insert(rt_res[i].unitid);
        }
    }


    string ct_rec;
    for(uint32_t i = 0; i < ct_res.size(); i ++) {
        ct_rec += int_to_string<uint64_t>(ct_res[i].unitid) + ":" +
            int_to_string<uint64_t>(ct_res[i].bid) + ",";
        iter = unit_set.find(ct_res[i].unitid);
        if (iter == unit_set.end()) {
            all_rec += int_to_string<uint64_t>(ct_res[i].unitid) + ":" +
                int_to_string<uint64_t>(ct_res[i].bid) + ",";
            target_res.push_back(ct_res[i]);
            unit_set.insert(ct_res[i].unitid);
        }
    }

    string ut_rec;
    for(uint32_t i = 0; i < ut_res.size(); i ++) {
        ut_rec += int_to_string<uint64_t>(ut_res[i].unitid) + ":" +
            int_to_string<uint64_t>(ut_res[i].bid) + ",";
        iter = unit_set.find(ut_res[i].unitid);
        if (iter == unit_set.end()) {
            all_rec += int_to_string<uint64_t>(ut_res[i].unitid) + ":" +
                int_to_string<uint64_t>(ut_res[i].bid) + ",";
            target_res.push_back(ut_res[i]);
            unit_set.insert(ut_res[i].unitid);
        }
    }
    WRITE_LOG(UL_LOG_WARNING, "retarget size[%lu]: %s", rt_res.size(), rt_rec.c_str());
    WRITE_LOG(UL_LOG_WARNING, "context_target size[%lu]: %s", ct_res.size(), ct_rec.c_str());
    WRITE_LOG(UL_LOG_WARNING, "user_target size[%lu]: %s", ut_res.size(), ut_rec.c_str());
    WRITE_LOG(UL_LOG_WARNING, "all_target size[%lu]: %s", unit_set.size(), all_rec.c_str());

    return 0;
}


int RtbTarget::pre_process()
{
    int ret = 0;
    td->page_keywords.clear();
    for(int32_t i = 0; i < td->bid_request->page_keyword_size(); i++) {
        if (td->bid_request->page_keyword(i).length() >= MAX_KEYWORD_LEN) {
            WRITE_LOG(UL_LOG_WARNING, "keywords[%s] too long.", td->bid_request->page_keyword(i).c_str());
            continue;
        }
        char buf[MAX_KEYWORD_LEN];
        ret = fc_query_filter(td->bid_request->page_keyword(i).c_str(), buf);
        if (ret < 0 || strlen(buf) == 0) {
            WRITE_LOG(UL_LOG_WARNING, "keywords[%s] fc_query_filter failed.", 
                    td->bid_request->page_keyword(i).c_str());
            continue;
        }

        td->page_keywords.push_back(string(buf));

        page_context.append(" ");
        page_context.append(buf);
    }

    // feed all types of id
    id_list.clear();
    for(int i = 0; i < td->bid_request->baidu_id_list_size(); i ++) {
        if (td->bid_request->baidu_id_list(i).has_baidu_user_id()) {
            const string& bes_id = td->bid_request->baidu_id_list(i).baidu_user_id();
            id_list.push_back(std::make_pair(TYPE_REQUEST_ID_BES, bes_id));
        }
    }

    if(td -> bid_request -> has_mobile() && td -> bid_request -> has_url()) {
        const AdxRtb::BidRequest::Mobile& mobile = td->bid_request->mobile();
        for (int i = 0; i < mobile.id_size(); i++) {
            const AdxRtb::BidRequest::Mobile::MobileID& mobile_id = mobile.id(i);
            if (mobile_id.type() == 1) {
                id_list.push_back(make_pair(TYPE_REQUEST_ID_IMEI, mobile_id.id()));
            }
        }
    }

    id_list.push_back(make_pair(TYPE_REQUEST_ID_IP, td->bid_request->ip()));

    int adslot_size = td->bid_request->adslot_size();
    // doc said only one slot with be requested, so only the first with be considered
    if(adslot_size != 1) {
        WRITE_LOG(UL_LOG_WARNING, "invalid adslot size [%d]. ", adslot_size);
    }
    
    const AdxRtb::BidRequest::AdSlot& adslot = td->bid_request->adslot(0);

    excluded_url.clear();
    for(int j = 0; j < adslot.excluded_landing_page_url_size(); j++) {
        excluded_url.insert(adslot.excluded_landing_page_url(j));
    }

    return 0;
}


int RtbTarget::business_to_ad(const business_res_t& business, vector<target_res_t>& unit_list) 
{
    ad::rtb::business_ad busi_ad;
//    WRITE_LOG(UL_LOG_WARNING, "business_to_ad before seek %s ,size=%d",
//            business.business.c_str(), busi_ad.unitid_size());

    if (xbuiltin::RESULT_FOUND ==
            RtbDict::instance().business_ad_dict.seek(business.business.c_str(), &busi_ad)) {
//        WRITE_LOG(UL_LOG_WARNING, "business_to_ad found %s ,size=%d",
//                business.business.c_str(), busi_ad.unitid_size());
        if(busi_ad.unitid_size() != busi_ad.bid_size()) {
            WRITE_LOG(UL_LOG_WARNING, "unitid size[%d] != bid size[%d]", busi_ad.unitid_size(),
                busi_ad.bid_size());

            return -1;
        }
        for(int32_t i = 0; i < busi_ad.unitid_size(); i++) {
            target_res_t res;
            res.unitid = busi_ad.unitid(i);
            res.bid = busi_ad.bid(i);
            res.score = business.score;
            res.target_src = TARGET_SRC_CT;
            unit_list.push_back(res);
        }
    }
    return 0;
}

int RtbTarget::search_phrase(const string& phrase, hash_map<string, business_res_t>& result)
{
    ad::rtb::phrase_business busi;
    //WRITE_LOG(UL_LOG_WARNING, "search_phrase %s.", phrase.c_str());
    if (xbuiltin::RESULT_FOUND ==
            RtbDict::instance().phrase_business_dict.seek(phrase.c_str(), &busi)) {
        //WRITE_LOG(UL_LOG_WARNING, "search_phrase found %s.", phrase.c_str());
        hash_map<string, business_res_t>::iterator iter;
        iter = result.find(busi.business());
        if(iter == result.end()) {
            business_res_t new_res;
            string busi_name = busi.business();
            new_res.business = busi.business();
            new_res.score = busi.weight();
            new_res.support_phrase.push_back(phrase);
            result.insert(make_pair(busi_name, new_res));
            WRITE_LOG(UL_LOG_TRACE, "phrase [%s] matched business [%s].", 
                phrase.c_str(), new_res.business.c_str());
        } else {
            bool found_same_phrase = false;
            for(uint32_t i = 0; i < iter->second.support_phrase.size(); i ++) {
                if (phrase == iter->second.support_phrase[i]) {
                    found_same_phrase = true;
                    break;
                }
            }
            if(!found_same_phrase) {
                iter->second.score += busi.weight();
                iter->second.support_phrase.push_back(phrase);
            }
        }
    }
    return 0;

}

int RtbTarget::text_to_business(const char* text, business_res_t*& busi_res)
{
    busi_res = NULL;
    if(NULL == text) {
        WRITE_LOG(UL_LOG_FATAL, "param is NULL.");
        return -1;
    }
    int ret = 0;
    ret = scw_segment_words(pd->seg_dict, td->seg_out, text, strlen(text),
            LANGTYPE_SIMP_CHINESE, NULL);
    if(ret < 0) {
        WRITE_LOG(UL_LOG_WARNING, "seg text failed. text=[%s]", text);
        return -1;
    }
    td->seg_res.term_num = scw_get_token_1(
            td->seg_out, 
            SCW_OUT_WPCOMP|SCW_OUT_PROP, 
            td->seg_res.terms, 
            MAX_DESC_TERM_NUM);

    if(td->seg_res.term_num <= 0) {
        WRITE_LOG(UL_LOG_WARNING, "scw_get_token_1 page keywords failed. text=[%s]", text);
        return -1;
    }


    for (uint32_t i = 0; i < td->seg_res.term_num; i ++) {
        string phrase;
        for (uint32_t j = i+1; j <= td->seg_res.term_num; j++) {
            if( j - i > MAX_BUSINESS_PHRASE_TERMS) {
                break;
            }

            char* buff = td->seg_res.terms[j-1].buffer;
            //WRITE_LOG(UL_LOG_WARNING, "buf is %s.", buff);
            if (xbuiltin::RESULT_FOUND !=
                    RtbDict::instance().stop_word_dict.seek(buff) ){
                //WRITE_LOG(UL_LOG_WARNING, "not found stop word %s.", buff);
                phrase.append(buff);
            } else {
                continue;
            }

            ret = search_phrase(phrase, ct_res_dict);
            if (ret < 0) {
                WRITE_LOG(UL_LOG_WARNING, "search phrase failed. str=[%s]", phrase.c_str());
                continue;
            }
        }
    }

    hash_map<string, business_res_t>::iterator iter;
    float max_score = -100.0;
    for(iter = ct_res_dict.begin(); iter != ct_res_dict.end(); iter++) {
        if(iter->second.score > max_score) {
            busi_res = &(iter->second);
            max_score = iter->second.score;
        }
    }
    return 0;
}

} // namespace ranker
} // namespace im

/* vim: set ts=4 sw=4 sts=4 tw=100 et: */
