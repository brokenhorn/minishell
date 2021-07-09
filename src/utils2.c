#include "../includes/minishell.h"

char	*exit_status_variable(t_info *info, char *str)
{
	free(str);
	str = ft_itoa(info->exit_status);
	return (str);
}

char	*skip_alpha(char *str)
{
	while (ft_isalnum(*str) || *str == '_')
		str++;
	return (str);
}

void	ft_delpipe(int *pipe)
{
	close(pipe[0]);
	close(pipe[1]);
	free(pipe);
}

int	check_builtin(t_info *info)
{
	if (ft_strncmp(info->command->argv[0], "cd", 2) == 0)
	{
		return (1);
	}
	else if (ft_strncmp(info->command->argv[0], "export", 6) == 0)
	{
		return (1);
	}
	else if (ft_strncmp(info->command->argv[0], "exit", 4) == 0)
	{
		return (1);
	}
	else if (ft_strncmp(info->command->argv[0], "unset", 5) == 0)
		return (1);
	return (0);
}

int	check_tokens(t_info *info)
{
	t_command	*tmp;

	tmp = info->command;
	if (tmp->flag == B1 || tmp->flag == B2)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->argv[0] == NULL)
		{
			error(info, "syntax error", NULL);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
