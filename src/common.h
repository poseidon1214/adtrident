/* Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * File: http_server.cpp
 * Auth: shenguolong@baidu.com
**/

#include <sys/time.h> 
#include <iostream>
#include <vector>

#ifndef BAIDU_BML_CTR_PREDICT_COMMON_H
#define BAIDU_BML_CTR_PREDICT_COMMON_H

namespace ad {
namespace rtb {

long get_current_time();
std::string int2str(const int &source);
std::string long2str(const long &source);
int32_t str2int(const std::string &string_temp);  
int32_t dayofweek();
int32_t hourofday();
void word_split(std::vector<std::string>& dest, const std::string& src, const std::string& separator);

} // namespace rtb
} // ad 

#endif
