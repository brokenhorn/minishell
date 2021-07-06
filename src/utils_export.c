#include "../includes/minishell.h"

char	**sort_export(char **str, int n)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = n - 1;
	while (i < n - 1)
	{
		while (j > i)
		{
			if (*str[j - 1] > *str[j])
			{
				tmp = str[j - 1];
				str[j - 1] = str[j];
				str[j] = tmp;
			}
			j--;
		}
		j = n - 1;
		i++;
	}
	return (str);
}

char	**malloc_envp(char **envp)
{
	char	**copy;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	copy = (char **)malloc(sizeof(char *) * (i + 1));
	copy[i] = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		copy[i] = (char *)malloc(sizeof(char) * (ft_strlen(envp[i]) + 1));
		ft_strlcpy(copy[i], envp[i], ft_strlen(envp[i]) + 1);
		i++;
	}
	return (copy);
}

void	add_variable_new(t_info *info, char *name, char *value, int i)
{
	char	**copy;

	copy = (char **)malloc(sizeof(char *) * (i + 2));
	copy[i + 1] = NULL;
	copy[i] = new_variable(name, value);
	i = 0;
	while (info->envp[i] != NULL)
	{
		copy[i] = (char *)malloc(
				sizeof(char) * (ft_strlen(info->envp[i]) + 1));
		ft_strlcpy(copy[i], info->envp[i], ft_strlen(info->envp[i]) + 1);
		i++;
	}
	free_2arr(info->envp);
	info->envp = copy;
}
