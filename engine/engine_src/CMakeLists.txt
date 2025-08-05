cmake_minimum_required(VERSION 4.0)

project(common_lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/debug/)

add_executable(game_base
               debug_main.c)
target_link_libraries(game_base raylib common_lib)
