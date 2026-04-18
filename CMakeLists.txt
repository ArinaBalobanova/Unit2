cmake_minimum_required(VERSION 3.10)
project(StackProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

find_package(GTest REQUIRED)

add_executable(stack_tests tests.cpp)
target_link_libraries(stack_tests GTest::gtest GTest::gtest_main pthread)
target_include_directories(stack_tests PRIVATE .)

enable_testing()
add_test(NAME StackTests COMMAND stack_tests)
