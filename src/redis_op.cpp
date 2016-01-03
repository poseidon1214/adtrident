/* Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * File: redis.cpp
 * Auth: shenguolong@baidu.com
**/

#include "redis_op.h"

namespace ad {
namespace rtb {

RedisOp::RedisOp(const std::string& config_path) {
    _config = YAML::LoadFile(config_path);
    _host = _config["redis_db"]["redis_host"].as<std::string>();
    _port = _config["redis_db"]["redis_port"].as<int32_t>();
}

void RedisOp::connect_db() {
    conn  = redisConnect(_host.c_str(), _port);
    if(conn != NULL && conn->err) {
        printf("connection error: %s\n",conn->errstr);
    }
}

void RedisOp::disconnect_db() {
    redisFree(conn);
}

void RedisOp::set_redis_key(const std::string& key, const std::string& value) {
    std::string command = "set ";
    command += key;
    command += " ";
    command += value;

    redisReply *reply = (redisReply*)redisCommand(conn,command.c_str());
    freeReplyObject(reply);
}

void RedisOp::get_redis_key(const std::string& key, std::string& value) {
    std::string command = "get ";
    command += key;

    redisReply *reply = (redisReply*)redisCommand(conn,command.c_str());
    if (reply->type != REDIS_REPLY_STRING) {
        value = "";   
    } else {
        value = reply->str;
    }
    freeReplyObject(reply);
}

}//namespace rtb
}//namespace ad
