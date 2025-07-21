cmake_minimum_required(VERSION 3.19)
project(hello_world C)

set(CMAKE_C_STANDARD 99)

add_executable(hello_world main.c func.h)