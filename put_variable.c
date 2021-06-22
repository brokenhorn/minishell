#include "minishell.h"

static int	len_variable(char *str)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			while (str[i] != ' ' && str[i++] != '\0')
				len++;
			break;
		}
		i++;
	}
	return(len - 2);
}

static char *search_variable(char *str, char **envp)
{
	int		i;
	int		j;
	int		len;
	int		check;

	check = 0;
	i = ft_strlen(str) + 1;
	j = 0;
	while (envp[j] != NULL)
	{
		if (!ft_strncmp(envp[j], str, i - 1))
		{
			check = 1;
			len = ft_strlen(envp[j] + i);
			free(str);
			str = (char *)malloc(sizeof(char) * (len + 1));
			str[len] = '\0';
			len = 0;
			while (envp[j][i])
				str[len++] = envp[j][i++];
		}
		j++;
	}
	if (!check)
	{
		free(str);
		str = (char *) malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	return (str);
}

static char	*define_variable(char *str, char **envp)
{
	int		len;
	int		i;
	char	*variable;

	len = len_variable(str);
	variable = (char *)malloc(sizeof(char) * (len + 1));
	variable[len] = '\0';
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i - 1] == '$')
		{
			while (str[i] != ' ' && str[i] != '\0')
				variable[len++] = str[i++];
			break;
		}
		i++;
	}
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
			while (*str != ' ' && *str != '\0')
				str++;
			check = 1;
		}
		len++;
		str++;
	}
	return(len);
}

char	*make_new_str(char *str, char *new_str, char *variable)
{
	int		check;
	int		len;
	int		i;

	len = ft_strlen(variable) + len_str(str) + 1;
	check = 0;
	i = 0 ;
	while (len > 0)
	{
		if (*str == '$' && check == 0)
		{
			str++;
			while (*variable != '\0')
			{
				new_str[i++] = *variable++;
				len--;
			}
			while (*str != '\0' && *str != ' ')
				str++;
			check = 1;
		}
		else
			new_str[i++] = *str++;
		len--;
	}
	return(new_str);
}

char	*put_variable(char *str, char **envp)
{
	char	*variable;
	char	*new_str;
	int		len;

	new_str = str;
	variable = define_variable(str, envp);
	len = len_str(str);
	new_str = (char *) malloc(sizeof(char) * (ft_strlen(variable) + len + 1));
	new_str[ft_strlen(variable) + len] = '\0';
	new_str = make_new_str(str, new_str, variable);
	free(variable);
//	if (str)
//		free(str);
	str = new_str;
	return(new_str);
}
