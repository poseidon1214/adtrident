/* Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * File: http_server.cpp
 * Auth: shenguolong@baidu.com
**/

#include <base/comlog_sink.h>
#include "http_server.h"

static ad::rtb::HttpServiceImpl s_http_service_impl;

DEFINE_int32(port, 8010, "TCP Port of this server");
DEFINE_int32(idle_timeout_s, -1, "Connection will be closed if there is no "
             "read/write operations during the last `idle_timeout_s'");
DEFINE_int32(logoff_ms, 2000, "Maximum duration of server's LOGOFF state "
             "(waiting for client to close connection before server stops)");
DEFINE_string(config_path, "./conf/config.yaml", "config.yaml path");
DEFINE_string(log_config_path, "./conf/log.conf", "config.yaml path");
//DEFINE_string(certificate, "cert.pem", "Certificate file path to enable SSL");
//DEFINE_string(private_key, "key.pem", "Private key file path to enable SSL");

bool g_signal_quit = false;
void sigint_handler(int) { 
    g_signal_quit = true; 
}

void reload_pdata(int) { 
    LOG(INFO) << "receive reload pdata signal." << std::endl;
    s_http_service_impl.init(FLAGS_config_path); 
    LOG(INFO) << "reload model over." << std::endl;
}

int main(int argc, char* argv[]) {
    // Parse gflags. We recommend you to use gflags as well.
    google::ParseCommandLineFlags(&argc, &argv, true);
    logging::SetLogSink(logging::ComlogSink::GetInstance());
    if (logging::ComlogSink::GetInstance()->SetupFromConfig("conf/log.conf") != 0) {
        LOG(ERROR) << "Fail to setup comlog from conf/log.conf";
        return -1;
    }

    // Generally you only need one Server.
    baidu::rpc::Server server;
    // Optional, will be shown on /version page
    server.set_version("bes");
    // For more options see `baidu/rpc/server.h'.
    baidu::rpc::ServerOptions option;
    //option.num_threads = 5;
    option.idle_timeout_sec = FLAGS_idle_timeout_s;
    //option.certificate_file = FLAGS_certificate;
    //option.private_key_file = FLAGS_private_key;

    // Instance of your implemented service.
    s_http_service_impl.init(FLAGS_config_path);

    // Add the service into server. Notice the second parameter, because the
    // service is put on stack, we don't want server to delete it, otherwise
    // use baidu::rpc::SERVER_OWNS_SERVICE.
    if (server.AddService(&s_http_service_impl, 
                          baidu::rpc::SERVER_DOESNT_OWN_SERVICE) != 0) {
        LOG(FATAL) << "Fail to add service";
        return -1;
    }

    // Start the server.
    if (server.Start(FLAGS_port, &option) != 0) {
        LOG(FATAL) << "Fail to start HttpServer";
        return -1;
    }
    LOG(INFO) << "HttpServer is serving on port=" << FLAGS_port;

    // Service logic are running in separate worker threads, for main thread,
    // we don't have much to do, just spinning.
    signal(SIGINT, sigint_handler);
    signal(SIGUSR1, reload_pdata);
    signal(SIGPIPE, SIG_IGN);
    while (!g_signal_quit) {
        sleep(1);
    }

    // Don't forget to stop and join the server otherwise still-running
    // worker threads may crash your program. Clients will have/ at most
    // `FLAGS_logoff_ms' to close their connections. If some connections
    // still remains after `FLAGS_logoff_ms', they will be closed by force.
    server.Stop(FLAGS_logoff_ms);
    server.Join();
    
    return 0;
}
