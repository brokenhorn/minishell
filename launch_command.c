#include "minishell.h"

int launch_command_bin(t_info *info)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		execve(info->command->file, info->command->argv, info->envp);
	}
	else if (pid > 0)
		waitpid(pid, &status, WUNTRACED);
	else if (pid < 0)
	{
		error(info, NULL, NULL);
		my_exit(info);
	}
	return(1);
}

int launch_command_pipe(t_info *info)//запонмить вывод-ввод  дописать FORK 0< 0>
{
	int pipe1[2];
	int cp_fd;
	pid_t pid;
	int status;

	pid = fork();
	pipe(pipe1);
	cp_fd = dup(0);
	if (pid == 0)
	{
		dup2(pipe1[1], 1);
		close(pipe1[0]);
		execve(info->command->file, info->command->argv, info->envp);
	}
	else if (pid > 0)
	{
		close(pipe1[0]);
		waitpid(pid, &status, WUNTRACED);
	}
	else if (pid < 0)
	{
		error(info, NULL, NULL);
		my_exit(info);
	}
	return (1);
}

int launch_command_redirect(t_info *info)
{}

int launch_command(t_info *info) //ЕСЛИ НЕТ КОМАНДЫ ТО ОШИБКА НАДО ИСПРАВИТЬ LS??
{
	if (ft_strncmp(info->command->argv[0], "cd", 2) == 0)
		cd(info, info->envp);
	else if (ft_strncmp(info->command->argv[0], "export", 6) == 0)
		export(info->envp);
	else if (ft_strncmp(info->command->argv[0], "exit", 4) == 0)
		my_exit(info);
	else if (info->command->flag == PIPE && info->command->file != NULL)
		launch_command_pipe(info);
//	else if (info->command->flag == B1 || info->command->flag == B2 ||
//			info->command->flag == S1 || info->command->flag == S2 &&
//			info->command->file != NULL)
//		launch_command_redirect(info);
	else if (info->command->file != NULL)
		launch_command_bin(info);
	else
	{
		error(info,"Command not found",info->command->argv[0]);
		return(1);
	}
	//launch_command_bin(info);
	info->command->flag = 0;
	if(info->command->file)
	{
		free(info->command->file);
		info->command->file = NULL;
	}
	free_2arr(info->command->argv);
	info->command->argv = NULL;
	return (0);
}

