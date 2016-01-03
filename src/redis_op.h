/* Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * File: redis.cpp
 * Auth: shenguolong@baidu.com
**/

#include <sys/time.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "yaml-cpp/yaml.h"
#include "hiredis/hiredis.h"

#ifndef AD_RTB_REDIS_H
#define AD_RTB_REDIS_H

namespace ad {
namespace rtb {

class RedisOp {
public:
    RedisOp(const std::string& config_path);
    ~RedisOp(){}
    void connect_db();
    void disconnect_db();
    void set_redis_key(const std::string& key, const std::string& value);
    void get_redis_key(const std::string& key, std::string& value);
    
private:
    YAML::Node _config;
    std::string _host;
    int32_t _port;
    redisContext *conn;
};

}//namespace rtb
}//namespace ad

#endif
