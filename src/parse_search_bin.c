#include "../includes/minishell.h"

char	*search_path(t_info *info)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (info->envp[i] != NULL)
	{
		if (ft_strnstr(info->envp[i], "PATH", 4) != 0)
		{
			path = info->envp[i];
			break ;
		}
		i++;
	}
	return (path);
}

void	join_path_com(char *path_dir, t_info *info)
{
	char	*tmp;

	tmp = ft_strjoin(path_dir, "/");
	info->command->file = ft_strjoin(tmp, info->command->argv[0]);
	free(tmp);
}

void	search_readdir(DIR *dir_fd, t_info *info, char *path_dir)
{
	struct dirent	*rd;

	rd = readdir(dir_fd);
	while (rd != NULL)
	{
		if (ft_strncmp(rd->d_name, info->command->argv[0],
				   ft_strlen(rd->d_name)) == 0 && rd->d_type == DT_REG)
		{
			join_path_com(path_dir, info);
			break ;
		}
		rd = readdir(dir_fd);
	}
	closedir(dir_fd);
}

void	verify_path(t_info *info)
{
	char			*path;
	DIR				*dir_fd;
	struct dirent	*rd;
	char			*end_path;

	path = take_dir(info->command->argv[0], &end_path);
	dir_fd = opendir(path);
	if (dir_fd == NULL)
	{
		close_free_dir(NULL, path, end_path);
		info->err_msg = ft_strdup("No such file or directory");
	}
	else
	{
		rd = readdir(dir_fd);
		while (rd != NULL)
		{
			dup_path(rd, end_path, info);
			rd = readdir(dir_fd);
		}
		close_free_dir(dir_fd, path, end_path);
	}
	if (info->command->file == NULL)
		info->err_msg = ft_strdup("is a directory");
}

void	search_bin(t_info *info)
{
	char	*path;
	char	**path_dir;
	int		i;
	DIR		*dir_fd;

	if (*(info->command->argv[0]) == '/')
		verify_path(info);
	else
	{
		i = 1;
		path = search_path(info);
		path_dir = ft_split(path, ':');
		while (path_dir[i] != NULL)
		{
			dir_fd = opendir(path_dir[i]);
			if (dir_fd == NULL)
				break ;
			search_readdir(dir_fd, info, path_dir[i]);
			if (info->command->file != NULL)
				break ;
			i++;
		}
		free_2arr(path_dir);
	}
}
