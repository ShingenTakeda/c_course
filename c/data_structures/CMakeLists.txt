cmake_minimum_required(VERSION 4.0)

project(data_structures)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/data_structures)


add_executable(stack stack.c)
add_executable(queue queue.c)
add_executable(linked_list linked_list.c)
add_executable(dynamic_array dynamic_array.c)
add_executable(hash_table hash_table.c)
