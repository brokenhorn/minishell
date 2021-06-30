#include "../minishell.h"

void free_2arr(char **arr)
{
	int i;

	i = 0;
	if (arr)
	{
		while (arr[i] != NULL)
		{
			if (arr[i])
				free(arr[i]);
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

void free_info(t_info *info)
{
	if (info)
	{
		if (info->command)
		{
			if (info->command->argv)
				free_2arr(info->command->argv);
			if (info->command->file)
			{
				free(info->command->file);
				info->command->file = NULL;
			}
			free(info->command);
		}
		if (info->parse)
		{
			free(info->parse);
		}
		if (info->text)
			free(info->text);
		free(info);
	}
}

void	error(t_info *info, char *str, char *help)
{
	if (str == NULL)
		str = strerror(errno);
	if (help == NULL)
		printf("%s\n", str);
	else
		printf("%s: %s\n", str, help);
	free_info(info);
}

void	my_exit(t_info *info)
{
	error(info, "exit", NULL);
	exit(0);
}

int	ft_check_space(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}