cmake_minimum_required(VERSION 3.19)
project(minishell_parse C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-lreadline")
add_executable(minishell_parse main.c  parse_tokens.c
        libft/ft_split.c
        libft/ft_strlen.c
        libft/ft_strtrim.c
        libft/ft_strchr.c
        libft/ft_strjoin.c
        libft/ft_strnstr.c
        libft/ft_strncmp.c
        libft/ft_strdup.c
        libft/ft_strlcpy.c
        libft/ft_isalpha.c
        put_variable.c
        cd.c
        parse_search_bin.c utils.c launch_command.c)