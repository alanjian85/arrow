cmake_minimum_required(VERSION 3.0)
project(arrow CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(arrow INTERFACE)
target_include_directories(arrow INTERFACE include)

add_subdirectory(tests)
