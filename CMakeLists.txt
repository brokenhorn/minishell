cmake_minimum_required(VERSION 3.19)
project(minishell C)

set(CMAKE_C_FLAGS "-lreadline")

set(CMAKE_C_STANDARD 99)

add_executable(minishell libft/ft_strncmp.c minishell.h main.c pwd.c cd.c)