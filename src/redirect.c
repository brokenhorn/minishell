#include "../includes/minishell.h"

static char	*util(t_info *info, char *stop, char *str)
{
	char	*text;
	char	*tmp;

	text = (char *) malloc(sizeof(char) * 1);
	text[0] = '\0';
	while (!(ft_strlen(str) == ft_strlen(stop)
			&& (ft_strncmp(stop, str, ft_strlen(str)) + 1) == ft_strlen(str)))
	{
		if (str)
		{
			tmp = text;
			text = ft_strjoin(text, str);
			free(tmp);
			free(str);
			tmp = text;
			text = ft_strjoin(text, "\n");
			free(tmp);
		}
		str = readline("> ");
	}
	if (str)
		free(str);
	text = put_variable(info, text, info->envp);
	return (text);
}

static void	redirect_S2(t_info *info, char *stop)
{
	char	*text;
	int		fd[2];

	text = NULL;
	text = util(info, stop, NULL);
	pipe(fd);
	if (!fork())
	{
		close(fd[0]);
		write(fd[1], text, ft_strlen(text));
		close(fd[1]);
		exit(0);
	}
	wait(0);
	dup2(fd[0], 0);
	close(fd[1]);
	close(fd[0]);
	free(text);
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
		redirect_S2(info, file);
}
