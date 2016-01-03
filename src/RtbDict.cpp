#include "RtbDict.h"

#define REG_DICT(dictname, dict) \
do { \
    if (xbuiltin::Manager::instance().register_dict(dictname, (dict)) < 0) { \
        WRITE_LOG(UL_LOG_FATAL, "register dict[%s] failed.", dictname); \
        return -1; \
    } \
} while (0)

#define REG_PLUGIN(dict, plugin) \
do { \
    if ((dict)->register_plugin((plugin)) < 0) { \
        WRITE_LOG(UL_LOG_FATAL, "register plugin failed."); \
        return -1; \
    } \
} while (0)

namespace ad {
namespace rtb {

int RtbDict::register_plugin()
{
    return 0;
}

int RtbDict::register_dict()
{
    if (register_plugin() < 0) {
        return -1;
    }

    try {
        REG_DICT("phrase_business", &phrase_business_dict);
        REG_DICT("business_ad", &business_ad_dict);
        REG_DICT("stop_word", &stop_word_dict);
        REG_DICT("user_info", &user_info_dict);
        REG_DICT("plan_info", &plan_info_dict);
        REG_DICT("unit_info", &unit_info_dict);
        REG_DICT("idea_info", &idea_info_dict);
        REG_DICT("unit_idea", &unit_idea_dict);
        //REG_DICT("black_list_info", &black_list_info_dict);
    } catch (bsl::Exception& e) {
        WRITE_LOG(UL_LOG_FATAL, "failed to register dict. [%s]", e.what());
        return -1; 
    } catch (...) {
        WRITE_LOG(UL_LOG_FATAL, "Expection: failed to register dict.");
        return -1; 
    }   

    return 0;
}

}
}

/* vim: set ts=4 sw=4 sts=4 tw=100 et: */
