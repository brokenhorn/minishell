#include "minishell.h"

void	pwd(char **envp)
{
	int		i;
	int		j;

	i = 4;
	j = 0;
	while (envp[j] != NULL)
	{
		if (!ft_strncmp(envp[j], "PWD=", 4))
			while (envp[j][i])
				printf("%c", envp[j][i++]);
		j++;
	}
	printf("\n");
}
