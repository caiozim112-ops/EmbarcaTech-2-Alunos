cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Config Pico SDK
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(PICO_BOARD pico_w CACHE STRING "Board type")

# SDK
include(pico_sdk_import.cmake)
project(arquitetura_modular C CXX ASM)
pico_sdk_init()

# ========== BIBLIOTECAS ==========

# Drivers
add_library(drivers STATIC drivers/led_embutido.c)
target_include_directories(drivers PUBLIC include)
target_link_libraries(drivers pico_stdlib pico_cyw43_arch)

# HAL
add_library(hal STATIC hal/hal_led.c)
target_include_directories(hal PUBLIC include)
target_link_libraries(hal drivers pico_stdlib)

# ========== EXECUTÁVEL ==========
add_executable(arquitetura_modular main.c)
target_include_directories(arquitetura_modular PRIVATE include)
target_link_libraries(arquitetura_modular pico_stdlib hal)

# ========== SAÍDAS ==========
pico_add_extra_outputs(arquitetura_modular)
pico_enable_stdio_usb(arquitetura_modular 1)
pico_enable_stdio_uart(arquitetura_modular 0)
