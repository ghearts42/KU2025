cmake_minimum_required(VERSION 3.10)
project(day1and2)

set(CMAKE_C_COMPILER "/usr/bin/gcc")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

 set(EXECUTABLES
    c_example/day1and2/infinit.c
)

file(GLOB EXECUTABLES "c_example/day1and2/*.c")

foreach(EXECUTABLE ${EXECUTABLES})
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${EXE_NAME} ${EXECUTABLE})
endforeach()
