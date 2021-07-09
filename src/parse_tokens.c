#include "../includes/minishell.h"

char *allocate_str(char **line_cp, int count, t_info *info, char delim)
{
	int j;
	int step;
	char *str;

	step = 0;
	str = (char *) malloc(sizeof(char) * count);
	j = 0;
	check_delim(info, delim, (*line_cp)[count]);
	if (delim == '<' && (*line_cp)[count] == delim)
	{
		info->command->flag = S2;
		step++;
	}
	else if (delim == '>' && (*line_cp)[count] == delim)
	{
		info->command->flag = B2;
		step++;
	}
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

char *ft_strtok(char **line_cp, t_info *info, char *delim)
{
	int i;
	int j;
	char *token;
	char *tmp;

	i = 0;
	token = NULL;
	if (**line_cp == '\0' || *line_cp == NULL)
		return (NULL);
	while ((*line_cp)[i] != '\0')
	{
		j = 0;
		rise_one_q(info, (*line_cp)[i]);
		rise_two_q(info, (*line_cp)[i]);
		while (delim[j] != '\0')
		{
			if ((*line_cp)[i] == delim[j] && info->parse->opn == 0)
			{
				token =	allocate_str(line_cp, i + 1, info, delim[j]);
			//	*line_cp = *line_cp + i + 1;
				return (token);
			}
			j++;
		}
		close_opn(info);
		i++;
	}
	tmp = ft_strdup(*line_cp);
	*line_cp = *line_cp + i;
	return(tmp);
}

void	get_token_argv_bin(char **token, t_info *info)
{
	t_command *f_com;
	char *tmp;

	f_com = ft_new_com();
	info->command = f_com;
	*token =  ft_strtok(&info->parse->line_cp,info, "|<>");
	tmp = *token;
	*token = put_variable(info, *token, info->envp);
	if (*token != NULL)
	{
		parse_get_token_util(info, token);
	}
	while (*token != NULL)
	{
		free(*token);
		*token =  ft_strtok(&info->parse->line_cp,info, "|<>");
		*token = put_variable(info, *token, info->envp);
		if (*token != NULL)
		{
			parse_get_token_util(info, token);
		}
	}
	info->command = f_com;
}

void parse(t_info *info) //ОБРАБОАТЬ ЕСЛИ НЕ НАШЕЛ КОМАНДУ
{
	char *line;
	char *token;


	token = NULL;
	line = ft_strtrim(info->text, " ");
	if (check_valid(info, line) == 0)
	{
		free(line);
		return;
	}
	info->parse->line_cp = line;
	get_token_argv_bin(&token, info);
	if (check_tokens(info) == 0)
	{
		free(line);
		return;
	}
	parse_place_bin(info);
	launch_command(info);
	free(line);
}
