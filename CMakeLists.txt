cmake_minimum_required(VERSION 3.13)
project(lab1)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


add_executable(lab1 main.cpp Test/Test_double.cpp Test/List.h )
target_link_libraries(lab1 gtest gtest_main)
