// Baidu RPC - A framework to host and access services throughout Baidu.
// Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
// A client sending EchoRequests to server by multiple threads.

#include <gflags/gflags.h>
#include <baas-lib-c/baas.h>
#include <baas-lib-c/giano_mock_helper.h>
#include <boost/atomic.hpp>
#include <bthread.h>
#include <baidu/streaming_log.h>
#include <baidu/string_printf.h>
#include <baidu/time.h>
#include <baidu/cacheline.h>
#include <baidu/rpc/channel.h>
#include <baidu/rpc/policy/giano_authenticator.h>
#include <deque>
#include <fstream>
#include "http_server.pb.h"
#include <string>
#include <vector>
#include <sstream>
using std::vector;
using std::string;

vector<vector<string> > global_vector;
vector<bthread_t> tids;

volatile bool g_signal_quit = false;
void sigint_handler(int) { 
    g_signal_quit = true; 
}

DEFINE_int32(thread_num, 50, "Number of threads to send requests");
DEFINE_bool(use_bthread, false, "Use bthread to send requests");
DEFINE_string(attachment, "foo", "Carry this along with requests");
DEFINE_int32(request_size, 16, "Bytes of each request");
DEFINE_bool(auth, false, "Enable Giano authentication");
DEFINE_string(connection_type, "pooled",
              "Connection type. Available values: single, pool, short");
DEFINE_string(server, "0.0.0.0:8001", "IP Address of server");
DEFINE_string(uri, "/RTBService/bes", "Http URI of server");
DEFINE_int32(timeout_ms, 5000, "RPC timeout in milliseconds");
DEFINE_int32(max_retry, 3, "Maximum retry times by RPC framework"); 
DEFINE_bool(dont_fail, false, "Print fatal when some call failed");
DEFINE_int32(sleep_time, 0, "Sleep time between every request"); 

DEFINE_bool(use_http, true, "Use http protocol to transfer messages");
DEFINE_bool(mobile, false, "Use mobile");

pthread_mutex_t g_latency_mutex = PTHREAD_MUTEX_INITIALIZER;
struct BAIDU_CACHELINE_ALIGNMENT SenderInfo {
    size_t nsuccess;
    int64_t latency_sum;
};
std::deque<SenderInfo> g_sender_info;

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

void fill_buff(vector<vector<std::string> >& request_buf)
{
    std::ifstream infile;
    infile.open("test_in"); 
    string line;
    while(std::getline(infile, line)) {
        std::vector<std::string> arr;
        split(line , "\t", arr);
        request_buf.push_back(arr);
    }
    infile.close();
}



void fill_request(AdxRtb::BidRequest& request, const vector<std::string>& arr)
{
    request.set_id(arr[0]);
    request.set_ip(arr[1]);
    AdxRtb::BidRequest::BaiduId *baiduid = request.add_baidu_id_list();
    baiduid->set_baidu_user_id(arr[2]);
    baiduid->set_baidu_user_id_version(atoi(arr[3].c_str()));
    
    baiduid = request.add_baidu_id_list();
    baiduid->set_baidu_user_id(arr[4]);
    baiduid->set_baidu_user_id_version(atoi(arr[5].c_str()));

    AdxRtb::BidRequest::Geo *user_geo_info = request.mutable_user_geo_info();
    AdxRtb::BidRequest::Geo::UserLocation *user_location = user_geo_info->mutable_user_location();
    user_location->set_province(arr[6]);
    user_location->set_city(arr[7]);
    user_location->set_district(arr[8]);
    user_location->set_street(arr[9]);
    

    request.add_page_keyword(arr[10]);
    request.add_page_keyword(arr[11]);
    request.add_page_keyword(arr[12]);
    request.add_page_keyword(arr[13]);

    AdxRtb::BidRequest::AdSlot *adslot = request.add_adslot();
    adslot->set_minimum_cpm(atoi(arr[14].c_str()));
    adslot->set_sequence_id(atoi(arr[15].c_str()));
    adslot->set_slot_visibility(atoi(arr[16].c_str()));
    adslot->set_width(atoi(arr[17].c_str()));
    adslot->set_height(atoi(arr[18].c_str()));
    adslot->add_creative_type(atoi(arr[19].c_str()));


    AdxRtb::BidRequest::Mobile *mobile = request.mutable_mobile();
    AdxRtb::BidRequest::Mobile::MobileID *mid = mobile->add_id();

    mid->set_type(::AdxRtb::BidRequest_Mobile_MobileID_IDType(atoi(arr[20].c_str())));
    mid->set_id(arr[21].c_str());
    request.set_url(arr[22].c_str());
}

