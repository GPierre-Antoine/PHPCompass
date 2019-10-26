cmake_minimum_required(VERSION 3.14)

project(PHPCompass)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_subdirectory(${PROJECT_SOURCE_DIR}/parser/)
include_directories("${CMAKE_CURRENT_BINARY_DIR}/parser")
set(EXTRA_LIBS ${EXTRA_LIBS} parser.so)


add_executable(Compass main.cpp)
target_link_libraries(Compass ${EXTRA_LIBS})