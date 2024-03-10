cmake_minimum_required(VERSION 3.10)
project(Lr2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(main main.cpp Six.cpp)
add_executable(test tests.cpp Six.cpp)

target_include_directories(test PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(test PRIVATE gtest gtest_main)