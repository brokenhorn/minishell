NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I includes/ -I libft/

LIBFT = -L. -lft -lreadline

SRC_DIR = src/

SRC_LIST =	main.c \
			cd.c \
			check_valid.c \
			export.c \
			launch_command.c \
			parse_search_bin.c \
			parse_tokens.c \
			put_variable.c \
           	utils.c \
           	utils2.c \
           	utils_list.c \
           	utils_export.c \
           	utils_launch.c\
           	utils_put_variable.c \
           	sig_utils.c \
           	path_search_bin_utils.c\
           	parse_strtok_utils.c\
           	redirect.c\
           	parse_utils.c\
           	utils_launch_pipe.c\


SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

SRCS = $(SRC)

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libft
	@make -C libft/
	cp libft/libft.a .
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	${CC} -g ${CFLAGS} -c $< -o $@

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean:
	make fclean -C libft/
	rm -f $(OBJ)
	rm -f $(NAME)
	rm -f libft.a

re: fclean all

test: all
	./$(NAME)

norm:
	norminette $(SRC) includes/$(HEADER)

.PHONY: clean fclean re test norm