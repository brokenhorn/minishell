#include "minishell.h"

static char **sort(char **str, int n)
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
	return(str);
}

void	export(char **envp)
{
	int		n;
	char	**copy;

	n = 0;
	while (envp[n])
		n++;
	copy = (char **)malloc(sizeof(char *) * (n + 1));
	copy[n] = NULL;
	n = 0;
	while (*envp)
	{
		copy[n] = (char *)malloc(sizeof(char) * (ft_strlen(*envp) + 1));
		ft_strlcpy(copy[n], *envp, ft_strlen(*envp) + 1);
		n++;
		envp++;
	}
	copy = sort(copy, n);
	n = 0;
	while (copy[n])
		printf("%s\n", copy[n++]);
	free_2arr(copy);
}
