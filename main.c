#include "minishell.h"

t_command	*new_com()
{
	t_command *com;

	com = (t_command *)malloc(sizeof(t_command));
	com->command = 0;
	com->file = 0;
	com->flag = 0;
	com->text = NULL;
	return (com);
}

t_list	*new_list(t_command *com, t_history *lis)
{
	t_history	*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->text = NULL;
	list->next = NULL;
	list->prev = lis;
	return (list);
}

void	error(char *str)
{
	if (str == NULL)
		str = strerror(errno);
	printf("%s\n", str);
	exit(errno);
}

int		main(int argc, char **argv, char **envp)
{
	t_history 	*list;
	t_command	*com;
	t_info		*info;
	char		*str;

	com = new_com();
	list = NULL;
	list = new_list(com, list);
	info = (t_info *)malloc(sizeof(t_info));
	info->command = com;
	info->history = list;

	com->text = ft_strdup("co");
	cd(com, envp);
	pwd(envp);
	while (*envp)
		printf("%s\n", *envp++);
//	while (1)
//	{
//		list->text = readline("BulochkaBao% ");
//		parse(info, envp);
//	}
	return (0);
}
