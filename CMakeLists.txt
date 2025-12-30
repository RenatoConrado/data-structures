cmake_minimum_required(VERSION 3.25.0)
project(data-structure VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(include)

add_executable(funcLinkedList src/linked-list/function.cpp)
add_executable(classLinkedList src/linked-list/class.cpp)

add_executable(deque src/deque.cpp)
