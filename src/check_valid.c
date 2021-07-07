#include "../minishell.h"

static int	check_error(t_info *info, char *str)
{
	error(info, str, NULL);
	info->exit_status = 258;
	return (0);
}

static int	check_redirect(t_info *info, char *str)
{
	if (*str == '>')
	{
		if (*(str + 1) == '\0')
			return (check_error(info,
					   "syntax error near unexpected token `newline'"));
		if (*(str + 1) == '>' && *(str - 1) == '>')
			return (check_error(info,
					   "syntax error near unexpected token `>'"));
		if (*(str + 1) == '<')
			return (check_error(info,
					   "syntax error near unexpected token `<'"));
	}
	if (*str == '<')
	{
		if (*(str + 1) == '\0')
			return (check_error(info,
					   "syntax error near unexpected token `newline'"));
		if (*(str + 1) == '<' && *(str - 1) == '<')
			return (check_error(info,
					   "syntax error near unexpected token `<'"));
		if (*(str + 1) == '>')
			return (check_error(info,
					   "syntax error near unexpected token `>'"));
	}
	return (1);
}

void	check_valid(t_info *info, char *str)
{
	char	qu;

	qu = 0;
	if (*str == '|')
		return (error(info, "syntax error near unexpected token `|'", NULL));
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
			if (!check_redirect(info, str))
				return ;
		str++;
	}
	if (qu != 0)
		error(info, "unclosed quotes", NULL);
}
