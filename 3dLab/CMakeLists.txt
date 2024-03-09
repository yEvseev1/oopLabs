cmake_minimum_required(VERSION 3.24)
project(oop_lab3)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(oop_lab3 main.cpp src/Point.cpp src/Triangle.cpp src/Hexagon.cpp src/Octagon.cpp src/FigureList.cpp)
add_executable(oop_lab3_test tests/test.cpp src/Point.cpp src/Triangle.cpp src/Hexagon.cpp src/Octagon.cpp src/FigureList.cpp)

target_include_directories(oop_lab3_test PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(oop_lab3_test PRIVATE gtest gtest_main)
