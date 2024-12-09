cmake_minimum_required(VERSION 3.25)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

find_package(benchmark REQUIRED)

include_directories(.)
#include_directories(strings)

add_subdirectory(benchmark/strings)
