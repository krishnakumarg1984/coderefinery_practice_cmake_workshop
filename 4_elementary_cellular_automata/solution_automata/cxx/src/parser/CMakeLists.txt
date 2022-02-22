add_library(parser)

target_sources(parser
  PUBLIC
    parser.hpp
  PRIVATE
    # parser.cpp
    ${CMAKE_CURRENT_LIST_DIR}/parser.cpp
  )

target_include_directories(parser
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )
