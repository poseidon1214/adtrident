#ifndef AD_RTB_UTIL_H
#define AD_RTB_UTIL_H

#include <string>
#include <vector>
#include <sstream>

namespace ad {
namespace rtb {
    const static uint32_t MAX_DESC_LEN = 128;
    const static uint32_t MAX_DESC_TERM_NUM = 64;

    const static uint32_t MAX_KEYWORD_LEN = 64;
    const static uint32_t MAX_KEYWORD_TERM_NUM = 32;

    const static uint32_t MAX_BUSINESS_PHRASE_TERMS = 6;
    const static uint32_t MAX_PATH_LEN = 256;

    const static uint32_t MAX_ADLIST_LEN = 256;

    const static uint32_t DAY_OF_WEEK = 7;

    enum {
    TARGET_SRC_CT = 1,
    TARGET_SRC_UT = 2,
    TARGET_SRC_RT = 3
    };

    enum TYPE_REQUEST_ID {
    TYPE_REQUEST_ID_JDT = 1,
    TYPE_REQUEST_ID_BES = 2,
    TYPE_REQUEST_ID_IMEI = 3,
    TYPE_REQUEST_ID_IP = 4
    };

    // 字符串切分函数
    void split(const std::string& input, 
        const std::string& delim, 
        std::vector< std::string >& out_array);
    
    template<typename int_type>
    int_type string_to_int(const std::string text)
    {
        int_type ret;
        std::stringstream ss;
        ss << text;
        ss >> ret;
        return ret;
    }

    template<typename int_type>
    std::string int_to_string(int_type num)
    {
        std::string ret;
        std::stringstream ss;
        ss << num;
        ss >> ret;
        return ret;
    }
} // end of namespace ad
} // end of namespace rtb

#endif
