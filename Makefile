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
           			utils_put_variable.c \
           			sig_utils.c \
           			path_search_bin_utils.c


SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

SRCS = $(SRC)

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libft
	@echo "\n"
	@echo "\033[0;32mCompiling minishell..."
	@make -C libft/
	cp libft/libft.a .
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@${CC} -g ${CFLAGS} -c $< -o $@

clean:
	@echo "\033[0;31mCleaning libft..."
	@make clean -C libft/
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31mCleaning libft..."
	@make fclean -C libft/
	@echo "\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

test: all
	./$(NAME)

norm:
	norminette $(SRC) includes/$(HEADER)

.PHONY: clean fclean re test norm