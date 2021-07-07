#include "../includes/minishell.h"

int launch_command_bin(t_info *info, int *pipe_p)
{
//	pid_t pid;
	int status;


	//pid = fork();
	if (pipe_p == NULL)
	{
		info->wait_count++;
		if (!fork())
			execve(info->command->file, info->command->argv, info->envp);
	}
	else if (pipe_p != NULL)
	{
		info->wait_count++;
		if (!fork())
		{
			dup2(pipe_p[0], 0);
			ft_lstclear(&info->pipe_list, &ft_delpipe);
			execve(info->command->file, info->command->argv, info->envp);
		}
	}
	return(1);
}

int launch_command_pipe(t_info *info,__unused  int *pipe_p)
{
	int *pipe_n;
	t_list *node;
	int status;

	pipe_n = (int*)malloc(sizeof(int) * 2);
	pipe(pipe_n);
	node = ft_lstnew(pipe_n);
	ft_lstadd_back(&info->pipe_list, node);
	if (pipe_p != NULL)
	{
		info->wait_count++;
		if(!fork())
		{
			dup2(pipe_n[1], 1);
			dup2(pipe_p[0], 0);
			ft_lstclear(&info->pipe_list, &ft_delpipe);
			execve(info->command->file, info->command->argv, info->envp);
		}
	}
	else if (pipe_p == NULL)
	{
		info->wait_count++;
		if (!fork())
		{
			dup2(pipe_n[1], 1);
			ft_lstclear(&info->pipe_list, &ft_delpipe);
			execve(info->command->file, info->command->argv, info->envp);
		}
	}
	info->command = info->command->next;
	if (info->command && info->command->flag == PIPE)
		launch_command_pipe(info, pipe_n);
	else if (info->command && info->command->flag != PIPE)
		launch_command_bin(info, pipe_n);
//	close(pipe_n[0]);
//	close(pipe_n[1]);
	return (1);
}

//int launch_command_pipe(t_info *info,__unused  int *pipe_p)
//{
//	//int pipe1[2];
//	int *pipe1;
//	int *pipe2;
////	pid_t pid;
//	int status;
//
//	pipe1 = (int*)malloc(sizeof(int) * 2);
//	pipe2 = (int*)malloc(sizeof(int) * 2);
//	if (pipe(pipe1))
//		printf("pipe_error");
//	pipe(pipe2);
//	if (!fork())
//	{
//		close(pipe1[0]);
//		dup2(pipe1[1], 1);
//		close(pipe1[1]);
//		close(pipe2[1]);
//		close(pipe2[0]);
//		execve(info->command->file, info->command->argv, info->envp);
//	}
//	info->command = info->command->next;
//	if(!fork())
//	{
//		dup2(pipe1[0], 0);
//		dup2(pipe2[1], 1);
//		close(pipe1[1]);
//		close(pipe1[0]);
//		close(pipe2[1]);
//		close(pipe2[0]);
//		execve(info->command->file, info->command->argv, info->envp);
//	}
//	info->command = info->command->next;
//	if (!fork())
//	{
//		dup2(pipe2[0], 0);
//		close(pipe2[0]);
//		close(pipe2[1]);
//		close(pipe1[1]);
//		close(pipe1[0]);
//		execve(info->command->file, info->command->argv, info->envp);
//	}
//
//	close(pipe1[0]);
//	close(pipe1[1]);
//	close(pipe2[0]);
//	close(pipe2[1]);
//	wait(0);
//	wait(0);
//	wait(0);
//	return (1);
//}

//int launch_command_redirect(t_info *info)
//{}

int launch_command(t_info *info) //пайпы для билдынов
{
	t_command *tmp;

	tmp = info->command;
	while (info->command != NULL)
	{
		if (ft_strncmp(info->command->argv[0], "cd", 2) == 0)
			cd(info, info->envp);
		else if (ft_strncmp(info->command->argv[0], "export", 6) == 0)
			export(info ,info->command->argv);
		else if (ft_strncmp(info->command->argv[0], "exit", 4) == 0)
			my_exit(info);
		else if (info->command->flag == PIPE && info->command->file != NULL)
			launch_command_pipe(info, NULL);
		else if (info->command->file != NULL)
			launch_command_bin(info, NULL);
			////	else if (info->command->flag == B1 || info->command->flag == B2 ||
////			info->command->flag == S1 || info->command->flag == S2 &&
////			info->command->file != NULL)
////		launch_command_redirect(info);
		else
		{
			if (info->err_msg == NULL)
				error(info,"Command not found",info->command->argv[0]);
			else
				error(info,info->err_msg,info->command->argv[0]);
			return(1);
		}
		ft_lstclear(&info->pipe_list, &ft_delpipe);
		while (info->wait_count != 0)
		{
			wait(&info->exit_status);
			info->wait_count--;
		}

		if (info->command)
			info->command = info->command->next;
	}
	info->command = tmp;
	free_info(info);
	info->wait_count = 0;
	return (0);
}

