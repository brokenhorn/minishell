#include "../includes/minishell.h"

void	close_free_dir(DIR *dir_fd, char *path, char *end_path)
{
	if (dir_fd)
		closedir(dir_fd);
	free(path);
	free(end_path);
}

void	dup_path(struct dirent	*rd, char *end_path, t_info *info)
{
	if (ft_strncmp(rd->d_name, end_path, ft_strlen(rd->d_name)) == 0
		&& rd->d_type == DT_REG)
		info->command->file = ft_strdup(info->command->argv[0]);
}
