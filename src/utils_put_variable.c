#include "../minishell.h"

int	len_str(char *str)
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
	return (len);
}

static void	util(char *variable, char **new_str, int *i, int *len)
{
	if (variable)
	{
		while (*variable != '\0')
		{
			(*new_str)[(*i)++] = *variable++;
			(*len)--;
		}
	}
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
			util(variable, &new_str, &i, &len);
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
	return (new_str);
}

static char	*delet_quot(char *str, char **ptr)
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
	return (str);
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
	return (str);
}
