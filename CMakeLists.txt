cmake_minimum_required(VERSION 4.3)
project(SystemBenchmark)

set(CMAKE_CXX_STANDARD 20)

add_executable(system-benchmark
        main.cpp
        test.h
        benchmark.h
        menu.h
        menu.cpp)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(system-benchmark PRIVATE DEVELOPMENT_BUILD)
endif()