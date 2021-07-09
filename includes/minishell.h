#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# include "stdlib.h"
# include "stdint.h"
# include "string.h"
# include "unistd.h"
# include "stdio.h"
# include "limits.h"
# include "sys/wait.h"
# include "sys/stat.h"
# include "sys/types.h"
# include "readline/readline.h"
# include "readline/history.h"
# include "signal.h"
# include "dirent.h"
# include "errno.h"
# include <fcntl.h>

# define B1 10
# define S1 11
# define B2 12
# define S2 13
# define PIPE 14

typedef struct	s_sig
{
	int				sigint;
}				t_sig;

extern t_sig g_sig;

typedef struct s_command
{
	int					command;
	int					flag;
	char				**argv;
	char				*file;
	struct s_command	*next;
}				t_command;

typedef struct s_parse
{
	int		opn;
	int		qu;
	char	*line_cp;
}				t_parse;

typedef struct s_info
{
	char		*text;
	char		**envp;
	t_command	*command;
	t_parse		*parse;
	int			exit_status;
	char		*err_msg;
	int			err_check;
	int			wait_count;
	int			dup_in;
	int			dup_out;
	int			fd_redirect;
	t_list		*pipe_list;
	int			parse_i;
}				t_info;

void		error(t_info *info, char *str, char *help);
char		*put_variable(t_info *info, char *str, char **envp);
void		cd(t_info *info, char **envp);
void		parse(t_info *info);
void		search_bin(t_info *info);
void		free_2arr(char **arr);
int			launch_command(t_info *info);
void		my_exit(t_info *info);
int			check_valid(t_info *info, char *str);
void		export(t_info *info, char **text);
int			ft_check_space(char *str);
void		free_info(t_info *info);
void		start_point(char **envp);
int			main(int argc, char **argv, char **envp);
t_command	*ft_new_com(void);
void		ft_com_add_back(t_command **lst, t_command *new);
char		**sort_export(char **str, int n);
char		**malloc_envp(char **envp);
void		add_variable_new(t_info *info, char *name, char *value, int i);
char		*no_quotes(char *str);
char		*make_new_str(char *str, char *new_str, char *variable, char **ptr);
int			len_str(char *str, char *ptr);
char		*new_variable(char *name, char *value);
char		*take_dir(char *str, char **end_path);
char		*exit_status_variable(t_info *info, char *str);
char		*skip_alpha(char *str);
void		sig_slash(int signal);
void		sig_init(int signal);
void		ft_delpipe(int *pipe);
int			check_builtin(t_info *info);
void		launch_dowait(t_info *info);
void		redirect(t_info *info);
void		parse_place_bin(t_info *info);
void		parse_get_token_util(t_info *info, char **token);
void		close_opn(t_info *info);
void		rise_one_q(t_info *info, char sym);
void		rise_two_q(t_info *info, char sym);
int		check_delim(t_info *info, char delim, char next_s);
int     	check_tokens(t_info *info);
int 		*push_pipe(t_info *info);
void		last_step(t_info *info, t_command *tmp);
void		print_empty_com(t_info *info);
int			launch_builtin(t_info *info);
void		null_pipe(t_info *info, int *pipe_n);
char		*allocate_str(char **line_cp, int count, t_info *info, char delim);
int			cmp_delim(char *delim, char **line_cp, t_info *info, char **token);
void		not_null_pipe(t_info *info, int *pipe_n, int *pipe_p);
void		bin_pipe_not_null(t_info *info, int *pipe_p);
void		close_free_dir(DIR *dir_fd, char *path, char *end_path);
void		dup_path(struct dirent	*rd, char *end_path, t_info * info);
void		cntrl_d(void);
void		no_check(int check, t_info *info, char *str);
#endif
