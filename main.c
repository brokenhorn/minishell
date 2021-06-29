#include "minishell.h"

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

t_parse *init_parse(t_info *info)
{
	t_parse *parse;

	parse = (t_parse *)malloc(sizeof(t_parse));
	parse->qu = 0;
	parse->opn = 0;
	parse->line_cp = NULL;
	return (parse);
}

void start_point(char **envp)
{
	t_command	*com;
	t_info		*info;

//	com = new_com();
//	info = (t_info *)malloc(sizeof(t_info));
//	info->command = com;
//	info->envp = envp;
//	info->text = NULL;
//	info->parse = init_parse(info);
	while (1)
	{
		com = new_com();
		info = (t_info *)malloc(sizeof(t_info));
		info->command = com;
		info->envp = envp;
		info->text = NULL;
		info->parse = init_parse(info);
		//signal(SIGQUIT, exit(info)); //ctrl-d = exit ПЕРЕДЕЛАТЬ ВНУТРИ СИГНАЛ
		//	signal(SIGINT, ); // ctrl-c = \n
		info->text = readline("BulochkaBao% ");
		if (info->text && info->text[0] && ft_check_space(info->text) == 1)
			add_history(info->text);
		else
		{
			free_info(info);
			start_point(envp);
		}
		parse(info);
	}
}
//
//int		main(int argc, char **argv, char **envp)
//{
//	start_point(envp);
//	return(1);
//}

int		main(int argc, char **argv, char **envp) //EXPORT
{
	t_command	*com;
	t_info		*info;

	while (1)
	{
		com = new_com();
		info = (t_info *)malloc(sizeof(t_info));
		info->command = com;
		info->envp = envp;
		info->text = NULL;
		info->parse = init_parse(info);
		//signal(SIGQUIT, exit(info)); //ctrl-d = exit ПЕРЕДЕЛАТЬ ВНУТРИ СИГНАЛ
		//	signal(SIGINT, ); // ctrl-c = \n
		info->text = readline("BulochkaBao% ");
		if (info->text && info->text[0] && ft_check_space(info->text) == 1)
		{
			add_history(info->text);
			parse(info);
		}
		else
		{
			free_info(info);
			//start_point(envp);
		}
	//	parse(info);
	}

	return (0);
}
