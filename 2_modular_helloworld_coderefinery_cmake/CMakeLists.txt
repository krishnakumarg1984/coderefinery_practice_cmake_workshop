cmake_minimum_required(VERSION 3.14)

project(example LANGUAGES CXX)

# add_executable(hello hello.cpp greeting.cpp greeting.hpp)

message(STATUS "I am here!")
# message(FATAL_ERROR "I am here and I want the configuration to stop here.")

message(STATUS "CMAKE_CXX_COMPILER_ID is ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "CMAKE_CXX_COMPILER_VERSION is ${CMAKE_CXX_COMPILER_VERSION}")

include(CMakePrintHelpers)
cmake_print_variables(CMAKE_CXX_COMPILER_ID CMAKE_CXX_COMPILER_VERSION)
cmake_print_variables(CMAKE_CXX_COMPILER_ID)
cmake_print_variables(CMAKE_CXX_COMPILER_VERSION)
cmake_print_variables(SOMETHING_UNDEFINED)


add_executable(hello hello.cpp)

add_library(greeting SHARED greeting.cpp greeting.hpp)
# add_library(greeting STATIC greeting.cpp greeting.hpp)

target_link_libraries(hello PRIVATE greeting)
