#include "../includes/minishell.h"

char	*allocate_str(char **line_cp, int count, t_info *info, char delim)
{
	int		j;
	int		step;
	char	*str;

	str = (char *) malloc(sizeof(char) * count);
	j = 0;
	step = check_delim(info, delim, (*line_cp)[count]);
	while ((*line_cp)[j] != delim)
	{
		str[j] = (*line_cp)[j];
		j++;
	}
	str[j] = '\0';
	*line_cp = *line_cp + step;
	*line_cp = *line_cp + count;
	return (str);
}

char	*ft_strtok(char **line_cp, t_info *info, char *delim)
{
	int		i;
	int		j;
	char	*token;
	char	*tmp;

	i = 0;
	token = NULL;
	if (**line_cp == '\0' || *line_cp == NULL)
		return (NULL);
	while ((*line_cp)[i] != '\0')
	{
		j = 0;
		rise_one_q(info, (*line_cp)[i]);
		rise_two_q(info, (*line_cp)[i]);
		info->parse_i = i;
		if (cmp_delim(delim, line_cp, info, &token) == 1)
			return (token);
		close_opn(info);
		i++;
	}
	tmp = ft_strdup(*line_cp);
	*line_cp = *line_cp + i;
	return (tmp);
}

void	get_token_argv_bin(char **token, t_info *info)
{
	t_command	*f_com;
	char		*tmp;

	f_com = ft_new_com();
	info->command = f_com;
	*token = ft_strtok(&info->parse->line_cp, info, "|<>");
	tmp = *token;
	*token = put_variable(info, *token, info->envp);
	if (*token != NULL)
	{
		parse_get_token_util(info, token);
	}
	while (*token != NULL)
	{
		free(*token);
		*token = ft_strtok(&info->parse->line_cp, info, "|<>");
		*token = put_variable(info, *token, info->envp);
		if (*token != NULL)
		{
			parse_get_token_util(info, token);
		}
	}
	info->command = f_com;
}

void	parse(t_info *info)
{
	char	*line;
	char	*token;

	token = NULL;
	line = ft_strtrim(info->text, " ");
	if (check_valid(info, line) == 0)
	{
		free(line);
		return ;
	}
	info->parse->line_cp = line;
	get_token_argv_bin(&token, info);
	if (check_tokens(info) == 0)
	{
		free_info(info);
		free(line);
		return ;
	}
	parse_place_bin(info);
	launch_command(info);
	free(line);
}
