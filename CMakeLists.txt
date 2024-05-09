cmake_minimum_required(VERSION 3.28)
project(StopWatch C)

set(CMAKE_C_STANDARD 90)

add_executable(StopWatch main.c
        stopwatch.h)
