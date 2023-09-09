cmake_minimum_required(VERSION 3.22)
project(sink)

set(CMAKE_CXX_STANDARD 17)

add_executable(sink main.cpp)
find_package(cppzmq)
target_link_libraries(sink fmt cppzmq)