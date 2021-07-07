#include "../includes/minishell.h"

void	launch_dowait(t_info *info)
{
	while (info->wait_count != 0)
	{
		wait(&info->exit_status);
		info->wait_count--;
	}
}

