cmake_minimum_required(VERSION 3.22)
project(tc_message)

set(CMAKE_CXX_STANDARD 20)

find_package(Protobuf REQUIRED)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

if(ANDROID)
    protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS tc_message.proto)
    add_library(tc_message ${CMAKE_CURRENT_BINARY_DIR}/tc_message.pb.cc proto_message_maker.cpp)
    target_link_libraries(tc_message protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)
elseif(WIN32 OR APPLE OR UNIX)
    protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS tc_message.proto tc_service_message.proto)

    message("Protobuf of tc_message.proto: ${PROTO_SRCS}")
    add_library(tc_proto_message ${CMAKE_CURRENT_BINARY_DIR}/tc_message.pb.cc ${CMAKE_CURRENT_BINARY_DIR}/tc_service_message.pb.cc)
    target_link_libraries(tc_proto_message protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)

    add_library(tc_message proto_message_maker.cpp)
    target_link_libraries(tc_message tc_proto_message)

    #add_custom_command(TARGET tc_message POST_BUILD
    #        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/tc_message.pb.h"  "${CMAKE_CURRENT_SOURCE_DIR}"
    #        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/tc_message.pb.cc"  "${CMAKE_CURRENT_SOURCE_DIR}"
    #)
endif()