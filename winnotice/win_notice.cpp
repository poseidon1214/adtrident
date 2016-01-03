// Baidu RPC - A framework to host and access services throughout Baidu.
// Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
//
// If you have any problem, contact us:
//   Baidu Hi : group 1296497 
//   Email    : pbrpc@baidu.com
//   Wiki     : http://wiki.baidu.com/display/RPC/baidu-rpc

// A server to receive HttpRequest and send back HttpResponse.

#include <gflags/gflags.h>
#include <baas-lib-c/baas.h>
#include <base/logging.h>
#include <base/comlog_sink.h>
#include <baidu/rpc/server.h>
#include "win_notice.pb.h"

DEFINE_int32(port, 8010, "TCP Port of this server");
DEFINE_int32(idle_timeout_s, -1, "Connection will be closed if there is no "
             "read/write operations during the last `idle_timeout_s'");
DEFINE_int32(logoff_ms, 2000, "Maximum duration of server's LOGOFF state "
             "(waiting for client to close connection before server stops)");
DEFINE_string(config_path, "./conf/config.yaml", "config.yaml path");
DEFINE_string(log_config_path, "./conf/log.conf", "config.yaml path");

// Your implementation of example::HttpService
namespace ad {
namespace rtb {

using AdxRtb::HttpRequest;
using AdxRtb::HttpResponse;

class WinNoticeImpl : public AdxRtb::WinNotice {
public:
    WinNoticeImpl() {};
    virtual ~WinNoticeImpl() {};
    virtual void record(google::protobuf::RpcController* cntl_base,
                      const HttpRequest* /*request*/,
                      HttpResponse* /*response*/,
                      google::protobuf::Closure* done) {
        baidu::rpc::ClosureGuard done_guard(done);

        baidu::rpc::Controller* cntl =
            static_cast<baidu::rpc::Controller*>(cntl_base);

        LOG(INFO) << "Received " << (cntl->is_ssl() ? "HTTPS " : "HTTP " )
                   << "request[log_id=" << cntl->log_id() 
                   << "] from " << cntl->remote_side() 
                   << " host=" << cntl->http_request().uri().host() 
                   << " port= " << cntl->http_request().uri().port() << noflush;
        LOG(INFO) << ": " << cntl->request_attachment();

        //http://www.dsp.com/monitor?reqid=%%ID%%&price=%%PRICE%%&ext_data=%%EXT_ DATA%%
        //PRICE 基于 SHA-1 HMAC 算法进行加密,C++模块可以直接用 openssl 中的接口实现。
        //DSP 注册时 获得 32 字节的加密秘钥,用于解密。获取 32 字节的完整性检测密钥,用于价格完整性检查。
        std::string _ext_data;
        std::string _price;
        std::string _reqid;
        std::string _creative_id;
        std::string _style_type;
        std::string _index;
        for (baidu::rpc::URI::QueryIterator it = cntl->http_request().uri().QueryBegin();
                it != cntl->http_request().uri().QueryEnd(); ++it) {
            if(it->first == "ext_data") 
                _ext_data = it->second;
            if(it->first == "price") 
                _price = it->second;
            if(it->first == "reqid") 
                _reqid = it->second;
            if(it->first == "creative_id") 
                _creative_id = it->second;
            if(it->first == "style_type") 
                _style_type = it->second;
            if(it->first == "index") 
                _index = it->second;
            //std::cout << ' ' << it->first << '=' << it->second << std::endl;
        }
        LOG(NOTICE) << "adtrident win notice is:" << _reqid << "\t" << _price << "\t" 
            << _creative_id << "\t" << _style_type << "\t"
            << _index << "\t"<< _ext_data;        

        // Fill response.
        cntl->http_response().set_content_type("text/plain");
        base::IOBufBuilder os;
        os << "queries success!";
        os.move_to(cntl->response_attachment());
    }
};
}  // namespace ad 
}  // namespace rtb 

int main(int argc, char* argv[]) {
    // Parse gflags. We recommend you to use gflags as well.
    google::ParseCommandLineFlags(&argc, &argv, true);

    logging::SetLogSink(logging::ComlogSink::GetInstance());
    if (logging::ComlogSink::GetInstance()->SetupFromConfig("conf/winnotice_log.conf") != 0) {
        LOG(ERROR) << "Fail to setup comlog from conf/winnotice_log.conf";
        return -1;
    }
    baidu::rpc::Server server;
    server.set_version("win_notice");
    baidu::rpc::ServerOptions option;
    option.idle_timeout_sec = FLAGS_idle_timeout_s;
    //option.auth = auth.get();
    //option.certificate_file = FLAGS_certificate;
    //option.private_key_file = FLAGS_private_key;

    ad::rtb::WinNoticeImpl win_notice_impl;
    std::cout << "request begin" << std::endl;
    if (server.AddService(&win_notice_impl, 
                          baidu::rpc::SERVER_DOESNT_OWN_SERVICE) != 0) {
        LOG(ERROR) << "Fail to add service";
        return -1;
    }

    // Start the server.
    if (server.Start(FLAGS_port, &option) != 0) {
        LOG(ERROR) << "Fail to start HttpServer";
        return -1;
    }
    // Wait until Ctrl-C is pressed, then Stop() and Join() the server.
    server.RunUntilAskedToQuit();
    return 0;
}
