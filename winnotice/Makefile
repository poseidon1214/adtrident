#COMAKE2 edit-mode: -*- Makefile -*-
####################64Bit Mode####################
ifeq ($(shell uname -m),x86_64)
CC=gcc
CXX=g++
CXXFLAGS=
CFLAGS=
CPPFLAGS=-g \
  -O2 \
  -pipe \
  -W \
  -Wall \
  -Werror \
  -fPIC \
  -Wno-deprecated \
  --std=c++11 \
  -D__const__=
INCPATH=
DEP_INCPATH=-I../../../lib2-64/ullib \
  -I../../../lib2-64/ullib/include \
  -I../../../lib2-64/ullib/output \
  -I../../../lib2-64/ullib/output/include \
  -I../../../op/oped/noah/webfoot/naming-lib \
  -I../../../op/oped/noah/webfoot/naming-lib/include \
  -I../../../op/oped/noah/webfoot/naming-lib/output \
  -I../../../op/oped/noah/webfoot/naming-lib/output/include \
  -I../../../public/baidu-rpc \
  -I../../../public/baidu-rpc/include \
  -I../../../public/baidu-rpc/output \
  -I../../../public/baidu-rpc/output/include \
  -I../../../public/bthread \
  -I../../../public/bthread/include \
  -I../../../public/bthread/output \
  -I../../../public/bthread/output/include \
  -I../../../public/bvar \
  -I../../../public/bvar/include \
  -I../../../public/bvar/output \
  -I../../../public/bvar/output/include \
  -I../../../public/common \
  -I../../../public/common/include \
  -I../../../public/common/output \
  -I../../../public/common/output/include \
  -I../../../public/iobuf \
  -I../../../public/iobuf/include \
  -I../../../public/iobuf/output \
  -I../../../public/iobuf/output/include \
  -I../../../public/murmurhash \
  -I../../../public/murmurhash/include \
  -I../../../public/murmurhash/output \
  -I../../../public/murmurhash/output/include \
  -I../../../public/noah/giano-lib/release/baas-lib-c \
  -I../../../public/noah/giano-lib/release/baas-lib-c/include \
  -I../../../public/noah/giano-lib/release/baas-lib-c/output \
  -I../../../public/noah/giano-lib/release/baas-lib-c/output/include \
  -I../../../public/protobuf-json \
  -I../../../public/protobuf-json/include \
  -I../../../public/protobuf-json/output \
  -I../../../public/protobuf-json/output/include \
  -I../../../third-64/boost \
  -I../../../third-64/boost/include \
  -I../../../third-64/boost/output \
  -I../../../third-64/boost/output/include \
  -I../../../third-64/gflags \
  -I../../../third-64/gflags/include \
  -I../../../third-64/gflags/output \
  -I../../../third-64/gflags/output/include \
  -I../../../third-64/gtest \
  -I../../../third-64/gtest/include \
  -I../../../third-64/gtest/output \
  -I../../../third-64/gtest/output/include \
  -I../../../third-64/leveldb \
  -I../../../third-64/leveldb/include \
  -I../../../third-64/leveldb/output \
  -I../../../third-64/leveldb/output/include \
  -I../../../third-64/libevent \
  -I../../../third-64/libevent/include \
  -I../../../third-64/libevent/output \
  -I../../../third-64/libevent/output/include \
  -I../../../third-64/openssl \
  -I../../../third-64/openssl/include \
  -I../../../third-64/openssl/output \
  -I../../../third-64/openssl/output/include \
  -I../../../third-64/protobuf \
  -I../../../third-64/protobuf/include \
  -I../../../third-64/protobuf/output \
  -I../../../third-64/protobuf/output/include \
  -I../../../third-64/snappy \
  -I../../../third-64/snappy/include \
  -I../../../third-64/snappy/output \
  -I../../../third-64/snappy/output/include

#============ CCP vars ============
CCHECK=@ccheck.py
CCHECK_FLAGS=
PCLINT=@pclint
PCLINT_FLAGS=
CCP=@ccp.py
CCP_FLAGS=


#COMAKE UUID
COMAKE_MD5=c37fccb64c6090fbdda409d4b5b45db6  COMAKE


.PHONY:all
all:comake2_makefile_check win_notice 
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
	rm -rf win_notice
	rm -rf ./output/bin/win_notice
	rm -rf ./win_notice.pb.cc
	rm -rf ./win_notice.pb.h
	rm -rf ./win_notice_win_notice.pb.o
	rm -rf win_notice_win_notice.o

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

win_notice:win_notice_win_notice.pb.o \
  win_notice_win_notice.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mwin_notice[0m']"
	$(CXX) win_notice_win_notice.pb.o \
  win_notice_win_notice.o -Xlinker "-("  ../../../lib2-64/ullib/lib/libullib.a \
  ../../../op/oped/noah/webfoot/naming-lib/output/lib/libwebfoot_naming.a \
  ../../../public/baidu-rpc/libbdrpc.a \
  ../../../public/bthread/libbthread.a \
  ../../../public/bvar/libbvar.a \
  ../../../public/common/libbase.a \
  ../../../public/iobuf/libiobuf.a \
  ../../../public/murmurhash/libmurmurhash3.a \
  ../../../public/noah/giano-lib/release/baas-lib-c/libbaas_interface.a \
  ../../../public/protobuf-json/libjson-pb.a \
  ../../../third-64/boost/lib/libboost_context.a \
  ../../../third-64/gflags/lib/libgflags.a \
  ../../../third-64/gflags/lib/libgflags_nothreads.a \
  ../../../third-64/gtest/lib/libgmock.a \
  ../../../third-64/gtest/lib/libgmock_main.a \
  ../../../third-64/gtest/lib/libgtest.a \
  ../../../third-64/gtest/lib/libgtest_main.a \
  ../../../third-64/leveldb/lib/libleveldb.a \
  ../../../third-64/libevent/lib/libevent.a \
  ../../../third-64/libevent/lib/libevent_core.a \
  ../../../third-64/libevent/lib/libevent_extra.a \
  ../../../third-64/libevent/lib/libevent_openssl.a \
  ../../../third-64/libevent/lib/libevent_pthreads.a \
  ../../../third-64/openssl/lib/libcrypto.a \
  ../../../third-64/openssl/lib/libssl.a \
  ../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../third-64/protobuf/lib/libprotoc.a \
  ../../../third-64/snappy/lib/libsnappy.a -lpthread \
  -lrt \
  -ldl \
  -lz -Xlinker "-)" -o win_notice
	mkdir -p ./output/bin
	cp -f win_notice ./output/bin

./win_notice.pb.cc \
  ./win_notice.pb.h:win_notice.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m./win_notice.pb.cc \
  ./win_notice.pb.h[0m']"
	../../../third-64/protobuf/bin/protoc --cpp_out=./ --proto_path=./  win_notice.proto

win_notice.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mwin_notice.proto[0m']"
	@echo "ALREADY BUILT"

./win_notice_win_notice.pb.o:./win_notice.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m./win_notice_win_notice.pb.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ./win_notice_win_notice.pb.o ./win_notice.pb.cc

win_notice_win_notice.o:win_notice.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mwin_notice_win_notice.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o win_notice_win_notice.o win_notice.cpp

endif #ifeq ($(shell uname -m),x86_64)


