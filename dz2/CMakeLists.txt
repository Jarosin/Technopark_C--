cmake_minimum_required(VERSION 3.0.0)
project(dz2 VERSION 0.1.0)

include(CTest)
enable_testing()
include_directories(${dz2_SOURCE_DIR}/inc)
FILE(GLOB SRC src/*.cpp)
add_executable(dz2 ${SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
