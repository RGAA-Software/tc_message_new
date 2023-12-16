cmake_minimum_required(VERSION 3.26)
project(tc_message)

set(CMAKE_CXX_STANDARD 20)

find_package(Protobuf REQUIRED)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS tc_message.proto)

add_library(tc_message library.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(tc_message protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)
