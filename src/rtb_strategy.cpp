/* Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * File: rtb_strategy.cpp
 * Auth: shenguolong@baidu.com
**/

#include "rtb_strategy.h"

namespace ad {
namespace rtb {

using AdxRtb::BidRequest;
using AdxRtb::BidResponse;

//std::string _black_list;

RtbStrategy::RtbStrategy() {
}

//void RtbStrategy::loadConf(const std::string& config_path) {
//    _config_path = config_path; 
//    _rtb_data.userBlackList(_config_path, _black_list);
//}

void RtbStrategy::_fillIds(BidRequest* request) {
    if(request -> has_ip()) {
        _ip = request -> ip();
    }

    for (int j = 0; j < request->baidu_id_list_size(); j++) {
        const AdxRtb::BidRequest::BaiduId& baidu_id = request -> baidu_id_list(j);
        if(baidu_id.baidu_user_id_version() == 2) {
            _bes_id = baidu_id.baidu_user_id();
            break;
        }
    }

    if(request -> has_mobile()) {
        const AdxRtb::BidRequest::Mobile& mobile = request -> mobile();
        for (int j = 0; j < mobile.id_size(); j++) {
            const AdxRtb::BidRequest::Mobile::MobileID& mobile_id = mobile.id(j);
            switch(mobile_id.type()) {
                case 0:
                    break;
                case 1:
                    _imei = mobile_id.id();
                    break;
                case 2:
                    _mac = mobile_id.id();
                    break;
            }
        }
    } 
}


void RtbStrategy::_fillFlowType(BidRequest* request) {
    _flow_type = "pc";

    //AdxRtb::BidRequest::AdSlot adslot;
    //for (int j = 0; j < request -> adslot_size(); j++) {
    //    adslot = request -> adslot(j);
    //    if(adslot.has_sequence_id()) {
    //        _sequence_id = adslot.sequence_id();
    //    }
    //}
    const AdxRtb::BidRequest::AdSlot& adslot = request->adslot(0);
    _sequence_id = adslot.sequence_id();
    _slot_visibility = adslot.slot_visibility();

    if(request -> has_mobile()) {
        _flow_type = "mobile";
    }
    if(request -> has_mobile() & request -> has_url()) {
        _flow_type = "wap";
    }
    if(request -> has_video()) {
        _flow_type = "video";
    }
    if(adslot.has_link_unit_info() & (adslot.creative_type(0) == 5)) {
        _flow_type = "lu";
    }    
}


void RtbStrategy::_addcount() {
    _count++;
    std::cout << _count << std::endl;
}


void RtbStrategy::bidding(BidRequest* request, BidResponse* response, RtbData* _rtb_data) {
    std::cout << _rtb_data->black_list[0] <<std::endl;
    
    //pre-process
    //_addcount();
    _fillIds(request);
    _fillFlowType(request);

    //1.user black list 


    //2.flow type: mobile,pc,video,LU


    //3.ad location: first sight
    if(_slot_visibility != 1) {
        _is_bid = 0;
    }

    //fill the response
    //required, the same as the request id
    response->set_id(request->id());
    //optional
    std::string debug_string = "ip:" + _ip + ";bes_id:" + _bes_id + ";mac:" + _mac + ";imei:" + _imei
        + ";flow_type:"+_flow_type+";";
    response->set_debug_string(debug_string);
    //optional
    response->set_processing_time_ms(35);

    if (_is_bid) { 
        AdxRtb::BidResponse::Ad* ad = response->add_ad();
        //required
        ad->set_sequence_id(_sequence_id);
        //required
        ad->set_creative_id(_creative_id);
        //required
        ad->set_max_cpm(_max_cpm);
    }
}


} // namespace rtb
} // ad 
