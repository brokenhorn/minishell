#include "../includes/minishell.h"

int launch_command_bin(t_info *info, int *pipe_p)
{
	pid_t pid;
	int status;


	pid = fork();
	if (pid == 0 && pipe_p == NULL)
	{
		execve(info->command->file, info->command->argv, info->envp);
	}
	else if (pid == 0 && pipe_p != NULL)
	{
		dup2(pipe_p[0], STDIN_FILENO);
		//close(pipe_p[0]);
		//close(pipe_p[1]);
		execve(info->command->file, info->command->argv, info->envp);
	}
	else if (pid < 0)
		printf("errror");
	else if (pid > 0)
		waitpid(pid, &status, WUNTRACED);
	//wait(&pid);
	return(1);
}

int launch_command_pipe(t_info *info,__unused  int *pipe_p)
{
	//int pipe1[2];
	int *pipe1;
//	pid_t pid;
	int status;

	pipe1 = (int*)malloc(sizeof(int) * 2);
	if (pipe(pipe1))
		printf("pipe_error");
	if (!fork())
	{
		close(pipe1[0]);
		dup2(pipe1[1], 1);
		close(pipe1[1]);
		execve(info->command->file, info->command->argv, info->envp);
	}
	info->command = info->command->next;
	if(!fork())
	{
		close(pipe1[1]);
		dup2(pipe1[0], 0);
		close(pipe1[0]);
		execve(info->command->file, info->command->argv, info->envp);
	}
	close(pipe1[0]);
	close(pipe1[1]);
	wait(0);
	wait(0);
	return (1);
}

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
		info->command = info->command->next;
	}
	info->command = tmp;
	free_info(info);
	return (0);
}

