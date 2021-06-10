#include "minishell.h"

t_command	*new_com()
{
	t_command *com;

	com = (t_command *)malloc(sizeof(t_command));
	com->command = 0;
	com->file = 0;
	com->flag = 0;
	com->redirect = 0;
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

int		main(int argc, char **argv, char **envp)
{
	t_history 	*list;
	t_command	*com;
	char		*str;

	com = new_com();
	list = NULL;
	list = new_list(com, list);
	while (1)
	{
		list->text = readline("BulochkaBao% ");
		parse(com, envp);
	}
	return (0);
}
