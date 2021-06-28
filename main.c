#include "minishell.h"

t_command	*new_com()
{
	t_command *com;

	com = (t_command *)malloc(sizeof(t_command));
	com->command = 0;
	com->file = 0;
	com->flag = 0;
	com->argv = NULL;
	return (com);
}

int		main(int argc, char **argv, char **envp) //EXPORT
{
	t_command	*com;
	t_info		*info;

	com = new_com();
	info = (t_info *)malloc(sizeof(t_info));
	info->command = com;
	info->envp = envp;
	info->text = NULL;
	while (1)
	{
		//signal(SIGQUIT, exit(info)); //ctrl-d = exit ПЕРЕДЕЛАТЬ ВНУТРИ СИГНАЛ
	//	signal(SIGINT, ); // ctrl-c = \n
		info->text = readline("BulochkaBao% ");
		if (info->text && info->text[0])
			add_history(info->text);
		parse(info);
	}
	return (0);
}
