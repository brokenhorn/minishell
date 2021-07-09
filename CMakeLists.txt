cmake_minimum_required(VERSION 3.19)
project(minishell_parse C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include")
add_executable(minishell_parse
        src/main.c  src/parse_tokens.c
        libft/ft_strlen.c
        libft/ft_strtrim.c
        libft/ft_strchr.c
        libft/ft_strjoin.c
        libft/ft_strnstr.c
        libft/ft_strncmp.c
        libft/ft_strdup.c
        libft/ft_strlcpy.c
        libft/ft_isalpha.c
        libft/ft_split.c
        libft/ft_isdigit.c
        libft/ft_itoa.c
        libft/ft_nbrlen_bonus.c
        libft/ft_lstadd_back.c
        libft/ft_lstclear.c
        libft/ft_lstnew.c
        src/utils2.c
        libft/ft_isalnum.c
        src/check_valid.c
        src/put_variable.c
        src/cd.c
        src/export.c
        src/utils_put_variable.c
        src/utils_export.c
        src/parse_search_bin.c
        src/utils.c
        src/redirect.c
        src/launch_command.c
        src/utils_list.c
        src/path_search_bin_utils.c
        src/parse_utils.c
        src/sig_utils.c src/utils_launch.c src/parse_strtok_utils.c
        src/utils_launch_pipe.c src/utils_search_path.c src/utils_main.c src/utils3.c
        src/unset.c)