#ifndef MINISHELL_H
#define MINISHELL_H

#include "libft/libft.h"

#include "stdlib.h"
#include "stdint.h"
#include "string.h"
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

#define CD 1
#define EXPORT 2
#define UNSET 3
#define PWD 4
#define ENV 5
#define EXIT 6
#define ECHO 7

#define B1 10
#define S1 11
#define B2 12
#define S2 13
#define PIPE 14

typedef struct	s_command
{
	int			command;
	int 		flag;
	char		**argv;
	char		*file;
	struct s_command *next;
}				t_command;

typedef struct	s_parse
{
	int		opn;
	int		qu;
	char 	*line_cp;
}				t_parse;

typedef struct	s_info
{
	char 		*text;
	char		**envp;
	t_command	*command;
	t_parse		*parse;
}				t_info;

void	error(t_info *info, char *str, char *help);
char	*put_variable(char *str, char **envp);
void	cd(t_info *info, char **envp);
void	parse(t_info *info);
void  	search_bin(t_info *info);
void	free_2arr(char **arr);
int		launch_command(t_info *info);
void	my_exit(t_info *info);
void	check_valid(t_info *info, char *str);
void	export(t_info *info, char **text);
int		ft_check_space(char *str);
void	free_info(t_info *info);
void	start_point(char **envp);
int		main(int argc, char **argv, char **envp);
char	**sort_export(char **str, int n);
char	**malloc_envp(char **envp);
void	add_variable_new(t_info *info, char *name, char *value, int i);
char	*new_variable(char *name, char *value);

char	*no_quotes(char *str);
char	*make_new_str(char *str, char *new_str, char *variable, char **ptr);
int		len_str(char *str);

#endif