void* echo_request_sender(void* arg) {
    // `Channel' is thread safe
    baidu::rpc::Channel* channel = static_cast<baidu::rpc::Channel*>(arg);

    // Normally, you should not call a Channel directly, but instead construct
    // a stub Service wrapping it. stub can be shared by all threads as well.
    AdxRtb::HttpService_Stub stub(channel);

    int log_id = 0;
    SenderInfo* info = NULL;
    {
        BAIDU_SCOPED_LOCK(g_latency_mutex);
        g_sender_info.push_back(SenderInfo());
        info = &g_sender_info.back();
    }

    srand(pthread_self());  
    while ((!g_signal_quit)) {
        // We will receive response synchronously, safe to put variables
        // on stack.
        
        AdxRtb::BidRequest request;
        AdxRtb::BidResponse response;
        baidu::rpc::Controller cntl;

        int index = rand() % global_vector.size();
        
        fill_request(request, global_vector[index]);


//        adslot = request.add_adslot();
//        adslot->set_minimum_cpm(10);
//        adslot->set_sequence_id(2);
//        adslot->set_slot_visibility(2);
//        adslot->set_width(300);
//        adslot->set_height(250);
//        adslot->add_creative_type(1);
//
        // You can compress the request by setting Controller, but be aware
        // that compression may be costly, evaluate before turning on.
        // cntl->set_request_compress_type(baidu::rpc::COMPRESS_TYPE_GZIP);
        cntl.set_log_id(log_id ++);  // set by user
        cntl.set_timeout_ms(FLAGS_timeout_ms/*milliseconds*/);
        // RPC system only retries when the underlying connection is broken,
        // and it does this for at most `FLAGS_max_retry' times before the
        // deadline set by timeout
        cntl.set_max_retry(FLAGS_max_retry);
        if (!FLAGS_use_http) {
            // Set attachment which is wired to network directly instead of 
            // being serialized into protobuf messages.
            cntl.request_attachment().append(FLAGS_attachment);
        }

        // Because `done'(last parameter) is NULL, this function waits until
        // the response comes back or error occurs(including timedout).
        const int64_t start_time = baidu::cpuwide_time_us();
        if (!FLAGS_use_http) {
            //stub.bes_bidding(&cntl, &request, &response, NULL);
        } else {
            baidu::rpc::HttpHeader &header = cntl.http_request();
            header.set_method(baidu::rpc::HTTP_METHOD_POST);
            header.uri() = FLAGS_uri;

            base::IOBuf value;
            base::IOBufAsZeroCopyOutputStream ostream(&value);
            request.SerializeToZeroCopyStream(&ostream);
            cntl.request_attachment().append(value);

            channel->CallMethod(NULL, &cntl, NULL, NULL, NULL);

            base::IOBufAsZeroCopyInputStream istream(cntl.response_attachment());
            response.ParseFromZeroCopyStream(&istream);
            //LOG(DEBUG) << "response: " << response.DebugString();
        }
        
        const int64_t end_time = baidu::cpuwide_time_us();
        const int64_t elp = end_time - start_time;
        if (!cntl.Failed()) {
            info->latency_sum += elp;
            ++info->nsuccess;
        } else {
            LOG(FATAL) << "Fail to send HttpRequest, " << cntl.ErrorText();
            BAIDU_CHECK(g_signal_quit || !FLAGS_dont_fail)
                << "error=" << cntl.ErrorText() << " latency=" << elp;
            BAIDU_CHECK(elp < 5000) << "actually " << elp;
            // We can't connect to the server, sleep a while. Notice that this
            // is a specific sleeping to prevent this thread from spinning too
            // fast. You should continue the business logic in a production 
            // server rather than sleeping.
            bthread_usleep(50000);
        }
        if (FLAGS_sleep_time > 0) {
            usleep(FLAGS_sleep_time);
        }
    }

    return NULL;
}


