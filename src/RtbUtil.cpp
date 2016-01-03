#include "RtbUtil.h"
#include <string>
#include <vector>
#include <sstream>
namespace ad {
namespace rtb {

void split(const std::string& s, const std::string& delim,std::vector<std::string>& out_array)  
{  
    size_t last = 0;  
    size_t index=s.find_first_of(delim,last);  
    while (index!=std::string::npos)  
    {  
        out_array.push_back(s.substr(last,index-last));  
        last=index+1;  
        index=s.find_first_of(delim,last);  
    }  
    if (index-last>0)  
    {  
        out_array.push_back(s.substr(last,index-last));  
    }  
} 


} // end of namespace rtb
} // end of namespace ad
