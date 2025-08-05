cmake_minimum_required(VERSION 4.0)

project(common_lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/common_lib)

add_library(common_lib 
              ./data_structures/ECS.c
              ./data_structures/vector.c
              ./data_structures/dense_hashmap.c)
