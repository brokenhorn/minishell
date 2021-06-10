#ifndef MINISHELL_H
#define MINISHELL_H

#include "libft/libft.h"

#include "stdlib.h"
#include "stdint.h"
#include "unistd.h"
#include "stdio.h"
#include "limits.h"
#include "sys/wait.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "readline/readline.h"
#include "readline/history.h"
#include "signal.h"
#include "dirent.h"
#include "errno.h"

#define ECHO 7
#define CD 1
#define EXPORT 2
#define UNSET 3
#define PWD 4
#define ENV 5
#define EXIT 6

#define B1 10
#define S1 11
#define B2 12
#define S2 13

typedef struct	s_command
{
	int			*command;
	int 		*flag;
	char		**text;
	int			*redirect;
	int			*file;
}				t_command;

typedef struct	s_history
{
	char 			*text;
	struct s_list	*prev;
	struct s_list	*next;
}				t_history;

#endif
