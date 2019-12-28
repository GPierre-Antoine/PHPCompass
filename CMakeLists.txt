
cmake_minimum_required(VERSION 3.14)
project(PHPCompass)

set(PHPCOMPASS_VERSION_MAJOR 1)
set(PHPCOMPASS_VERSION_MINOR 0)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g -Werror -pedantic -Wno-unused-parameter")

add_subdirectory(${PROJECT_SOURCE_DIR}/Needle)
add_subdirectory(${PROJECT_SOURCE_DIR}/Magnet)
