#include "../includes/minishell.h"

t_command	*new_com()
{
	t_command *com;

	com = (t_command *)malloc(sizeof(t_command));
	com->command = 0;
	com->file = 0;
	com->flag = 0;
	com->argv = NULL;
	//com->next = NULL;
	return (com);
}

t_parse *init_parse(__unused t_info *info)
{
	t_parse *parse;

	parse = (t_parse *)malloc(sizeof(t_parse));
	parse->qu = 0;
	parse->opn = 0;
	parse->line_cp = NULL;
	return (parse);
}


int		main(__unused  int argc, __unused  char **argv, char **envp) //EXPORT CHECK VALID
{
//	t_command	*com;
	t_info		*info;
//	int sig_check;

	info = (t_info *)malloc(sizeof(t_info));
	info->command = NULL;
	info->envp = malloc_envp(envp);
	info->exit_status = 0;
	info->text = NULL;
	info->err_msg = NULL;
	info->err_check = 0;
	info->wait_count = 0;
	info->pipe_list = NULL;
	info->parse = init_parse(info);
	info->dup_in = dup(0);
	info->dup_out = dup(1);
	info->fd_redirect = NULL;
//	sig_check = 0;
	while (1)
	{
		info->err_check = 0;
		signal(SIGQUIT, &sig_exit); //ctrl-d = exit ПЕРЕДЕЛАТЬ ВНУТРИ СИГНАЛ
		signal(SIGINT,&sig_init);
		//sig_check =	signal(SIGINT, sig_init(sig_check));// ctrl-c = \n
		info->text = readline("BulochkaBao% ");
		if (info->text && info->text[0] && ft_check_space(info->text) == 1)
		{
			add_history(info->text);
			parse(info);
		}
		//sig_check = 0;
	}
	return (0);
}
