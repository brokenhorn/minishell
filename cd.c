#include "minishell.h"

void	cd(t_info *info, char **envp)
{
	int		j;
	char	*old;
	char	*new;
	char	*err;

	j = chdir(info->command->argv[1]);
	if (j == -1)
		error(info, NULL, NULL);
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
			break;
		}
		j++;
	}
	j = 0;
	while (envp[j] != NULL)
	{
		if (!ft_strncmp(envp[j], "OLDPWD=", 7))
		{
			envp[j] = ft_strjoin("OLDPWD=", old);
			break;
		}
		j++;
	}
}
