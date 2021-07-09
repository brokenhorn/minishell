#include "../includes/minishell.h"

void	null_pipe(t_info *info, int *pipe_n)
{
	info->wait_count++;
	if (!fork())
	{
		dup2(pipe_n[1], 1);
		ft_lstclear(&info->pipe_list, &ft_delpipe);
		if (launch_builtin(info) == 1)
			exit(0);
		else
			execve(info->command->file, info->command->argv, info->envp);
	}
}

void	not_null_pipe(t_info *info, int *pipe_n, int *pipe_p)
{
	info->wait_count++;
	if (!fork())
	{
		dup2(pipe_n[1], 1);
		dup2(pipe_p[0], 0);
		ft_lstclear(&info->pipe_list, &ft_delpipe);
		if (launch_builtin(info) == 1)
			exit(0);
		else
			execve(info->command->file, info->command->argv, info->envp);
	}
}

void	bin_pipe_not_null(t_info *info, int *pipe_p)
{
	info->wait_count++;
	if (!fork())
	{
		dup2(pipe_p[0], 0);
		ft_lstclear(&info->pipe_list, &ft_delpipe);
		if (launch_builtin(info) == 1)
			exit (0);
		else
			execve(info->command->file, info->command->argv, info->envp);
	}
}
