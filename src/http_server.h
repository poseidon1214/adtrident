/* Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * File: http_server.cpp
 * Auth: shenguolong@baidu.com
**/

#include <gflags/gflags.h>
#include <baas-lib-c/baas.h>
#include <baas-lib-c/giano_mock_helper.h>
#include <base/logging.h>
#include <baidu/rpc/server.h>
#include <baidu/rpc/policy/giano_authenticator.h>
#include <vector>
#include "http_server.pb.h"
#include "yaml-cpp/yaml.h"
#include "json.hpp"

//#include "rtb_data.h"
#include "RtbData.h"
#include "RtbDict.h"
#include "RtbTarget.h"

#ifndef AD_RTB_HTTP_SERVICE_H
#define AD_RTB_HTTP_SERVICE_H 

namespace ad {
namespace rtb {

class HttpServiceImpl : public AdxRtb::HttpService {
public:
    HttpServiceImpl() {};
    virtual ~HttpServiceImpl() {};
    virtual void Rtb(google::protobuf::RpcController* cntl_base,
                      const AdxRtb::HttpRequest* request,
                      AdxRtb::HttpResponse* response,
                      google::protobuf::Closure* done);
    void init(const std::string& config_path);

private:
    ProcessData process_data;
    ProcessData* pd;

    //RtbData _rtb_data;
    YAML::Node _config;
    std::string _config_path;
};

} // namespace rtb 
} // ad

#endif
