/* Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * File: http_server.cpp
 * Auth: shenguolong@baidu.com
**/
#include "http_server.h"
#include <time.h>
#include "json.hpp"
#include "common.h"

namespace ad {
namespace rtb {
using AdxRtb::BidRequest;
using AdxRtb::BidResponse;
using AdxRtb::HttpRequest;
using AdxRtb::HttpResponse;
using nlohmann::json;

//init the process data
void HttpServiceImpl::init(const std::string& config_path) {
    _config_path = config_path;
    //_rtb_data.loadConf(_config_path);
    process_data.initialize("./conf/strategy.conf");
    pd = &process_data;

    int ret = 0;
    ret = xbuiltin::Manager::instance().initialize_manager("./conf/rtb_dict.conf");
    if (ret < 0) {
       LOG(FATAL) << "failed to init XBuiltinManager.";
    }
    ret = ad::rtb::RtbDict::instance().register_plugin();
    if (ret < 0) {
       LOG(FATAL) <<  "failed to register_plugin.";
    }
    ret = ad::rtb::RtbDict::instance().register_dict();
    if (ret < 0) {
       LOG(FATAL) <<  "failed to register_dict.";
    }

    if (xbuiltin::Manager::instance().start_init_dict() < 0) {
        LOG(WARNING) << "failed to init dict.";
    }

    if (xbuiltin::Manager::instance().wait_for_init_dict_done() < 0) {
        LOG(WARNING) << "failed to init dict.";
    }

    if (xbuiltin::Manager::instance().reload_dict() < 0) {
        LOG(WARNING) << "xbuiltin Manager reload dict failed.";
    }
}

void HttpServiceImpl::Rtb(google::protobuf::RpcController* cntl_base,
                  const HttpRequest* request,
                  HttpResponse*,//response,
                  google::protobuf::Closure* done) {
    // This object helps you to call done->Run() in RAII style. If you need
    // to process the request asynchronously, pass done_guard.release().
    baidu::rpc::ClosureGuard done_guard(done);

    baidu::rpc::Controller* cntl =
        static_cast<baidu::rpc::Controller*>(cntl_base);

    long begin_time = get_current_time();
    LOG(INFO) << "Key:" << begin_time << " Receive new request:"
            << request->DebugString() << std::endl;
    
    BidRequest bes_request;
    BidResponse bes_response;

    try {
        if (!bes_request.ParseFromString(cntl->request_attachment().to_string())) {
            LOG(WARNING) << "Fail to parse bes request";
            //return;
        } else {
            LOG(INFO) << "Key:" << begin_time << " Request pb:"<< bes_request.DebugString() << std::endl;
        }
        //init the thread data
        ThreadData thread_data;
        thread_data.initialize();
        ThreadData* td = &thread_data;
        
        td -> bid_request = &bes_request;        
        td -> bid_response = &bes_response; 
        //bidding
        RtbTarget rtb_target;
        rtb_target.init(pd, td, _config_path);
        int ret = rtb_target.target();
        rtb_target.destroy();
        thread_data.destroy();
        LOG(INFO) << "Result:" << ret << std::endl;
        //RtbStrategy _rtb_strategy;
        //_rtb_strategy.bidding(&bes_request, &bes_response, &_rtb_data);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl; 
    }
    
    std::string response_string;
    if (!bes_response.SerializeToString(&response_string)) {
        LOG(WARNING) << "Fail to serialize bes response";
        return;
    } else {
       LOG(INFO) << "Key:" << begin_time << " Response pb:"<< bes_response.DebugString() << std::endl;
    }
    std::cout << bes_response.DebugString()  << std::endl; 
    //BidResponse tt;
    //if (!tt.ParseFromString(response_string)) {
    //   LOG(WARNING) << "Fail to parse bes response";
    //} else {
    //   LOG(WARNING) << "tt:" << tt.DebugString();
    //}
 
    // Fill response.
    //cntl->response_http_header().set_content_type("application/octet-stream");
    //std::stringstream stream;  
    //stream << response_string.length();  
    //cntl->http_response().AppendHeader(base::Slice("Content-Length"), base::Slice(stream.str()));

    //cntl->http_response().AppendHeader(base::Slice("Content-type"), base::Slice("application/octet-stream"));
    //cntl->http_response().AppendHeader(base::Slice("Content-Length"), base::Slice(int2str(response_string.length())));
    //cntl->http_response().AppendHeader(base::Slice("Connection"), base::Slice("keep-alive"));

    cntl->http_response().set_content_type("application/octet-stream");
    LOG(INFO) << "Key:" << begin_time << " Response success:"
            << response_string << std::endl;
    cntl->response_attachment().append(response_string);
    //done_guard.release();
}

} // namespace ad 
} // rtb
