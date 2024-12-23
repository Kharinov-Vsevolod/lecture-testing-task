cmake_minimum_required(VERSION 3.10)
project(stack)

add_library(stack stack.c)

add_executable(main main.c)
target_link_libraries(main stack)

add_executable(test_stack test_stack.c)
target_link_libraries(test_stack stack)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage -g")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

add_executable(benchmark_push_pop benchmark_push_pop.c)
target_link_libraries(benchmark_push_pop stack)