cmake_minimum_required(VERSION 2.8)

project(OSSApp)
message(STATUS "Hello OSSApp")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)
##add_definitions("-Wall -g")

option(TARS_MYSQL "option for mysql" OFF)
option(TARS_SSL "option for ssl" OFF)
option(TARS_HTTP2 "option for http2" OFF)

if(WIN32)
    include (c:\\tars\\cpp\\makefile\\tars-tools.cmake)
else()
    include (/usr/local/tars/cpp/makefile/tars-tools.cmake)
endif()

set(TARS_WEB_HOST "http://127.0.0.1:4001")

include_directories(/usr/local/tars/cpp/thirdparty/include)

link_directories(/usr/local/tars/cpp/thirdparty/lib)

##message("PROJECT_BINARY_DIR:         ${PROJECT_BINARY_DIR}")
##LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)
##link_directories(${PROJECT_BINARY_DIR}/lib)

add_subdirectory(src)