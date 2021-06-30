#include "../minishell.h"

static int	check_redirect(t_info *info, char *str)
{
	if (*str == '>')
	{
		if (*(str + 1) == '\0')
			error(info, "syntax error near unexpected token `newline'", NULL);
		if (*(str + 1) == '>' && *(str - 1) == '>')
			error(info, "syntax error near unexpected token `>'", NULL);
		if (*(str + 1) == '<')
			error(info, "syntax error near unexpected token `<'", NULL);
	}
	if (*str == '<')
	{
		if (*(str + 1) == '\0')
			error(info, "syntax error near unexpected token `newline'", NULL);
		if (*(str + 1) == '<' && *(str - 1) == '<')
			error(info, "syntax error near unexpected token `<'", NULL);
		if (*(str + 1) == '>')
			error(info, "syntax error near unexpected token `>'", NULL);
	}
}

void	check_valid(t_info *info, char *str)
{
	char	qu;

	qu = 0;
	if (*str == '|')
		error(info, "syntax error near unexpected token `|'", NULL);
	while (*str != '\0')
	{
		if (qu == 0 && (*str == '\'' || *str == '\"'))
		{
			if (*str == '\'')
				qu = '\'';
			else
				qu = '\"';
		}
		else if (*str == qu)
			qu = 0;
		if (qu == 0)
			check_redirect(info, str);
		str++;
	}
	if (qu != 0)
		error(info, "unclosed quotes", NULL);
}
