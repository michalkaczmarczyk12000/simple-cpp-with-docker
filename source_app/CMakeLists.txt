cmake_minimum_required(VERSION 3.22)
project(source)

set(CMAKE_CXX_STANDARD 17)

add_executable(source main.cpp)
find_package(cppzmq)
target_link_libraries(source fmt cppzmq)