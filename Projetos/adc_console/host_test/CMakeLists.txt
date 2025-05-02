cmake_minimum_required(VERSION 3.13)
project(run_tests C)

set(CMAKE_C_STANDARD 11)

add_executable(run_tests
    ../test/test_hal_temperature.c
    ../hal/ler_temperatura.c
    ../src/unity.c
)

target_include_directories(run_tests PRIVATE
    ../include
    ../src
)
