cmake_minimum_required(VERSION 3.6)
project(virtual_machine)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

set(SOURCE_FILES main.c)

add_executable(virtual_machine ${SOURCE_FILES})
target_link_libraries(virtual_machine ${CMAKE_SOURCE_DIR}/libft/libft.a)