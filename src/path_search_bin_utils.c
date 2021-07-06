#include "../includes/minishell.h"

char *allocate_path(char *str, int count, char **end_path)
{
	int i;
	int j;
	int i_cp;
	char *path;
	char *end;

	i = 0;
	j = 0;
	while (count != 0)
	{
		if (str[i] == '/')
			count--;
		i++;
	}
	i_cp = i;
	path = (char *)malloc(sizeof(char) * i + 1);
	if (i > 1)
		i--;
	while(i != 0)
	{
		path[j] = str[j];
		i--;
		j++;
	}
	path[j] = '\0';
	end = (char*)malloc(sizeof(char) * ft_strlen(str + i_cp) + 1);
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

char *take_dir(char* str, char **end_path)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '/')
			count++;
		i++;
	}
	i = 0;
	return (allocate_path(str, count, end_path));
}

