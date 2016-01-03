#COMAKE2 edit-mode: -*- Makefile -*-
####################64Bit Mode####################
ifeq ($(shell uname -m),x86_64)
CC=gcc
CXX=g++
CXXFLAGS=
CFLAGS=
CPPFLAGS=-g \
  -pipe \
  -W \
  -Wall \
  -Werror \
  -fPIC \
  -Wno-deprecated \
  --std=c++11 \
  -D__const__=
INCPATH=-Isrc
DEP_INCPATH=-I../../app-test/ecom/im/common/utlib \
  -I../../app-test/ecom/im/common/utlib/include \
  -I../../app-test/ecom/im/common/utlib/output \
  -I../../app-test/ecom/im/common/utlib/output/include \
  -I../../app/ecom/common/expframework \
  -I../../app/ecom/common/expframework/include \
  -I../../app/ecom/common/expframework/output \
  -I../../app/ecom/common/expframework/output/include \
  -I../../app/ecom/elib/ecommon-lib \
  -I../../app/ecom/elib/ecommon-lib/include \
  -I../../app/ecom/elib/ecommon-lib/output \
  -I../../app/ecom/elib/ecommon-lib/output/include \
  -I../../app/ecom/elib/shifen-lib \
  -I../../app/ecom/elib/shifen-lib/include \
  -I../../app/ecom/elib/shifen-lib/output \
  -I../../app/ecom/elib/shifen-lib/output/include \
  -I../../app/ecom/im/im-lib \
  -I../../app/ecom/im/im-lib/include \
  -I../../app/ecom/im/im-lib/output \
  -I../../app/ecom/im/im-lib/output/include \
  -I../../app/ecom/im/im-proto \
  -I../../app/ecom/im/im-proto/include \
  -I../../app/ecom/im/im-proto/output \
  -I../../app/ecom/im/im-proto/output/include \
  -I../../app/ecom/im/lib \
  -I../../app/ecom/im/lib/include \
  -I../../app/ecom/im/lib/output \
  -I../../app/ecom/im/lib/output/include \
  -I../../app/ecom/im/make \
  -I../../app/ecom/im/make/include \
  -I../../app/ecom/im/make/output \
  -I../../app/ecom/im/make/output/include \
  -I../../app/ecom/im/xbuiltin \
  -I../../app/ecom/im/xbuiltin/include \
  -I../../app/ecom/im/xbuiltin/output \
  -I../../app/ecom/im/xbuiltin/output/include \
  -I../../app/ecom/im/xmulti \
  -I../../app/ecom/im/xmulti/include \
  -I../../app/ecom/im/xmulti/output \
  -I../../app/ecom/im/xmulti/output/include \
  -I../../app/ecom/im/yacl \
  -I../../app/ecom/im/yacl/include \
  -I../../app/ecom/im/yacl/output \
  -I../../app/ecom/im/yacl/output/include \
  -I../../com/idlcompiler \
  -I../../com/idlcompiler/include \
  -I../../com/idlcompiler/output \
  -I../../com/idlcompiler/output/include \
  -I../../lib2-64/bsl \
  -I../../lib2-64/bsl/include \
  -I../../lib2-64/bsl/output \
  -I../../lib2-64/bsl/output/include \
  -I../../lib2-64/ccode \
  -I../../lib2-64/ccode/include \
  -I../../lib2-64/ccode/output \
  -I../../lib2-64/ccode/output/include \
  -I../../lib2-64/dict \
  -I../../lib2-64/dict/include \
  -I../../lib2-64/dict/output \
  -I../../lib2-64/dict/output/include \
  -I../../lib2-64/libcrf \
  -I../../lib2-64/libcrf/include \
  -I../../lib2-64/libcrf/output \
  -I../../lib2-64/libcrf/output/include \
  -I../../lib2-64/others-ex \
  -I../../lib2-64/others-ex/include \
  -I../../lib2-64/others-ex/output \
  -I../../lib2-64/others-ex/output/include \
  -I../../lib2-64/ullib \
  -I../../lib2-64/ullib/include \
  -I../../lib2-64/ullib/output \
  -I../../lib2-64/ullib/output/include \
  -I../../lib2-64/wordseg \
  -I../../lib2-64/wordseg/include \
  -I../../lib2-64/wordseg/output \
  -I../../lib2-64/wordseg/output/include \
  -I../../op/oped/noah/webfoot/naming-lib \
  -I../../op/oped/noah/webfoot/naming-lib/include \
  -I../../op/oped/noah/webfoot/naming-lib/output \
  -I../../op/oped/noah/webfoot/naming-lib/output/include \
  -I../../public/ans \
  -I../../public/ans/include \
  -I../../public/ans/output \
  -I../../public/ans/output/include \
  -I../../public/baidu-rpc \
  -I../../public/baidu-rpc/include \
  -I../../public/baidu-rpc/output \
  -I../../public/baidu-rpc/output/include \
  -I../../public/bslext \
  -I../../public/bslext/include \
  -I../../public/bslext/output \
  -I../../public/bslext/output/include \
  -I../../public/bthread \
  -I../../public/bthread/include \
  -I../../public/bthread/output \
  -I../../public/bthread/output/include \
  -I../../public/bvar \
  -I../../public/bvar/include \
  -I../../public/bvar/output \
  -I../../public/bvar/output/include \
  -I../../public/comlog-plugin \
  -I../../public/comlog-plugin/include \
  -I../../public/comlog-plugin/output \
  -I../../public/comlog-plugin/output/include \
  -I../../public/common \
  -I../../public/common/include \
  -I../../public/common/output \
  -I../../public/common/output/include \
  -I../../public/configure \
  -I../../public/configure/include \
  -I../../public/configure/output \
  -I../../public/configure/output/include \
  -I../../public/connectpool \
  -I../../public/connectpool/include \
  -I../../public/connectpool/output \
  -I../../public/connectpool/output/include \
  -I../../public/idlcompiler \
  -I../../public/idlcompiler/include \
  -I../../public/idlcompiler/output \
  -I../../public/idlcompiler/output/include \
  -I../../public/iobuf \
  -I../../public/iobuf/include \
  -I../../public/iobuf/output \
  -I../../public/iobuf/output/include \
  -I../../public/mcpack \
  -I../../public/mcpack/include \
  -I../../public/mcpack/output \
  -I../../public/mcpack/output/include \
  -I../../public/murmurhash \
  -I../../public/murmurhash/include \
  -I../../public/murmurhash/output \
  -I../../public/murmurhash/output/include \
  -I../../public/noah/giano-lib/release/baas-lib-c \
  -I../../public/noah/giano-lib/release/baas-lib-c/include \
  -I../../public/noah/giano-lib/release/baas-lib-c/output \
  -I../../public/noah/giano-lib/release/baas-lib-c/output/include \
  -I../../public/nshead \
  -I../../public/nshead/include \
  -I../../public/nshead/output \
  -I../../public/nshead/output/include \
  -I../../public/odict \
  -I../../public/odict/include \
  -I../../public/odict/output \
  -I../../public/odict/output/include \
  -I../../public/protobuf-json \
  -I../../public/protobuf-json/include \
  -I../../public/protobuf-json/output \
  -I../../public/protobuf-json/output/include \
  -I../../public/spreg \
  -I../../public/spreg/include \
  -I../../public/spreg/output \
  -I../../public/spreg/output/include \
  -I../../public/ub \
  -I../../public/ub/include \
  -I../../public/ub/output \
  -I../../public/ub/output/include \
  -I../../public/uconv \
  -I../../public/uconv/include \
  -I../../public/uconv/output \
  -I../../public/uconv/output/include \
  -I../../third-64/boost \
  -I../../third-64/boost/include \
  -I../../third-64/boost/output \
  -I../../third-64/boost/output/include \
  -I../../third-64/gflags \
  -I../../third-64/gflags/include \
  -I../../third-64/gflags/output \
  -I../../third-64/gflags/output/include \
  -I../../third-64/gtest \
  -I../../third-64/gtest/include \
  -I../../third-64/gtest/output \
  -I../../third-64/gtest/output/include \
  -I../../third-64/leveldb \
  -I../../third-64/leveldb/include \
  -I../../third-64/leveldb/output \
  -I../../third-64/leveldb/output/include \
  -I../../third-64/libevent \
  -I../../third-64/libevent/include \
  -I../../third-64/libevent/output \
  -I../../third-64/libevent/output/include \
  -I../../third-64/mysql \
  -I../../third-64/mysql/include \
  -I../../third-64/mysql/output \
  -I../../third-64/mysql/output/include \
  -I../../third-64/openssl \
  -I../../third-64/openssl/include \
  -I../../third-64/openssl/output \
  -I../../third-64/openssl/output/include \
  -I../../third-64/pcre \
  -I../../third-64/pcre/include \
  -I../../third-64/pcre/output \
  -I../../third-64/pcre/output/include \
  -I../../third-64/protobuf \
  -I../../third-64/protobuf/include \
  -I../../third-64/protobuf/output \
  -I../../third-64/protobuf/output/include \
  -I../../third-64/snappy \
  -I../../third-64/snappy/include \
  -I../../third-64/snappy/output \
  -I../../third-64/snappy/output/include \
  -I../../third-64/stlport \
  -I../../third-64/stlport/include \
  -I../../third-64/stlport/output \
  -I../../third-64/stlport/output/include \
  -I../../third-64/zlib \
  -I../../third-64/zlib/include \
  -I../../third-64/zlib/output \
  -I../../third-64/zlib/output/include \
  -I../../thirdsrc/protobuf \
  -I../../thirdsrc/protobuf/include \
  -I../../thirdsrc/protobuf/output \
  -I../../thirdsrc/protobuf/output/include

