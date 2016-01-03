#include <ext/hash_map>
#include "RtbData.h"
#include "RtbDict.h"

namespace ad {
namespace rtb {
using __gnu_cxx::hash_map;
using std::vector;
using std::pair;
using std::string;

class RtbFilter {
public:
    RtbFilter():pd(NULL),td(NULL){}

    int init(ProcessData* process_data, ThreadData* thread_data);

    int clear();

    int pre_process();

    int filter();

private:
    int budget_filter();

    int region_filter();

    int target_time_filter();

    int target_popu_filter();

    int show_frequency_control();

    ProcessData* pd;
    ThreadData* td;
};

} // namespace rtb
} // namespace ad

/* vim: set ts=4 sw=4 sts=4 tw=100 et: */
