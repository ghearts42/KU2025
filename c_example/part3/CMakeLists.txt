cmake_minimum_required(VERSION 3.10)
project(part3)

set(CMAKE_C_COMPILER "/usr/bin/gcc")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB EXECUTABLES "c_example/part3/*.c")

foreach(EXECUTABLE ${EXECUTABLES})
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${EXE_NAME} ${EXECUTABLE})
endforeach()
