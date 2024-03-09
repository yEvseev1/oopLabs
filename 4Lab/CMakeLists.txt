cmake_minimum_required(VERSION 3.24)
project(oop_lab4)

set(CMAKE_CXX_STANDARD 17)


include_directories(include)

add_executable(oop_lab4 main.cpp)
add_executable(oop_lab4_test tests/test.cpp)

target_include_directories(oop_lab4_test PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(oop_lab4_test PRIVATE gtest gtest_main)
