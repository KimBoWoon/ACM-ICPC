cmake_minimum_required(VERSION 3.6)
project(ACM_ICPC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    2193.cpp)

add_executable(ACM_ICPC ${SOURCE_FILES})