#============ CCP vars ============
CCHECK=@ccheck.py
CCHECK_FLAGS=
PCLINT=@pclint
PCLINT_FLAGS=
CCP=@ccp.py
CCP_FLAGS=


#COMAKE UUID
COMAKE_MD5=b18567bc885143d6a5acda372f3a0b58  COMAKE


.PHONY:all
all:comake2_makefile_check http_server 
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mall[0m']"
	@echo "make all done"

.PHONY:comake2_makefile_check
comake2_makefile_check:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mcomake2_makefile_check[0m']"
	#in case of error, update 'Makefile' by 'comake2'
	@echo "$(COMAKE_MD5)">comake2.md5
	@md5sum -c --status comake2.md5
	@rm -f comake2.md5

.PHONY:ccpclean
ccpclean:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mccpclean[0m']"
	@echo "make ccpclean done"

.PHONY:clean
clean:ccpclean
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mclean[0m']"
	rm -rf http_server
	rm -rf ./output/bin/http_server
	rm -rf src/http_server_RtbData.o
	rm -rf src/http_server_RtbDict.o
	rm -rf src/http_server_RtbTarget.o
	rm -rf src/http_server_RtbUtil.o
	rm -rf src/http_server_common.o
	rm -rf src/http_server_http_server.o
	rm -rf src/http_server_http_server_main.o
	rm -rf src/http_server_redis_op.o
	rm -rf src/http_server_rtb_data.o
	rm -rf src/http_server_rtb_strategy.o
	rm -rf proto/baidu_realtime_bidding.pb.cc
	rm -rf proto/baidu_realtime_bidding.pb.h
	rm -rf proto/http_server_baidu_realtime_bidding.pb.o
	rm -rf proto/black_list_info.pb.cc
	rm -rf proto/black_list_info.pb.h
	rm -rf proto/http_server_black_list_info.pb.o
	rm -rf proto/business_ad.pb.cc
	rm -rf proto/business_ad.pb.h
	rm -rf proto/http_server_business_ad.pb.o
	rm -rf proto/http_server.pb.cc
	rm -rf proto/http_server.pb.h
	rm -rf proto/http_server_http_server.pb.o
	rm -rf proto/idea_info.pb.cc
	rm -rf proto/idea_info.pb.h
	rm -rf proto/http_server_idea_info.pb.o
	rm -rf proto/phrase_business.pb.cc
	rm -rf proto/phrase_business.pb.h
	rm -rf proto/http_server_phrase_business.pb.o
	rm -rf proto/plan_info.pb.cc
	rm -rf proto/plan_info.pb.h
	rm -rf proto/http_server_plan_info.pb.o
	rm -rf proto/stop_word.pb.cc
	rm -rf proto/stop_word.pb.h
	rm -rf proto/http_server_stop_word.pb.o
	rm -rf proto/unit_idea.pb.cc
	rm -rf proto/unit_idea.pb.h
	rm -rf proto/http_server_unit_idea.pb.o
	rm -rf proto/unit_info.pb.cc
	rm -rf proto/unit_info.pb.h
	rm -rf proto/http_server_unit_info.pb.o
	rm -rf proto/user_info.pb.cc
	rm -rf proto/user_info.pb.h
	rm -rf proto/http_server_user_info.pb.o

.PHONY:dist
dist:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdist[0m']"
	tar czvf output.tar.gz output
	@echo "make dist done"

.PHONY:distclean
distclean:clean
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdistclean[0m']"
	rm -f output.tar.gz
	@echo "make distclean done"

.PHONY:love
love:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlove[0m']"
	@echo "make love done"

http_server:src/http_server_RtbData.o \
  src/http_server_RtbDict.o \
  src/http_server_RtbTarget.o \
  src/http_server_RtbUtil.o \
  src/http_server_common.o \
  src/http_server_http_server.o \
  src/http_server_http_server_main.o \
  src/http_server_redis_op.o \
  src/http_server_rtb_data.o \
  src/http_server_rtb_strategy.o \
  proto/http_server_baidu_realtime_bidding.pb.o \
  proto/http_server_black_list_info.pb.o \
  proto/http_server_business_ad.pb.o \
  proto/http_server_http_server.pb.o \
  proto/http_server_idea_info.pb.o \
  proto/http_server_phrase_business.pb.o \
  proto/http_server_plan_info.pb.o \
  proto/http_server_stop_word.pb.o \
  proto/http_server_unit_idea.pb.o \
  proto/http_server_unit_info.pb.o \
  proto/http_server_user_info.pb.o \
  ./lib/libmkl_core.a \
  ./lib/libmkl_sequential.a \
  ./lib/libmkl_intel_lp64.a \
  ./lib/libyaml-cpp.a \
  ./lib/libhiredis.so.0.10 \
  ./lib/libmysqlclient.so.18
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mhttp_server[0m']"
	$(CXX) src/http_server_RtbData.o \
  src/http_server_RtbDict.o \
  src/http_server_RtbTarget.o \
  src/http_server_RtbUtil.o \
  src/http_server_common.o \
  src/http_server_http_server.o \
  src/http_server_http_server_main.o \
  src/http_server_redis_op.o \
  src/http_server_rtb_data.o \
  src/http_server_rtb_strategy.o \
  proto/http_server_baidu_realtime_bidding.pb.o \
  proto/http_server_black_list_info.pb.o \
  proto/http_server_business_ad.pb.o \
  proto/http_server_http_server.pb.o \
  proto/http_server_idea_info.pb.o \
  proto/http_server_phrase_business.pb.o \
  proto/http_server_plan_info.pb.o \
  proto/http_server_stop_word.pb.o \
  proto/http_server_unit_idea.pb.o \
  proto/http_server_unit_info.pb.o \
  proto/http_server_user_info.pb.o -Xlinker "-(" ./lib/libmkl_core.a \
  ./lib/libmkl_sequential.a \
  ./lib/libmkl_intel_lp64.a \
  ./lib/libyaml-cpp.a \
  ./lib/libhiredis.so.0.10 \
  ./lib/libmysqlclient.so.18 ../../app-test/ecom/im/common/utlib/output/lib/libutlib.a \
  ../../app/ecom/common/expframework/libexpfw.a \
  ../../app/ecom/elib/ecommon-lib/libellib.a \
  ../../app/ecom/elib/shifen-lib/libsflib.a \
  ../../app/ecom/im/im-lib/libimlib.a \
  ../../app/ecom/im/im-proto/libitp.a \
  ../../app/ecom/im/xbuiltin/libxbuiltin.a \
  ../../app/ecom/im/xmulti/output/lib/libxmulti.a \
  ../../app/ecom/im/yacl/libyacl.a \
  ../../com/idlcompiler/astyle/libastyle.a \
  ../../com/idlcompiler/cxx/libskeleton.a \
  ../../com/idlcompiler/java/libjava_skeleton.a \
  ../../com/idlcompiler/parser/libparser.a \
  ../../com/idlcompiler/php/libphp_skeleton.a \
  ../../lib2-64/bsl/lib/libbsl.a \
  ../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../lib2-64/bsl/lib/libbsl_var.a \
  ../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../lib2-64/ccode/lib/libulccode.a \
  ../../lib2-64/dict/lib/libuldict.a \
  ../../lib2-64/libcrf/lib/libcrf.a \
  ../../lib2-64/others-ex/lib/libullib_ex.a \
  ../../lib2-64/ullib/lib/libullib.a \
  ../../lib2-64/wordseg/libsegment.a \
  ../../op/oped/noah/webfoot/naming-lib/output/lib/libwebfoot_naming.a \
  ../../public/baidu-rpc/libbdrpc.a \
  ../../public/bthread/libbthread.a \
  ../../public/bvar/libbvar.a \
  ../../public/common/libbase.a \
  ../../public/configure/libconfig.a \
  ../../public/iobuf/libiobuf.a \
  ../../public/murmurhash/libmurmurhash3.a \
  ../../public/noah/giano-lib/release/baas-lib-c/libbaas_interface.a \
  ../../public/odict/libodict.a \
  ../../public/protobuf-json/libjson-pb.a \
  ../../public/spreg/libspreg.a \
  ../../public/ub/output/lib/libub.a \
  ../../third-64/boost/lib/libboost_context.a \
  ../../third-64/gflags/lib/libgflags.a \
  ../../third-64/gflags/lib/libgflags_nothreads.a \
  ../../third-64/gtest/lib/libgmock.a \
  ../../third-64/gtest/lib/libgmock_main.a \
  ../../third-64/gtest/lib/libgtest.a \
  ../../third-64/gtest/lib/libgtest_main.a \
  ../../third-64/leveldb/lib/libleveldb.a \
  ../../third-64/libevent/lib/libevent.a \
  ../../third-64/libevent/lib/libevent_core.a \
  ../../third-64/libevent/lib/libevent_extra.a \
  ../../third-64/libevent/lib/libevent_openssl.a \
  ../../third-64/libevent/lib/libevent_pthreads.a \
  ../../third-64/mysql/lib/libdbug.a \
  ../../third-64/mysql/lib/libheap.a \
  ../../third-64/mysql/lib/libmyisam.a \
  ../../third-64/mysql/lib/libmyisammrg.a \
  ../../third-64/mysql/lib/libmysqlclient.a \
  ../../third-64/mysql/lib/libmysqlclient_r.a \
  ../../third-64/mysql/lib/libmystrings.a \
  ../../third-64/mysql/lib/libmysys.a \
  ../../third-64/mysql/lib/libvio.a \
  ../../third-64/openssl/lib/libcrypto.a \
  ../../third-64/openssl/lib/libssl.a \
  ../../third-64/pcre/lib/libpcre.a \
  ../../third-64/pcre/lib/libpcrecpp.a \
  ../../third-64/pcre/lib/libpcreposix.a \
  ../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../third-64/protobuf/lib/libprotobuf.a \
  ../../third-64/protobuf/lib/libprotoc.a \
  ../../third-64/snappy/lib/libsnappy.a \
  ../../third-64/zlib/lib/libz.a -lpthread \
  -lrt \
  -ldl \
  -lz -Xlinker "-)" -o http_server
	mkdir -p ./output/bin
	cp -f http_server ./output/bin

src/http_server_RtbData.o:src/RtbData.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/http_server_RtbData.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o src/http_server_RtbData.o src/RtbData.cpp

src/http_server_RtbDict.o:src/RtbDict.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/http_server_RtbDict.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o src/http_server_RtbDict.o src/RtbDict.cpp

src/http_server_RtbTarget.o:src/RtbTarget.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/http_server_RtbTarget.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o src/http_server_RtbTarget.o src/RtbTarget.cpp

src/http_server_RtbUtil.o:src/RtbUtil.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/http_server_RtbUtil.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o src/http_server_RtbUtil.o src/RtbUtil.cpp

src/http_server_common.o:src/common.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/http_server_common.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o src/http_server_common.o src/common.cpp

src/http_server_http_server.o:src/http_server.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/http_server_http_server.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o src/http_server_http_server.o src/http_server.cpp

src/http_server_http_server_main.o:src/http_server_main.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/http_server_http_server_main.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o src/http_server_http_server_main.o src/http_server_main.cpp

src/http_server_redis_op.o:src/redis_op.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/http_server_redis_op.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o src/http_server_redis_op.o src/redis_op.cpp

src/http_server_rtb_data.o:src/rtb_data.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/http_server_rtb_data.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o src/http_server_rtb_data.o src/rtb_data.cpp

src/http_server_rtb_strategy.o:src/rtb_strategy.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/http_server_rtb_strategy.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o src/http_server_rtb_strategy.o src/rtb_strategy.cpp

proto/baidu_realtime_bidding.pb.cc \
  proto/baidu_realtime_bidding.pb.h:proto/baidu_realtime_bidding.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/baidu_realtime_bidding.pb.cc \
  proto/baidu_realtime_bidding.pb.h[0m']"
	../../third-64/protobuf/bin/protoc --cpp_out=proto --proto_path=proto --proto_path=../../app/ecom/im/xbuiltin/output/include/ \
  --proto_path=../../third-64/protobuf/include/ \
  --plugin=protoc-gen-xbuiltin=../../app/ecom/im/xbuiltin/output/bin/xbuiltin-generator \
  --xbuiltin_out \
  proto proto/baidu_realtime_bidding.proto

proto/baidu_realtime_bidding.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/baidu_realtime_bidding.proto[0m']"
	@echo "ALREADY BUILT"

proto/http_server_baidu_realtime_bidding.pb.o:proto/baidu_realtime_bidding.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/http_server_baidu_realtime_bidding.pb.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o proto/http_server_baidu_realtime_bidding.pb.o proto/baidu_realtime_bidding.pb.cc

proto/black_list_info.pb.cc \
  proto/black_list_info.pb.h:proto/black_list_info.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/black_list_info.pb.cc \
  proto/black_list_info.pb.h[0m']"
	../../third-64/protobuf/bin/protoc --cpp_out=proto --proto_path=proto --proto_path=../../app/ecom/im/xbuiltin/output/include/ \
  --proto_path=../../third-64/protobuf/include/ \
  --plugin=protoc-gen-xbuiltin=../../app/ecom/im/xbuiltin/output/bin/xbuiltin-generator \
  --xbuiltin_out \
  proto proto/black_list_info.proto

proto/black_list_info.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/black_list_info.proto[0m']"
	@echo "ALREADY BUILT"

proto/http_server_black_list_info.pb.o:proto/black_list_info.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/http_server_black_list_info.pb.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o proto/http_server_black_list_info.pb.o proto/black_list_info.pb.cc

proto/business_ad.pb.cc \
  proto/business_ad.pb.h:proto/business_ad.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/business_ad.pb.cc \
  proto/business_ad.pb.h[0m']"
	../../third-64/protobuf/bin/protoc --cpp_out=proto --proto_path=proto --proto_path=../../app/ecom/im/xbuiltin/output/include/ \
  --proto_path=../../third-64/protobuf/include/ \
  --plugin=protoc-gen-xbuiltin=../../app/ecom/im/xbuiltin/output/bin/xbuiltin-generator \
  --xbuiltin_out \
  proto proto/business_ad.proto

proto/business_ad.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/business_ad.proto[0m']"
	@echo "ALREADY BUILT"

proto/http_server_business_ad.pb.o:proto/business_ad.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/http_server_business_ad.pb.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o proto/http_server_business_ad.pb.o proto/business_ad.pb.cc

proto/http_server.pb.cc \
  proto/http_server.pb.h:proto/http_server.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/http_server.pb.cc \
  proto/http_server.pb.h[0m']"
	../../third-64/protobuf/bin/protoc --cpp_out=proto --proto_path=proto --proto_path=../../app/ecom/im/xbuiltin/output/include/ \
  --proto_path=../../third-64/protobuf/include/ \
  --plugin=protoc-gen-xbuiltin=../../app/ecom/im/xbuiltin/output/bin/xbuiltin-generator \
  --xbuiltin_out \
  proto proto/http_server.proto

proto/http_server.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/http_server.proto[0m']"
	@echo "ALREADY BUILT"

proto/http_server_http_server.pb.o:proto/http_server.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/http_server_http_server.pb.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o proto/http_server_http_server.pb.o proto/http_server.pb.cc

proto/idea_info.pb.cc \
  proto/idea_info.pb.h:proto/idea_info.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/idea_info.pb.cc \
  proto/idea_info.pb.h[0m']"
	../../third-64/protobuf/bin/protoc --cpp_out=proto --proto_path=proto --proto_path=../../app/ecom/im/xbuiltin/output/include/ \
  --proto_path=../../third-64/protobuf/include/ \
  --plugin=protoc-gen-xbuiltin=../../app/ecom/im/xbuiltin/output/bin/xbuiltin-generator \
  --xbuiltin_out \
  proto proto/idea_info.proto

proto/idea_info.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/idea_info.proto[0m']"
	@echo "ALREADY BUILT"

proto/http_server_idea_info.pb.o:proto/idea_info.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/http_server_idea_info.pb.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o proto/http_server_idea_info.pb.o proto/idea_info.pb.cc

proto/phrase_business.pb.cc \
  proto/phrase_business.pb.h:proto/phrase_business.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/phrase_business.pb.cc \
  proto/phrase_business.pb.h[0m']"
	../../third-64/protobuf/bin/protoc --cpp_out=proto --proto_path=proto --proto_path=../../app/ecom/im/xbuiltin/output/include/ \
  --proto_path=../../third-64/protobuf/include/ \
  --plugin=protoc-gen-xbuiltin=../../app/ecom/im/xbuiltin/output/bin/xbuiltin-generator \
  --xbuiltin_out \
  proto proto/phrase_business.proto

proto/phrase_business.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/phrase_business.proto[0m']"
	@echo "ALREADY BUILT"

proto/http_server_phrase_business.pb.o:proto/phrase_business.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/http_server_phrase_business.pb.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o proto/http_server_phrase_business.pb.o proto/phrase_business.pb.cc

proto/plan_info.pb.cc \
  proto/plan_info.pb.h:proto/plan_info.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/plan_info.pb.cc \
  proto/plan_info.pb.h[0m']"
	../../third-64/protobuf/bin/protoc --cpp_out=proto --proto_path=proto --proto_path=../../app/ecom/im/xbuiltin/output/include/ \
  --proto_path=../../third-64/protobuf/include/ \
  --plugin=protoc-gen-xbuiltin=../../app/ecom/im/xbuiltin/output/bin/xbuiltin-generator \
  --xbuiltin_out \
  proto proto/plan_info.proto

proto/plan_info.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/plan_info.proto[0m']"
	@echo "ALREADY BUILT"

proto/http_server_plan_info.pb.o:proto/plan_info.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/http_server_plan_info.pb.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o proto/http_server_plan_info.pb.o proto/plan_info.pb.cc

proto/stop_word.pb.cc \
  proto/stop_word.pb.h:proto/stop_word.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/stop_word.pb.cc \
  proto/stop_word.pb.h[0m']"
	../../third-64/protobuf/bin/protoc --cpp_out=proto --proto_path=proto --proto_path=../../app/ecom/im/xbuiltin/output/include/ \
  --proto_path=../../third-64/protobuf/include/ \
  --plugin=protoc-gen-xbuiltin=../../app/ecom/im/xbuiltin/output/bin/xbuiltin-generator \
  --xbuiltin_out \
  proto proto/stop_word.proto

proto/stop_word.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/stop_word.proto[0m']"
	@echo "ALREADY BUILT"

proto/http_server_stop_word.pb.o:proto/stop_word.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/http_server_stop_word.pb.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o proto/http_server_stop_word.pb.o proto/stop_word.pb.cc

proto/unit_idea.pb.cc \
  proto/unit_idea.pb.h:proto/unit_idea.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/unit_idea.pb.cc \
  proto/unit_idea.pb.h[0m']"
	../../third-64/protobuf/bin/protoc --cpp_out=proto --proto_path=proto --proto_path=../../app/ecom/im/xbuiltin/output/include/ \
  --proto_path=../../third-64/protobuf/include/ \
  --plugin=protoc-gen-xbuiltin=../../app/ecom/im/xbuiltin/output/bin/xbuiltin-generator \
  --xbuiltin_out \
  proto proto/unit_idea.proto

proto/unit_idea.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/unit_idea.proto[0m']"
	@echo "ALREADY BUILT"

proto/http_server_unit_idea.pb.o:proto/unit_idea.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/http_server_unit_idea.pb.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o proto/http_server_unit_idea.pb.o proto/unit_idea.pb.cc

proto/unit_info.pb.cc \
  proto/unit_info.pb.h:proto/unit_info.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/unit_info.pb.cc \
  proto/unit_info.pb.h[0m']"
	../../third-64/protobuf/bin/protoc --cpp_out=proto --proto_path=proto --proto_path=../../app/ecom/im/xbuiltin/output/include/ \
  --proto_path=../../third-64/protobuf/include/ \
  --plugin=protoc-gen-xbuiltin=../../app/ecom/im/xbuiltin/output/bin/xbuiltin-generator \
  --xbuiltin_out \
  proto proto/unit_info.proto

proto/unit_info.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/unit_info.proto[0m']"
	@echo "ALREADY BUILT"

proto/http_server_unit_info.pb.o:proto/unit_info.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/http_server_unit_info.pb.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o proto/http_server_unit_info.pb.o proto/unit_info.pb.cc

proto/user_info.pb.cc \
  proto/user_info.pb.h:proto/user_info.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/user_info.pb.cc \
  proto/user_info.pb.h[0m']"
	../../third-64/protobuf/bin/protoc --cpp_out=proto --proto_path=proto --proto_path=../../app/ecom/im/xbuiltin/output/include/ \
  --proto_path=../../third-64/protobuf/include/ \
  --plugin=protoc-gen-xbuiltin=../../app/ecom/im/xbuiltin/output/bin/xbuiltin-generator \
  --xbuiltin_out \
  proto proto/user_info.proto

proto/user_info.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/user_info.proto[0m']"
	@echo "ALREADY BUILT"

proto/http_server_user_info.pb.o:proto/user_info.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mproto/http_server_user_info.pb.o[0m']"
	$(CXX) -c -I. \
  -I./include/ \
  -I./proto $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o proto/http_server_user_info.pb.o proto/user_info.pb.cc

endif #ifeq ($(shell uname -m),x86_64)


