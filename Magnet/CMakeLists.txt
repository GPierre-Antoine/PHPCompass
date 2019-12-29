
# Enable debug symbols by default
# must be done before project() statement
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif ()

configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)
include_directories("${PROJECT_BINARY_DIR}")

set(CSRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(magnet ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CSRC}/symbol.cpp
        ${CSRC}/symbol.h
        ${CSRC}/iterator/target_file_iterator.cpp
        ${CSRC}/iterator/target_file_iterator.h
        )