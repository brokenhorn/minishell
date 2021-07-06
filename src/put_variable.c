#include "../includes/minishell.h"

static int	util(char **envp, char **str, int i, int j)
{
	int		check;
	int		len;

	check = 1;
	len = ft_strlen(envp[j] + i);
	free(*str);
	*str = (char *)malloc(sizeof(char) * (len + 1));
	(*str)[len] = '\0';
	len = 0;
	if (envp[j][i - 1] != '=')
		check = 0;
	else
	{
		while (envp[j][i])
			(*str)[len++] = envp[j][i++];
	}
	return (check);
}

static char	*search_variable(t_info *info, char *str, char **envp)
{
	int		i;
	int		j;
	int		check;

	check = 0;
	i = ft_strlen(str) + 1;
	j = 0;
	while (envp[j] != NULL && !check)
	{
		if (!ft_strncmp(envp[j], str, i - 1))
			check = util(envp, &str, i, j);
		j++;
	}
	if (!check)
	{
		if (*str == '?')
			str = exit_status_variable(info, str);
		else
		{
			free(str);
			str = NULL;
		}
	}
	return (str);
}

static char	*define_variable(t_info *info, char *ptr, char **envp)
{
	int		len;
	char	*variable;

	len = 0;
	while (ft_isalnum(ptr[len]) || ptr[len] == '_')
		len++;
	if (*ptr == '?')
		len = 1;
	variable = (char *)malloc(sizeof(char) * (len + 1));
	variable[len] = '\0';
	len = 0;
	if (*ptr == '?')
		variable[len++] = '?';
	else
	{
		while (ft_isalnum(*ptr) || *ptr == '_')
			variable[len++] = *ptr++;
	}
	if (!len)
		return (NULL);
	return (search_variable(info, variable, envp));
}

char	*variable_in_str(t_info *info, char *str, char **ptr, char **envp)
{
	char	*variable;
	int		len;
	char	*new_str;

	(*ptr)++;
	variable = define_variable(info, *ptr, envp);
	len = len_str(str, *ptr);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(variable) + len + 1));
	new_str[ft_strlen(variable) + len] = '\0';
	new_str = make_new_str(str, new_str, variable, ptr);
	free(variable);
	free(str);
	return (new_str);
}

char	*put_variable(t_info *info, char *str, char **envp)
{
	char	*ptr;
	char	qu;

	qu = 0;
	ptr = str;
	if (!str)
		return (NULL);
	while (*ptr != '\0')
	{
		if (qu == 0 && (*ptr == '\'' || *ptr == '\"'))
		{
			if (*ptr == '\'')
				qu = '\'';
			else
				qu = '\"';
		}
		else if (*ptr == qu)
			qu = 0;
		if (*ptr == '$' && qu != '\''
			&& !(*(ptr - 1) == '\"' && *(ptr + 1) == '\"'))
			str = variable_in_str(info, str, &ptr, envp);
		else
			ptr++;
	}
	return (no_quotes(str));
}
