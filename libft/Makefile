SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace_bonus.c ft_max_bonus.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_min_bonus.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_power_bonus.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_nbrlen_bonus.c ft_split.c

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

BOBJS	= ${BONUS:.c=.o}

NAME		= libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -I libft.h

.c.o:		${CC} ${CFLAGS} $< -o ${<:.c-.o}

$(NAME):		${OBJS}
			ar rc ${NAME} ${OBJS}

all: 		${NAME}

bonus:		${OBJS} ${BOBJS}
		ar rc ${NAME} ${OBJS} ${BOBJS}

clean:
			rm -f ${OBJS} ${BOBJS}

fclean:		clean
			rm -f ${NAME}

re: 		fclean all
