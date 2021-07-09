#include "../includes/minishell.h"

int	slash_count(int count, char *str)
{
	int	i;

	i = 0;
	while (count != 0)
	{
		if (str[i] == '/')
			count--;
		i++;
	}
	return (i);
}

char	*fulfill_path(char *str, int i)
{
	char	*path;
	int		j;

	j = 0;
	path = (char *)malloc(sizeof(char) * i + 1);
	if (i > 1)
		i--;
	while (i != 0)
	{
		path[j] = str[j];
		i--;
		j++;
	}
	path[j] = '\0';
	return (path);
}

char	*allocate_path(char *str, int count, char **end_path)
{
	int		i;
	int		i_cp;
	char	*path;
	char	*end;

	path = NULL;
	end = NULL;
	i = slash_count(count, str);
	i_cp = i;
	path = fulfill_path(str, i);
	end = (char *)malloc(sizeof(char) * ft_strlen(str + i_cp) + 1);
	i = 0;
	while (str[i_cp] != '\0')
	{
		end[i] = str[i_cp];
		i++;
		i_cp++;
	}
	end[i] = '\0';
	*end_path = end;
	return (path);
}

char	*take_dir(char *str, char **end_path)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '/')
			count++;
		i++;
	}
	i = 0;
	return (allocate_path(str, count, end_path));
}
