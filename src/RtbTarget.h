#ifndef AD_RTB_RTB_TARGET_H
#define AD_RTB_RTB_TARGET_H

//#include <ext/hash_map>
#include <hash_set>
#include <base/containers/hash_tables.h>
#include "RtbData.h"
#include "RtbDict.h"
#include "redis_op.h"

namespace ad {
namespace rtb {
using std::vector;
using std::pair;
using std::string;
//using __gnu_cxx::hash_map;
using base::hash_map;
using __gnu_cxx::hash_set;

class RtbTarget {
public:
    RtbTarget():pd(NULL),td(NULL){}
    int init(ProcessData* process_data, ThreadData* thread_data, std::string config_path);
    void destroy();
    int clear();
    int pre_process();
    int target();

    vector<target_res_t> ct_res;
    vector<target_res_t> ut_res;
    vector<target_res_t> rt_res;

    vector<target_res_t> target_res;

private:
    std::string _config_path;

    RedisOp* _redis_handler;

    int context_target();

    int user_target();

    int retarget();

    int merge_target_res();

    void fill_ad_info();

    void ad_filter_region();

    void ad_filter_blacklist();

    void ad_filter_flow_type();

    void ad_filter_slot();

    void ad_filter_timewindow();

    int ad_filter();

    int business_to_ad(const business_res_t& business, vector<target_res_t>& unit_list);

    int search_phrase(const string& phrase, hash_map<string, business_res_t>& result);

    int text_to_business(const char* text, business_res_t*& busi_res);

    int seek_user_ad(RedisOp* redis_handler, 
        pair<TYPE_REQUEST_ID, string>& id, 
        hash_map<uint64_t, uint64_t>& unit_list, 
        const std::string& prefix);

    int select_idea_one_ad(const vector<uint64_t>& idea_list, 
        ad::rtb::idea_info& selected);

    int select_idea();

    // select one ad and calc bid
    int bidding();


    ProcessData* pd;
    ThreadData* td;
    
    string page_context;
    hash_map<string, business_res_t> ct_res_dict;
    base::hash_map<uint64_t, ad::rtb::adv_t> adv_list;

    vector<pair<TYPE_REQUEST_ID, string> > id_list;
    hash_set<string> excluded_url;
    
};

} // namespace rtb
} // namespace ad

#endif
/* vim: set ts=4 sw=4 sts=4 tw=100 et: */
