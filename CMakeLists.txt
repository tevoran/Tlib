cmake_minimum_required(VERSION 3.16)
project("Tlib")

#BASICALLY RELEASE MODE
#SET(CMAKE_CXX_FLAGS  "-m64 -Ofast -flto -march=native -funroll-loops")

#DEBUGMODE
#SET(CMAKE_CXX_FLAGS "-g -ggdb -fsanitize=address")
#SET(CMAKE_CXX_FLAGS "-g -Werror -Wall -Wextra")
SET(CMAKE_C_FLAGS "-O0 -g")


#PROFILERMODE
#SET(CMAKE_CXX_FLAGS "-g -pg")

#SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
#SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

include(FindPkgConfig)

include_directories(.)

#creating the tests
file(GLOB_RECURSE "double-linked-list" SRC tests/double-linked-list/*.c)
add_executable(double-linked-list WIN32 ${double-linked-list})

file(GLOB_RECURSE "matrix" SRC tests/math/matrix.c)
add_executable(matrix WIN32 ${matrix})

file(GLOB_RECURSE "vector" SRC tests/math/vector.c)
add_executable(vector WIN32 ${vector})

file(GLOB_RECURSE "float" SRC tests/math/float.c)
add_executable(float WIN32 ${float})