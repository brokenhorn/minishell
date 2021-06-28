#include "minishell.h"

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
	}
}

void	error(t_info *info, char *str)
{
	if (str == NULL)
		str = strerror(errno);
	printf("%s\n", str);
	if (info)
	{
		if (info->command)
		{
			if (info->command->argv)
				free_2arr(info->command->argv);
			if (info->command->file)
				free(info->command->file);
			free(info->command);
		}
		if (info->text)
			free(info->text);
		free(info);
	}
}

void	my_exit(t_info *info)
{
	error(info, "exit");
	exit(0);
}