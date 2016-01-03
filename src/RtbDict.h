#ifndef RTB_DICT_H
#define RTB_DICT_H

#include <Manager.h>
#include <TSVDict.h>

#include "phrase_business.pb.h"
#include "business_ad.pb.h"
#include "stop_word.pb.h"
#include "user_info.pb.h"
#include "plan_info.pb.h"
#include "unit_info.pb.h"
#include "idea_info.pb.h"
#include "unit_idea.pb.h"

namespace ad {
namespace rtb {

class RtbDict
{
public:
    xbuiltin::TSVDict<ad::rtb::phrase_business> phrase_business_dict;
    xbuiltin::TSVDict<ad::rtb::business_ad> business_ad_dict;
    xbuiltin::TSVDict<ad::rtb::stop_word> stop_word_dict;
    xbuiltin::TSVDict<ad::rtb::user_info> user_info_dict;
    xbuiltin::TSVDict<ad::rtb::plan_info> plan_info_dict;
    xbuiltin::TSVDict<ad::rtb::unit_info> unit_info_dict;
    xbuiltin::TSVDict<ad::rtb::idea_info> idea_info_dict;
    xbuiltin::TSVDict<ad::rtb::unit_idea> unit_idea_dict;
    //xbuiltin::TSVDict<ad::rtb::black_list_info> black_list_info_dict;

public:
    static RtbDict& instance() {
        static RtbDict d;
        return d;
    }

    int register_plugin();
    int register_dict();

private:
};
}
}

#endif // RTB_DICT_H

/* vim: set ts=4 sw=4 sts=4 tw=100 et: */
