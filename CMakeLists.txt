cmake_minimum_required(VERSION 3.22)
project(tc_message)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR}/tc_3rdparty/asio2/include)
include_directories(${CMAKE_SOURCE_DIR}/tc_3rdparty/asio2/3rd)

if(ANDROID)
    find_package(Protobuf REQUIRED)
    message("==> Protobuf libraries: ${Protobuf_LIBRARIES}")
    protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS tc_message.proto tc_file_transfer.proto tc_signaling_message.proto)
    add_library(tc_message
            ${CMAKE_CURRENT_BINARY_DIR}/tc_message.pb.cc
            ${CMAKE_CURRENT_BINARY_DIR}/tc_file_transfer.pb.cc
            ${CMAKE_CURRENT_BINARY_DIR}/tc_signaling_message.pb.cc
            proto_message_maker.cpp
            msg_answer_cbk.cpp
            )
    target_link_libraries(tc_message protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)

elseif(WIN32 OR APPLE OR UNIX)
    protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS tc_message.proto tc_service_message.proto tc_file_transfer.proto tc_signaling_message.proto)

    message("Protobuf of tc_message.proto: ${PROTO_SRCS}")

    add_library(tc_message proto_message_maker.cpp msg_answer_cbk.cpp
            ${CMAKE_CURRENT_BINARY_DIR}/tc_message.pb.cc
            ${CMAKE_CURRENT_BINARY_DIR}/tc_service_message.pb.cc
            ${CMAKE_CURRENT_BINARY_DIR}/tc_file_transfer.pb.cc
            ${CMAKE_CURRENT_BINARY_DIR}/tc_signaling_message.pb.cc
    )
    target_link_libraries(tc_message libprotobuf)

endif()