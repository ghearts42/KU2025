cmake_minimum_required(VERSION 3.10)
project(bookSql)

set(SOURCES
    src/bookSql.c
    src/main.c
    )

# set(CMAKE_C_COMPILER "/usr/bin/gcc")

# set(CMAKE_C_STANDARD 99)
# set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(bookSql ${SOURCES})
target_include_directories(bookSql PRIVATE include)
# target_include_directories(bookSql Private ${CMAKE_CURRENT_LIST_DIR}/src)

target_include_directories(bookSql PRIVATE /usr/include/mysql)
target_link_directories(bookSql PRIVATE /usr/lib/mysql)
target_link_libraries(bookSql PRIVATE mysqlclient)