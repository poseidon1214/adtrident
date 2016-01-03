/* Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * File: rtb_strategy.h
 * Auth: shenguolong@baidu.com
**/

#include <base/logging.h>
#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include "proto/baidu_realtime_bidding.pb.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <string>
#include <mutex>
#include "redis_op.h"
#include "common.h"
#include "mkl/mkl.h"
#include "mkl/mkl_vml_functions.h"
#include "json.hpp"
#include "yaml-cpp/yaml.h"
#include "mysql/mysql.h"
#include "rtb_data.h"

#ifndef AD_RTB_RTB_STRATEGY_H
#define AD_RTB_RTB_STRATEGY_H

namespace ad {
namespace rtb {

class RtbStrategy {
public:
    RtbStrategy();
    //void loadConf(const std::string& config_path);
    void _addcount();
    void bidding(AdxRtb::BidRequest* request, AdxRtb::BidResponse* response, RtbData* _rtb_data);
private:
    int32_t _count = 1;

    YAML::Node _config;
    std::string _config_path;

    int32_t _is_bid = 1;
    std::string _ip;
    std::string _bes_id;
    std::string _imei;
    std::string _mac;
    std::string _flow_type;
    int32_t _sequence_id;
    int32_t _slot_visibility;
    int32_t _creative_id = 0;
    int32_t _max_cpm = 1;

private:
    void _fillIds(AdxRtb::BidRequest* request);
    void _fillFlowType(AdxRtb::BidRequest* request);
};

} // namespace rtb
} // ad 

#endif
