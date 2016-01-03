#include "RtbData.h"
#include "config_setter.h"
#include "config_setter_helper.h"

namespace ad {
namespace rtb {


int ProcessData::initialize(const char* config_path) 
{
    framework::config_file_t* cf = framework::config_setter_t::instance()->get_config_file(config_path);

    if (cf == NULL) { 
        WRITE_LOG(UL_LOG_FATAL, "failed to create config handle for '%s'!", config_path);
        return -1;
    }

    REGCFG_FIX_STRING(cf, "WORD_SEG_CONF_PATH", _conf_wordseg_conf_path, "./data/worddict/scw.conf");
    REGCFG_FIX_STRING(cf, "WORD_SEG_DICT_PATH", _conf_wordseg_dict_path, "./data/worddict/");

    pgconf = scw_load_conf(_conf_wordseg_conf_path); 
    if(NULL == pgconf) {
        WRITE_LOG(UL_LOG_FATAL, "scw_load_conf(%s) return NULL.", _conf_wordseg_conf_path);
        return -1;
    }
    seg_dict = scw_load_worddict(_conf_wordseg_dict_path);
    if (NULL == seg_dict) {
        WRITE_LOG(UL_LOG_FATAL, "scw_load_worddict(%s) return NULL.", _conf_wordseg_dict_path);
        return -1;
    }

//    REGCFG_FIX_STRING(cf, "UT_REDIS_CONF_PATH", _conf_wordseg_conf_path, "./conf/user_target_redis.conf");
//    REGCFG_FIX_STRING(cf, "RT_REDIS_CONF_PATH", _conf_wordseg_dict_path, "./conf/retarget_redis.conf");
//
//    ut_db_handler = new RedisOp(_conf_ut_redis_path);
//    ut_db_handler -> connect_db();
//
//    rt_db_handler = new RedisOp(_conf_rt_redis_path);
//    rt_db_handler -> connect_db();


    //init the adv_list

    return 0;
}

int ThreadData::initialize()
{
    int ret = 0;
    ret = clear();
    if(ret != 0) {
        WRITE_LOG(UL_LOG_FATAL, "clear failed.");
        return -1;
    }

    u_int scw_out_flag;
    scw_out_flag = SCW_OUT_ALL | SCW_OUT_PROP;
    seg_out = scw_create_out(MAX_KEYWORD_TERM_NUM, scw_out_flag);
    if (NULL == seg_out ) {
        WRITE_LOG(UL_LOG_FATAL, "scw_create_out return NULL.");
        return -1;
    }
    return 0;
}

void ThreadData::destroy()
{
    scw_destroy_out(seg_out);
}

int ThreadData::clear()
{
    page_keywords.clear();
    return 0;
}

} // namespace rtb
} // ad 
