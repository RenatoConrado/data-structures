cmake_minimum_required(VERSION 3.25.0)
project(data-structure VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(include)
add_executable(funcLinkedList src/linked-list/function.cpp)
add_executable(classLinkedList src/linked-list/class.cpp)
add_executable(deque src/deque.cpp)

# --- Google Test ---
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS tests/**.cpp)
add_executable(all_tests ${TEST_SOURCES})

target_link_libraries(all_tests GTest::gtest GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(all_tests)
# --- Google Test ---
