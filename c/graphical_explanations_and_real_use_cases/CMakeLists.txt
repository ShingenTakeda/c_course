cmake_minimum_required(VERSION 4.0)

project(basics)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/graphical_explanations_and_real_use_cases)

add_executable(simple_window simple_window.c)
target_link_libraries(simple_window raylib)
