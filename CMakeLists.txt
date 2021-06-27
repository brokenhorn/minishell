cmake_minimum_required(VERSION 3.19)
project(minishell C)

set(CMAKE_C_FLAGS "-lreadline")

set(CMAKE_C_STANDARD 99)

add_executable(minishell libft/ft_strncmp.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcpy.c libft/ft_strlen.c
        libft/ft_isalpha.c libft/ft_strlcat.c libft/ft_min_bonus.c minishell.h main.c pwd.c cd.c put_variable.c)