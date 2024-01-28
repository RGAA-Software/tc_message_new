cmake_minimum_required(VERSION 3.22)
project(tc_message)

set(CMAKE_CXX_STANDARD 20)

find_package(Protobuf REQUIRED)

if(WIN32 OR APPLE OR UNIX)
    protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS tc_message.proto)

    add_library(tc_message library.cpp ${PROTO_SRCS} ${PROTO_HDRS})
    target_link_libraries(tc_message protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)
elseif(ANDROID)
    add_library(tc_message library.cpp tc_message.pb.cc)
    target_link_libraries(tc_message protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)
endif()