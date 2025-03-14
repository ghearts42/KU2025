cmake_minimum_required(VERSION 3.10)
project(carSerial)

# include_directories((${CMAKE_CURRENT_LIST_DIR}/include)) #필요한 폴더가 있을 때

set(SOURCES
main.c
serial.c
)

add_executable(carSerial ${SOURCES})
