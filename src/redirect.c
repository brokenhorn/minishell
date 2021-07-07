#include "../includes/minishell.h"

static void	redirect_S2(char *stop)
{
	char	*str;

	str = NULL;
	int a = ft_strlen(str);
	int b = ft_strlen(stop);
	int x = ft_strncmp(stop, str, ft_strlen(str));
	int y = ft_strlen(str);
	while (!(ft_strlen(str) == ft_strlen(stop) && (ft_strncmp(stop, str, ft_strlen(str)) + 1) == ft_strlen(str)))
	{
		if (str)
			free(str);
		str = readline("> ");
	}
	if (str)
		free(str);
}

void	redirect(t_info *info)
{
	char	*file;

	file = info->command->next->argv[0];
	if (info->command->flag == B1)
	{
		info->fd_redirect = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0664);
		dup2(info->fd_redirect, 1);
	}
	else if (info->command->flag == B2)
	{
		info->fd_redirect = open(file, O_WRONLY | O_CREAT | O_APPEND, 0664);
		dup2(info->fd_redirect, 1);
	}
	else if (info->command->flag == S1)
	{
		info->fd_redirect = open(file, O_RDONLY | O_CREAT, 0664);
		dup2(info->fd_redirect, 0);
	}
	else if (info->command->flag == S2)
		redirect_S2(file);
}
