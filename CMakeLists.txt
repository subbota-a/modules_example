cmake_minimum_required(VERSION 3.28)
project(modules_example LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
enable_testing()

add_executable(modules_example)

target_sources(modules_example
    PUBLIC
    main.cpp

    PUBLIC FILE_SET HEADERS FILES
    modules/geometry.h

    PUBLIC FILE_SET CXX_MODULES FILES
    modules/printing.cppm
    modules/calculating.cppm
    modules/geometry.cppm
)
if (MSVC)
    target_compile_options(modules_example PRIVATE "/utf-8")
endif ()

add_test(NAME modules_example COMMAND modules_example)
