cmake_minimum_required(VERSION 3.14)

project(example LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
  # set(CMAKE_BUILD_TYPE "RelWithDebInfo")
  set(CMAKE_BUILD_TYPE "Release")
endif()

# https://github.com/omnisci/omniscidb/blob/master/CMakeLists.txt#L100-L114
macro(set_alternate_linker linker)
  find_program(LINKER_EXECUTABLE ld.${USE_ALTERNATE_LINKER}
               ${USE_ALTERNATE_LINKER})
  if(LINKER_EXECUTABLE)
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU"
       AND "${CMAKE_CXX_COMPILER_VERSION}" VERSION_LESS 12.1.0)
      # add_link_options("-fuse-ld=ld")
    elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang"
           AND "${CMAKE_CXX_COMPILER_VERSION}" VERSION_LESS 12.0.0)
      add_link_options("-ld-path=${USE_ALTERNATE_LINKER}")
    else()
      add_link_options("-fuse-ld=${USE_ALTERNATE_LINKER}")
    endif()
  else()
    set(USE_ALTERNATE_LINKER
        ""
        CACHE STRING "Use alternate linker" FORCE)
  endif()
endmacro()

set(USE_ALTERNATE_LINKER
    "mold"
    CACHE STRING "Use alternate linker. Leave empty
for default; 'gold', 'lld', 'bfd', 'mold'")

if(NOT "${USE_ALTERNATE_LINKER}" STREQUAL "")
  set_alternate_linker(${USE_ALTERNATE_LINKER})
endif()

# message(STATUS "I am here!") message(FATAL_ERROR "I am here and I want the
# configuration to stop here.")

message(STATUS "CMAKE_CXX_COMPILER_ID is ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "CMAKE_CXX_COMPILER_VERSION is ${CMAKE_CXX_COMPILER_VERSION}")

include(CMakePrintHelpers)
cmake_print_variables(CMAKE_CXX_COMPILER_ID CMAKE_CXX_COMPILER_VERSION)
# cmake_print_variables(SOMETHING_UNDEFINED)

# add_executable(hello hello.cpp greeting.cpp greeting.hpp)

add_executable(hello hello.cpp)

add_library(greeting SHARED greeting.cpp greeting.hpp)
# add_library(greeting STATIC greeting.cpp greeting.hpp)

target_link_libraries(hello PRIVATE greeting)
