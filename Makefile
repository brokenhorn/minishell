NAME = minishell

CC = gcc

FLAGS =	-Wall -Werror -Wextra

LIBFT = libft/libft.a

INCLUDES =	-I libft/ -I

SRC_DIR =	src/
SRC_LIST =	main.c \
			cd.c \
			check_valid.c \
			export.c \
			launch_command.c \
			parse.c \
			parse_search_bin.c \
			parse_tokens.c \
			put_variable.c \
			utils.c \
			utils2.c \
			utils_list.c \
			utils_export.c \
			utils_put_variable.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))
OBJ = $(SRC:.c=.o)

.c.o:		${CC} ${CFLAGS} $< -o ${<:.c-.o}

all: $(NAME)
$(NAME): $(OBJ)
		cd libft && make
		ar rc $(NAME) $(OBJ)
clean:
		rm -rf $(OBJ)
		cd libft && make clean
fclean: clean
		rm -rf $(NAME)
		cd libft && make fclean
re: fclean all
.PHONY:	all re fclean clean