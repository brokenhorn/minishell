#include "../includes/minishell.h"

static int	check_variable(char *text, char **name, char **value)
{
	int		i;

	if (!(ft_isalpha(text[0]) || text[0] == '_'))
		return (0);
	i = 0;
	while (text[i] != '=' && text[i] != '\0')
		i++;
	*name = (char *)malloc(sizeof(char) * (i + 1));
	(*name)[i] = '\0';
	i = 0;
	while (*text != '=' && *text != '\0')
		(*name)[i++] = *text++;
	*value = NULL;
	if (*text == '=')
	{
		text++;
		*value = (char *) malloc(sizeof(char) * (ft_strlen(text) + 1));
		(*value)[ft_strlen(text)] = '\0';
		i = 0;
		while (*text != '\0')
			(*value)[i++] = *text++;
	}
	return (1);
}

static void	without_variable(t_info *info, int i)
{
	char	**copy;
	int		size;

	size = 0;
	while (info->envp[size] != NULL)
		size++;
	copy = (char **)malloc(sizeof(char *) * (size));
	copy[size] = NULL;
	size = 0;
	while (info->envp[size] != NULL)
	{
		if (size != i)
		{
			copy[i] = (char *) malloc(
					sizeof(char) * (ft_strlen(info->envp[i]) + 1));
			ft_strlcpy(copy[i], info->envp[i], ft_strlen(info->envp[i]) + 1);
		}
		i++;
	}
	free_2arr(info->envp);
	info->envp = copy;
}

static void	delet_variable(t_info *info, char *name, char *value)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	while (info->envp[i] != NULL)
	{
		if (!ft_strncmp(info->envp[i], name, ft_strlen(name))
			&& (info->envp[i][ft_strlen(name)] == '='
			|| info->envp[i][ft_strlen(name)] == '\0'))
		{
			free(info->envp[i]);
			if (value)
				info->envp[i] = new_variable(name, value);
			check = 1;
			break ;
		}
		i++;
	}
	if (check)
		without_variable(info, i);
}

void	unset(t_info *info, char **text)
{
	char	*name;
	char	*value;

	text++;
	if (!(*text))
		return ;
	else
	{
		while (*text)
		{
			name = NULL;
			value = NULL;
			if (check_variable(*text, &name, &value))
				delet_variable(info, name, value);
			else
				printf("\'%s\': not a valid identifier\n", *text);
			text++;
			free(name);
			free(value);
		}
	}
}
