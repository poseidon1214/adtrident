/* Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * File: rtb_strategy.cpp
 * Auth: shenguolong@baidu.com
**/

#include "rtb_data.h"

namespace ad {
namespace rtb {

RtbData::RtbData() {
}

void RtbData::loadConf(const std::string& config_path) {
    _config_path = config_path;
    _connectDB();
    _userBlackList();
    _closeDB();
}

void RtbData::_connectDB() {
    YAML::Node _config = YAML::LoadFile(_config_path);
    mysql_init(&_conn);
    mysql_real_connect(&_conn, _config["mysql_db"]["mysql_host"].as<std::string>().c_str(),
            _config["mysql_db"]["mysql_user"].as<std::string>().c_str(),
            _config["mysql_db"]["mysql_pwd"].as<std::string>().c_str(),
            _config["mysql_db"]["mysql_database"].as<std::string>().c_str(),
            _config["mysql_db"]["mysql_port"].as<int32_t>(), NULL, 0);
}

void RtbData::_closeDB() {
    mysql_close(&_conn);  
}

void RtbData::_userBlackList() {
    std::string sql = "select ipblack from user";
    std::cout << sql <<std::endl;
    mysql_query(&_conn, sql.c_str());
    MYSQL_RES *result = mysql_store_result(&_conn); 
    MYSQL_ROW row;
    
    while((row = mysql_fetch_row(result))) {
        //for(int32_t j=0; j < (int)mysql_num_fields(result); ++j) {  
            //std::cout << row[j] << " ";
        //}
        black_list.push_back(row[0]); 
    }
    long begin_time = get_current_time();
    black_list.push_back(long2str(begin_time));
    
    mysql_free_result(result);     
}

} // namespace rtb
} // ad 