int main(int argc, char* argv[]) {
    // Parse gflags. We recommend you to use gflags as well.
    google::ParseCommandLineFlags(&argc, &argv, true);

    
    // Login to get `CredentialGenerator' (see baas-lib-c/baas.h for more
    // information) and then pass it to `GianoAuthenticator'
    // Turn on giano mock (always pass authentication) for simplicity
    baas::CredentialGenerator gen = CREATE_MOCK_PERSONAL_GENERATOR(
            "mock_user", "mock_roles", "mock_group", baas::sdk::BAAS_OK);
    baidu::rpc::policy::GianoAuthenticator auth(&gen, NULL);

    // A Channel represents a communication line to a Server. Notice that 
    // Channel is thread-safe and can be shared by all threads in your program.
    baidu::rpc::Channel channel;
    baidu::rpc::ChannelOptions option;
    option.connection_type =
            baidu::rpc::StringToConnectionType(FLAGS_connection_type);
    if (option.connection_type == baidu::rpc::CONNECTION_TYPE_UNKNOWN) {
        LOG(FATAL) << "Unknown connection type=" << FLAGS_connection_type;
        return -1;
    }
    option.auth = NULL;
    if (FLAGS_use_http) {
        option.protocol = baidu::rpc::PROTOCOL_HTTP;
    }
    
    // Initialize the channel, NULL means using default options, for more 
    // options, see `baidu/rpc/channel.h'.
    if (channel.Init(FLAGS_server.c_str(), &option) != 0) {
        LOG(FATAL) << "Fail to initialize channel";
        return -1;
    }
    fill_buff(global_vector);

    tids.resize(FLAGS_thread_num);
    if (!FLAGS_use_bthread) {
        for (int i = 0; i < FLAGS_thread_num; ++i) {
            if (pthread_create(&tids[i], NULL,
                               echo_request_sender, &channel) != 0) {
                LOG(FATAL) << "Fail to create pthread";
                return -1;
            }
        }
    } else {
        for (int i = 0; i < FLAGS_thread_num; ++i) {
            if (bthread_start_background(
                    &tids[i], NULL, 
                    echo_request_sender, &channel) != 0) {
                LOG(FATAL) << "Fail to create bthread";
                return -1;
            }
        }
    }

    signal(SIGINT, sigint_handler);
    int64_t last_counter = 0;
    int64_t last_latency_sum = 0;
    std::vector<size_t> last_nsuccess(FLAGS_thread_num);
    while (!g_signal_quit) {
        sleep(1);
        int64_t latency_sum = 0;
        int64_t nsuccess = 0;
        pthread_mutex_lock(&g_latency_mutex);
        BAIDU_CHECK_EQ(g_sender_info.size(), (size_t)FLAGS_thread_num);
        for (size_t i = 0; i < g_sender_info.size(); ++i) {
            const SenderInfo& info = g_sender_info[i];
            latency_sum += info.latency_sum;
            nsuccess += info.nsuccess;
            if (FLAGS_dont_fail) {
                BAIDU_CHECK(info.nsuccess > last_nsuccess[i]);
            }
            last_nsuccess[i] = info.nsuccess;
        }
        pthread_mutex_unlock(&g_latency_mutex);

        const int64_t avg_latency = (latency_sum - last_latency_sum) /
            std::max(nsuccess - last_counter, 1L);
        std::cout << "Sending request at qps=" << nsuccess - last_counter
                  << " latency=" << avg_latency << std::endl;
        last_counter = nsuccess;
        last_latency_sum = latency_sum;
    }

    LOG(TRACE) << "EchoClient is going to quit";
    for (int i = 0; i < FLAGS_thread_num; ++i) {
        if (!FLAGS_use_bthread) {
            pthread_join(tids[i], NULL);
        } else {
            bthread_join(tids[i], NULL);
        }
    }

    return 0;
}
