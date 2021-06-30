#include "../minishell.h"

static void	export_empty(char **envp)
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
	copy = sort_export(copy, n);
	n = 0;
	while (copy[n])
	{
		printf("declare -x ");
		printf("%s\n", copy[n++]);
	}
	free_2arr(copy);
}

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

char	*new_variable(char *name, char *value)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(name)
				+ ft_strlen(value) + 2));
	str[ft_strlen(name) + ft_strlen(value) + 1] = '\0';
	while (*name != '\0')
		str[i++] = *name++;
	if (value)
	{
		str[i++] = '=';
		while (*value != '\0')
			str[i++] = *value++;
	}
	return (str);
}

static void	add_variable(t_info *info, char *name, char *value)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	while (info->envp[i] != NULL)
	{
		if (!ft_strncmp(info->envp[i], name, ft_strlen(name))
			&& info->envp[i][ft_strlen(name)] == '=')
		{
			free(info->envp[i]);
			if (value)
				info->envp[i] = new_variable(name, value);
			check = 1;
			break ;
		}
		i++;
	}
	if (!check)
		add_variable_new(info, name, value, i);
}

void	export(t_info *info, char **text)
{
	char	*name;
	char	*value;

	if (!text)
		export_empty(info->envp);
	else
	{
		while (*text)
		{
			name = NULL;
			value = NULL;
			if (check_variable(*text, &name, &value))
				add_variable(info, name, value);
			else
				printf("\'%s\': not a valid identifier\n", *text);
			text++;
			free(name);
			free(value);
		}
	}
}
