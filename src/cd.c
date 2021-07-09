#include "../includes/minishell.h"

static void	old_pwd(char **envp, char *old)
{
	int		j;

	j = 0;
	while (envp[j] != NULL)
	{
		if (!ft_strncmp(envp[j], "OLDPWD=", 7))
		{
			envp[j] = ft_strjoin("OLDPWD=", old);
			break ;
		}
		j++;
	}
}

int	directory(t_info *info, char **envp)
{
	int		j;
	char	*home;

	j = 0;
	home = info->command->argv[1];
	if (!home)
	{
		while (envp[j] != NULL)
		{
			if (!ft_strncmp(envp[j], "HOME=", 5))
			{
				home = ft_strdup(envp[j] + 5);
				break ;
			}
			j++;
		}
	}
	j = chdir(home);
	if (j == -1)
	{
		error(info, NULL, NULL);
		return (0);
	}
	return (1);
}

void	cd(t_info *info, char **envp)
{
	int		j;
	char	*old;
	char	*new;
	char	*err;

	old = NULL;
	if (!directory(info, envp))
		return ;
	j = 0;
	new = malloc(400);
	while (envp[j] != NULL)
	{
		if (!ft_strncmp(envp[j], "PWD=", 4))
		{
			old = ft_strdup(envp[j] + 4);
			err = getcwd(new, 300);
			if (err == NULL)
				error(info, NULL, NULL);
			envp[j] = ft_strjoin("PWD=", new);
			break ;
		}
		j++;
	}
	old_pwd(envp, old);
}
