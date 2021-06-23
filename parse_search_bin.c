#include "minishell.h"

char *search_path(t_info *info)
{
	char *path;
	int i;

	i = 0;
	path = NULL;
	while (info->envp[i] != NULL)
	{
		if (ft_strnstr(info->envp[i],"PATH", 4) != 0)
		{
			path = info->envp[i];
			break;
		}
		i++;
	}
	return (path);
}

void search_bin(t_info *info)
{
	char *path;
	char **path_dir;
	int i;
	DIR *dir_fd;
	struct dirent *rd;

	i = 0;
	path = search_path(info);
	path_dir = ft_split(path, ':'); //malloc
	while (path_dir[i] != NULL)
	{
		dir_fd = opendir(path_dir[i]);
		while((rd = readdir(dir_fd)) != NULL)
		{
			if (rd->d_name == info->command->argv[0])
			{
				info->command->file = ft_strjoin(path_dir[i], info->command->argv[0]);
				break;
			}
		}
		if (info->command->file  != NULL)
		{
			closedir(dir_fd);
			break;
		}
		i++;
		closedir(dir_fd); //если не найдет файл ошибка
	}
}