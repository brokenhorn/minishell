#include "../includes/minishell.h"

t_sig	g_sig;

t_parse	*init_parse(__unused t_info *info)
{
	t_parse	*parse;

	parse = (t_parse *)malloc(sizeof(t_parse));
	parse->qu = 0;
	parse->opn = 0;
	parse->line_cp = NULL;
	return (parse);
}

void	init_info(t_info *info)
{
	info->command = NULL;
	info->exit_status = 0;
	info->text = NULL;
	info->err_msg = NULL;
	info->err_check = 0;
	info->wait_count = 0;
	info->pipe_list = NULL;
	info->parse = init_parse(info);
	info->dup_in = dup(0);
	info->dup_out = dup(1);
	info->fd_redirect = -1;
	g_sig.sigint = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_info	*info;

	(void)argv;
	(void)argc;
	info = (t_info *)malloc(sizeof(t_info));
	init_info(info);
	info->envp = malloc_envp(envp);
	while (1)
	{
		g_sig.sigint = 0;
		info->err_check = 0;
		signal(SIGQUIT, &sig_slash);
		signal(SIGINT, &sig_init);
		info->text = readline("BulochkaBao% ");
		if (info->text == NULL)
			cntrl_d();
		if (info->text && info->text[0] && ft_check_space(info->text) == 1)
		{
			add_history(info->text);
			parse(info);
		}
	}
	return (0);
}
