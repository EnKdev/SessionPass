cmake_minimum_required(VERSION 3.29)
project(libsessionpass VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

find_package(CURL REQUIRED)

add_library(libsessionpass STATIC
        HttpHelper.cpp
        HttpHelper.h
        OtsvCode.cpp
        OtsvCode.h)

target_link_libraries(libsessionpass CURL::libcurl)
