#include "../includes/minishell.h"

t_command	*ft_new_com(void)
{
	t_command	*node;

	node = (t_command *)malloc(sizeof(t_command));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->command = 0;
	node->argv = NULL;
	node->file = NULL;
	node->flag = 0;
	return (node);
}

void	ft_com_add_back(t_command **lst, t_command *new)
{
	t_command	*a;

	if (lst && new)
	{
		if (!(*lst))
			*lst = new;
		else
		{
			a = *lst;
			while (a->next)
				a = a->next;
			a->next = new;
		}
	}
}
