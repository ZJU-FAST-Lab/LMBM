cmake_minimum_required(VERSION 2.8.3)
project(lmbm)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g -fPIC")

include_directories(${PROJECT_SOURCE_DIR}/lmbm)

add_library(lmbm SHARED IMPORTED)

set_target_properties(lmbm PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/lmbm/lmbm.so)

add_executable(lmbm_example lmbm_example.cpp)

target_link_libraries(lmbm_example lmbm)
