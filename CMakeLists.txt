cmake_minimum_required(VERSION 3.25.0)
project(data-structure VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
#set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(funcLinkedList src/linked-list/function.cpp)

add_executable(classLinkedList src/linked-list/class.cpp)
