#include "../includes/minishell.h"



char *allocate_str(char *line_cp, int count, t_info *info, char delim)
{
	int j;
	char *str;

	str = (char *) malloc(sizeof(char) * count);
	j = 0;
	if (delim == '|')
		info->command->flag = PIPE; // ПРОВЕРКА НА ОШИБКУ ВИДА <<< <<> и тд
	else if (delim == '<' && line_cp[count] != delim)
		info->command->flag = S1;
	else if (delim == '>' && line_cp[count] != delim)
		info->command->flag = B1;
	else if (delim == '<' && line_cp[count] == delim)
		info->command->flag = S2;
	else if (delim == '>' && line_cp[count] == delim)
		info->command->flag = B2;
	while (line_cp[j] != delim)
	{
		str[j] = line_cp[j];
		j++;
	}
	str[j] = '\0';
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
		if ((*line_cp)[i] == '\'' && info->parse->qu != 2)
		{
			info->parse->qu = 1;
			info->parse->opn++;
		}
		if ((*line_cp)[i]== '"' && info->parse->qu != 1)
		{
			info->parse->qu = 2;
			info->parse->opn++;
		}
		while (delim[j] != '\0')
		{
			if ((*line_cp)[i] == delim[j] && info->parse->opn == 0)
			{
				token =	allocate_str(*line_cp, i + 1, info, delim[j]);
				*line_cp = *line_cp + i + 1;
				return (token);
			}
			j++;
		}
		if(info->parse->opn == 2)
		{
			info->parse->opn = 0;
			info->parse->qu = 0;
		}
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
		info->command->argv = ft_split(*token, ' ');
		search_bin(info);
		if (info->parse->line_cp != NULL && *(info->parse->line_cp) != '\0')
		{
			info->command->next = ft_new_com();
			info->command = info->command->next;
		}
	}
	while (*token != NULL)
	{
		free(*token);
		*token =  ft_strtok(&info->parse->line_cp,info, "|<>");
		*token = put_variable(info, *token, info->envp);
		if (*token != NULL)
		{
			info->command->argv = ft_split(*token, ' ');
			search_bin(info);
			if (info->parse->line_cp != NULL && *(info->parse->line_cp) != '\0')
			{
				info->command->next = ft_new_com();
				info->command = info->command->next;
			}
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
	check_valid(info, line);
	if (info->err_check == 1)
	{
		free(line);
		return;
	}
	info->parse->line_cp = line;
	check_valid(info, line);
	get_token_argv_bin(&token, info);
	launch_command(info);
	free(line);
}
