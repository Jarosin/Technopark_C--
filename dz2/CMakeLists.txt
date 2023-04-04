cmake_minimum_required(VERSION 3.0.0)
project(dz2 VERSION 0.1.0)

include(CTest)
enable_testing()
FILE(GLOB SRCS *.cpp)
add_executable(dz2 ${SRCS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
