
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})

find_package(BISON)
find_package(FLEX)

add_definitions(-DYY_NO_UNPUT)

BISON_TARGET(parser ${CMAKE_CURRENT_SOURCE_DIR}/parser/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.yy.cpp)
FLEX_TARGET(scanner ${CMAKE_CURRENT_SOURCE_DIR}/parser/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.ll.cpp)
ADD_FLEX_BISON_DEPENDENCY(scanner parser)
add_definitions(-DLLDEBUG)
add_library(parser.so ${BISON_parser_OUTPUTS} ${FLEX_scanner_OUTPUTS})


set(EXTRA_LIBS ${EXTRA_LIBS} parser.so)


add_executable(Compass main.cpp src/files/file_info.cpp src/files/file_info_manager.cpp src/files/file_info_manager.h)
target_link_libraries(Compass ${EXTRA_LIBS})