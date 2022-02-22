# set minimum cmake version
cmake_minimum_required(VERSION 3.14)

# project name and language
project(example LANGUAGES CXX)

include(CMakePrintHelpers)

foreach(key IN ITEMS NUMBER_OF_LOGICAL_CORES NUMBER_OF_PHYSICAL_CORES IS_64BIT
                     HAS_SSE2 OS_NAME OS_RELEASE)
  # query the item ${key} and save its value in the variable _${key}
  cmake_host_system_information(RESULT _${key} QUERY ${key})
  cmake_print_variables(_${key})
endforeach()

# define executable and its source file
add_executable(example example.cpp)

# let the preprocessor know about the system name
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  target_compile_definitions(example PUBLIC "IS_LINUX")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  target_compile_definitions(example PUBLIC "IS_MACOS")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_compile_definitions(example PUBLIC "IS_WINDOWS")
endif()

# this is here because the config.h will be generated in PROJECT_BINARY_DIR
target_include_directories(example PRIVATE ${PROJECT_BINARY_DIR})
configure_file(config-template.h config.h @ONLY)
