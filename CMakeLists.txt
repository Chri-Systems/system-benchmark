cmake_minimum_required(VERSION 4.3)
project(benchmark)

set(CMAKE_CXX_STANDARD 20)

add_executable(benchmark main.cpp
        test.h
        benchmark.h)
