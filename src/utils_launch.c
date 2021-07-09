#include "../includes/minishell.h"

void	launch_dowait(t_info *info)
{
	while (info->wait_count != 0)
	{
		wait(&info->exit_status);
		info->wait_count--;
	}
}

int	*push_pipe(t_info *info)
{
	int		*pipe_n;
	t_list	*node;

	pipe_n = (int *)malloc(sizeof(int) * 2);
	pipe(pipe_n);
	node = ft_lstnew(pipe_n);
	ft_lstadd_back(&info->pipe_list, node);
	return (pipe_n);
}

void	last_step(t_info *info, t_command *tmp)
{
	dup2(info->dup_out, 1);
	dup2(info->dup_out, 0);
	if (info->fd_redirect)
		close(info->fd_redirect);
	info->fd_redirect = -1;
	info->command = tmp;
	free_info(info);
	info->wait_count = 0;
}

void	print_empty_com(t_info *info)
{
	if (info->err_msg == NULL)
		error(info, "Command not found", info->command->argv[0]);
	else
		error(info, info->err_msg, info->command->argv[0]);
	free_info(info);
}
