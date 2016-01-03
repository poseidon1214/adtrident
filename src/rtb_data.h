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

#ifndef AD_RTB_RTB_DATA_H
#define AD_RTB_RTB_DATA_H

namespace ad {
namespace rtb {

class RtbData {
public:
    RtbData();
    
    std::vector<std::string> black_list;
    void loadConf(const std::string& config_path); 
private:
    std::string _config_path;
    MYSQL _conn; 
    void _connectDB();
    void _closeDB();
    void _userBlackList();
};

} // namespace rtb
} // ad 

#endif
