cmake_minimum_required(VERSION 3.22)
project(worker)

set(CMAKE_CXX_STANDARD 17)

add_executable(worker main.cpp)
find_package(cppzmq)
target_link_libraries(worker fmt cppzmq)