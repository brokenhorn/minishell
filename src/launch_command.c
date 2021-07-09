#include "../includes/minishell.h"

int	launch_builtin(t_info *info)
{
	if (ft_strncmp(info->command->argv[0], "cd", 2) == 0)
	{
		cd(info, info->envp);
		return (1);
	}
	else if (ft_strncmp(info->command->argv[0], "export", 6) == 0)
	{
		export(info, info->command->argv);
		return (1);
	}
	else if (ft_strncmp(info->command->argv[0], "exit", 4) == 0)
	{
		my_exit(info);
		return (1);
	}
	else if (ft_strncmp(info->command->argv[0], "unset", 5) == 0)
	{
		unset(info, info->command->argv);
		return (1);
	}
	return (0);
}

int	launch_command_bin(t_info *info, int *pipe_p)
{
	if (info->command->flag == B1 || info->command->flag == B2
		|| info->command->flag == S1 || info->command->flag == S2)
		redirect(info);
	if (pipe_p == NULL)
	{
		if (launch_builtin(info) != 1)
		{
			info->wait_count++;
			if (!fork())
				execve(info->command->file, info->command->argv, info->envp);
		}
	}
	else if (pipe_p != NULL)
	{
		bin_pipe_not_null(info, pipe_p);
	}
	return (1);
}

int	launch_command_pipe(t_info *info, int *pipe_p)
{
	int		*pipe_n;

	pipe_n = push_pipe(info);
	if (pipe_p != NULL)
		not_null_pipe(info, pipe_n, pipe_p);
	else if (pipe_p == NULL)
		null_pipe(info, pipe_n);
	info->command = info->command->next;
	if (info->command && info->command->flag == PIPE)
		launch_command_pipe(info, pipe_n);
	else if (info->command && info->command->flag != PIPE)
		launch_command_bin(info, pipe_n);
	return (1);
}

int	launch_command(t_info *info)
{
	t_command	*tmp;

	tmp = info->command;
	while (info->command != NULL)
	{
		if (info->command->flag == PIPE && (info->command->file != NULL
				|| check_builtin(info) == 1))
			launch_command_pipe(info, NULL);
		else if (info->command->file != NULL || check_builtin(info) == 1)
			launch_command_bin(info, NULL);
		else
		{
			print_empty_com(info);
			return (1);
		}
		if (info->command->flag == B1 || info->command->flag == B2
			|| info->command->flag == S1 || info->command->flag == S2)
			info->command = info->command->next;
		ft_lstclear(&info->pipe_list, &ft_delpipe);
		launch_dowait(info);
		if (info->command)
			info->command = info->command->next;
	}
	last_step(info, tmp);
	return (0);
}
