cmake_minimum_required(VERSION 3.25)
project(calendar C)

set(CMAKE_C_STANDARD 11)

add_executable(calendar main.c parti_1.c parti_1.h parti_2.c parti_2.h timer.c timer.h)
