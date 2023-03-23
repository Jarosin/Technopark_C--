cmake_minimum_required(VERSION 3.0.0)
project(dz1 VERSION 0.1.0)

include(CTest)
enable_testing()
include_directories(${dz1_SOURCE_DIR}/inc)
add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})