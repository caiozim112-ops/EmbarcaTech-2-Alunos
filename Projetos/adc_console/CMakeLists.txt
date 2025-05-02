# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(adc_console C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Adicione as bibliotecas
add_library(drivers STATIC drivers/temperature_sensor.c)
target_include_directories(drivers PUBLIC include)
target_link_libraries(drivers pico_stdlib hardware_adc)

add_library(hal STATIC
    hal/ler_temperatura.c)

# Add executable. Default name is the project name, version 0.1
# Enable stdio
add_executable(adc_console
        adc_console.c
        )

add_library(
    run_tests
    test/test_hal_temperature.c
    src/unity.c
    )
include_directories(include src)

target_link_libraries(adc_console pico_stdlib hardware_adc drivers hal)

# Adicione os includes padrão ao build
target_include_directories(adc_console PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_include_directories(run_tests PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# create map/bin/hex file etc.
pico_add_extra_outputs(adc_console)

# add url via pico_set_program_url
pico_enable_stdio_uart(adc_console 0)
pico_enable_stdio_usb(adc_console 1)

# add_executable(run_tests
#     test/test_hal_temperature.c
#     src/unity.c
# )
# target_include_directories(run_tests PRIVATE include src)