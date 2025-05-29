cmake_minimum_required(VERSION 3.0)
project(OpenCV_part2)

find_package(OpenCV REQUIRED)

file(GLOB SOURCES "*.cpp")
file(GLOB EXTRA_SOURCES "/home/hjpubuntu22045/korea_c/opencv/part2/array.cpp")

foreach(SOURCE ${SOURCES})
    get_filename_component(EXE_NAME ${SOURCE} NAME_WE)
    add_executable(${EXE_NAME} ${SOURCE})
    target_link_libraries(${EXE_NAME} ${OpenCV_LIBS})
endforeach()