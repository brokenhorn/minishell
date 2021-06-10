cmake_minimum_required(VERSION 3.19)
project(minishell C)

set(CMAKE_C_FLAGS "-lreadline")

set(CMAKE_C_STANDARD 99)

add_executable(minishell minishell.h main.c)