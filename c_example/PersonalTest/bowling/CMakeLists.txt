cmake_minimum_required(VERSION 3.10)
project(bowling)

set(SOURCES
    src/bowling.c
    src/main.c
    src/bowlingsql.c
    )

# set(CMAKE_C_COMPILER "/usr/bin/gcc")

# set(CMAKE_C_STANDARD 99)
# set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(bowling ${SOURCES})
target_include_directories(bowling PRIVATE include)
# target_include_directories(bookSql Private ${CMAKE_CURRENT_LIST_DIR}/src)

target_include_directories(bowling PRIVATE /usr/include/mysql)
target_link_directories(bowling PRIVATE /usr/lib/mysql)
target_link_libraries(bowling PRIVATE mysqlclient)