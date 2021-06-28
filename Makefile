NAME = minishell

CC = gcc

FLAGS =	-Wall -Werror -Wextra

LIBFT = libft/libft.a

INCLUDES =	-I libft/ -I

SRC_DIR =	src/
SRC_LIST =	main.c \
			parse_search_bin.c \
			put_variable.c \
			pwd.c \
			cd.c \
			utils.c

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