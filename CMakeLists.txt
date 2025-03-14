cmake_minimum_required(VERSION 3.10)
project(MainProject)

# 내부 CMakeLists.txt 포함

add_subdirectory(sqlquery)
add_subdirectory(c_example/day1and2)
# add_subdirectory(c_example/day3)
# add_subdirectory(c_example/day4)
add_subdirectory(c_example/part3/CarSerial)
# add_subdirectory(c_example/PersonalTest)
# include(sqlquery/CMakeLists.txt)
# include(c_example/day1and2/CMakeLists.txt)
# include(c_example/part3/CMakeLists.txt)