#ifndef AD_RTB_RTB_DATA_H
#define AD_RTB_RTB_DATA_H

#include <vector>
#include <string>
#include "scwdef.h"
#include "isegment.h"

#include "RtbUtil.h"
#include "baidu_realtime_bidding.pb.h"

#include "user_info.pb.h"
#include "plan_info.pb.h"
#include "unit_info.pb.h"
#include "idea_info.pb.h"
#include "redis_op.h"

namespace ad {
namespace rtb {

struct adv_t {
    uint64_t unitid;
    uint64_t base_bid;
    ad::rtb::unit_info unit_info;
    ad::rtb::user_info user_info;
    ad::rtb::plan_info plan_info;
    ad::rtb::idea_info idea_info;
};


class ProcessData{
public:
    ProcessData(){}
    int initialize(const char* config_path);
    int clear();
    int finalize();

    scw_worddict_t* seg_dict;
//    RedisOp* ut_db_handler;
//    RedisOp* rt_db_handler;
    

    char _conf_wordseg_conf_path[MAX_PATH_LEN];
    char _conf_wordseg_dict_path[MAX_PATH_LEN];

//    char _conf_ut_redis_path[MAX_PATH_LEN];
//    char _conf_rt_redis_path[MAX_PATH_LEN];
};

struct seg_res_t {
    token_t terms[MAX_DESC_TERM_NUM];
    uint32_t term_num;
};

struct business_res_t {
    std::string business;
    float score;
    uint8_t src;
    std::vector<std::string> support_phrase;
};

struct target_res_t {
    uint64_t unitid;
    uint64_t bid;
    float score;
    uint8_t target_src;
};

class ThreadData {
public:
    const static uint32_t MAX_KEYWORDS_LEN = 256;

    ThreadData():bid_request(NULL), bid_response(NULL){}
    int initialize();
    void destroy();
    int clear();
    int finalize();

public:
//    BidRequest* bid_request;

    scw_out_t* seg_out;
    seg_res_t seg_res;

    std::vector<std::string> page_keywords;
    AdxRtb::BidRequest* bid_request;
    AdxRtb::BidResponse* bid_response;
    //std::vector<std::pair<REQUEST_ID_TYPE, std::string> > id_list;
};

} // namespace rtb
} // ad 

#endif
