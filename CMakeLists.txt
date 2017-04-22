cmake_minimum_required(VERSION 2.8.4)
project(program)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

#set(SOURCE_FILES iteration.c)
#set(SOURCE_FILES linkedlist.c)
set(SOURCE_FILES test.c)
#set(SOURCE_FILES scope1.c scope2.c)
add_executable(program ${SOURCE_FILES})