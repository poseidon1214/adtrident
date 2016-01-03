/* Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * File: http_server.cpp
 * Auth: shenguolong@baidu.com
**/

#include "common.h"
#include <sstream>

namespace ad {
namespace rtb {

long get_current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);    
    return tv.tv_sec * 1000000 + tv.tv_usec; 
}

std::string int2str(const int &source) {
    std::stringstream stream;
    stream << source;
    return stream.str();
}

std::string long2str(const long &source) {
    std::stringstream stream;
    stream << source;
    return stream.str();
}

int32_t str2int(const std::string &string_temp) {  
    int32_t int_temp;
    std::stringstream stream(string_temp);  
    stream>>int_temp;
    return int_temp;  
} 

int32_t hourofday() {
    struct tm *timeval;
    time_t tt;
    tt = time( NULL );
    timeval = localtime( &tt );
    return timeval->tm_hour;
}

int32_t dayofweek() {
    struct tm *timeval;
    time_t tt;
    tt = time( NULL );
    timeval = localtime( &tt );
    return timeval->tm_wday;
}

void word_split(std::vector<std::string>& dest, const std::string& src, const std::string& separator)
{
    std::string str = src;
    std::string substring;
    std::string::size_type start = 0, index;

    do
    {
        index = str.find_first_of(separator,start);
        if (index != std::string::npos)
        {    
            substring = str.substr(start,index-start);
            dest.push_back(substring);
            start = str.find_first_not_of(separator,index);
            if (start == std::string::npos) return;
        }
    }while(index != std::string::npos);
    
    //the last token
    substring = str.substr(start);
    dest.push_back(substring);
}

} // namespace rtb
} // ad 
