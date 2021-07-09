#include "../includes/minishell.h"

void	no_check(int check, t_info *info, char *str)
{
	if (!check)
	{
		error(info, info->command->argv[1], "numeric argument required");
		exit(0);
	}
	else if (str && info->command->argv[2] != NULL)
		printf("too many arguments\n");
	else
	{
		error(info, "exit", NULL);
		exit(0);
	}
}
