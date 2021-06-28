#include "minishell.h"

static char *search_variable(char *str, char **envp)
{
	int		i;
	int		j;
	int		len;
	int		check;

	check = 0;
	i = ft_strlen(str) + 1;
	j = 0;
	while (envp[j] != NULL && !check)
	{
		if (!ft_strncmp(envp[j], str, i - 1))
		{
			check = 1;
			len = ft_strlen(envp[j] + i);
			free(str);
			str = (char *)malloc(sizeof(char) * (len + 1));
			str[len] = '\0';
			len = 0;
			if (envp[j][i - 1] != '=')
			{
				check = 0;
				break;
			}
			while (envp[j][i])
				str[len++] = envp[j][i++];
		}
		j++;
	}
	if (!check)
	{
		free(str);
		str = NULL;
	}
	return (str);
}

static char	*define_variable(char *ptr, char **envp)
{
	int		len;
	char	*variable;

	len = 0;
	while (ft_isalpha(ptr[len]))
		len++;
	variable = (char *)malloc(sizeof(char) * (len + 1));
	variable[len] = '\0';
	len = 0;
	while (ft_isalpha(*ptr))
		variable[len++] = *ptr++;
	if (!len)
		return(NULL);
	return (search_variable(variable, envp));
}

static int len_str(char *str)
{
	int		len;
	int		check;

	len = 0;
	check = 0;
	while (*str != '\0')
	{
		if (*str == '$' && check == 0)
		{
			while (ft_isalpha(*str))
				str++;
			check = 1;
		}
		len++;
		str++;
	}
	return(len);
}

char	*make_new_str(char *str, char *new_str, char *variable, char **ptr)
{
	int		len;
	int		i;

	len = ft_strlen(variable) + len_str(str) + 1;
	*ptr -= 1;
	i = 0 ;
	while (len > 0)
	{
		if (str == *ptr)
		{
			str++;
			if (variable)
			{
				while (*variable != '\0')
				{
					new_str[i++] = *variable++;
					len--;
				}
			}
			*ptr = new_str + i;
			while (ft_isalpha(*str))
				str++;
		}
		else
		{
			new_str[i++] = *str++;
			len--;
		}
	}
	return(new_str);
}

char	*variable_in_str(char *str, char **ptr, char **envp)
{
	char	*variable;
	int		len;
	char	*new_str;

	(*ptr)++;
	variable = define_variable(*ptr, envp);
	len = len_str(str);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(variable) + len + 1));
	new_str[ft_strlen(variable) + len] = '\0';
	new_str = make_new_str(str, new_str, variable, ptr);
	free(variable);
	free(str);
	return (new_str);
}

char	*delet_quot(char *str, char **ptr)
{
	int		len;
	int		i;
	char	*tmp;
	char	*temp;

	len = ft_strlen(str);
	tmp = str;
	temp = str;
	str = (char *)malloc(sizeof(char) * len);
	str[len] = '\0';
	i = 0;
	while (len)
	{
		if (*ptr != tmp)
		{
			str[i++] = *tmp;
			len--;
		}
		else
			*ptr = str + i;
		tmp++;
	}
	free(temp);
	return(str);
}

char	*no_quotes(char *str)
{
	char	qu;
	char	*ptr;

	qu = 0;
	ptr = str;
	while (*ptr != '\0')
	{
		if (qu == 0 && (*ptr == '\'' || *ptr == '\"'))
		{
			if (*ptr == '\'')
				qu = '\'';
			else
				qu = '\"';
			str = delet_quot(str, &ptr);
		}
		else if (*ptr == qu)
		{
			qu = 0;
			str = delet_quot(str, &ptr);
		}
		else
			ptr++;
	}
	return(str);
}

char	*put_variable(char *str, char **envp)
{
	char	*ptr;
	char	qu;

	qu = 0;
	ptr = str;
	if (!str)
		return(NULL);
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
		if (*ptr == '$' && qu != '\'')
			str = variable_in_str(str, &ptr, envp);
		else
			ptr++;
	}
	str = no_quotes(str);
	return(str);
}
