cmake_minimum_required(VERSION 3.5.1)
project(ACM_ICPC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ACM-ICPC/1309.cpp)

add_executable(ACM_ICPC ${SOURCE_FILES})