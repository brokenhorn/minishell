#include "minishell.h"

t_parse *init_parse(t_info *info)
{
	t_parse *parse;

	parse = (t_parse *)malloc(sizeof(t_parse));
	parse->qu = 0;
	parse->opn = 0;

	return (parse);
}

//int check_line_error(char *line)
//{
//	int i;
//	int check;
//
//	i = 0;
//	check = 0;
//	while (line[i] != '\0')
//	{
//		if (line[i] == ' ')
//			i++;
//		if
//
//	}
//}

//int ft_strtok_count(t_info *info, char *line, char *delim)
//{
//	int i;
//	int j;
//	int count;
//
//	i = 0;
//	count = 0;
//	while (line[i] != '\0')
//	{
//		j = 0;
//		if (line[i] == '\'' && info->parse->qu != 2)
//		{
//			info->parse->qu = 1;
//			info->parse->opn++;
//		}
//		if (line[i] == '"' && info->parse->qu != 1)
//		{
//			info->parse->qu = 2;
//			info->parse->opn++;
//		}
//		while (delim[j] != '\0')
//		{
//			if (info->parse->qu == 1)
//				break;
//			if (line[i] == delim[j])
//			{
//				if (delim[j] == line[i - 1] && line[i] !=)
//
//			}
//			j++;
//		}
//		if(info->parse->opn == 2)
//		{
//			info->parse->opn = 0;
//			info->parse->qu = 0;
//		}
//		i++;
//	}
//	if (info->parse->opn != 0)
//		exit(-1);
//	return (count)
//}

char *allocate_str(char *line_cp, int count, t_info *info, char delim)
{
	int j;
	char *str;

	str = (char *) malloc(sizeof(char) * count);
	j = 0;
	if (delim == '|')
		info->command->flag == PIPE; // ПРОВЕРКА НА ОШИБКУ ВИДА <<< <<> и тд
	else if (delim == '<' && line_cp[count] != delim)
		info->command->flag == S1;
	else if (delim == '>' && line_cp[count] != delim)
		info->command->flag == B1;
	else if (delim == '<' && line_cp[count] == delim)
		info->command->flag == S2;
	else if (delim == '>' && line_cp[count] == delim)
		info->command->flag == B2;
	while (line_cp[j] != delim)
	{
		str[j] = line_cp[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char *ft_strtok(char *line_cp, t_info *info, char *delim)
{
	int i;
	int j;
	//static char *line_cp = NULL;
	char *token;

	i = 0;
	token = NULL;
//	if (line_cp == NULL)
//		line_cp = line;
	while (line_cp[i] != '\0')
	{
		j = 0;
		if (line_cp[i] == '\'' && info->parse->qu != 2)
		{
			info->parse->qu = 1;
			info->parse->opn++;
		}
		if (line_cp[i] == '"' && info->parse->qu != 1)
		{
			info->parse->qu = 2;
			info->parse->opn++;
		}
		while (delim[j] != '\0')
		{
			if (line_cp[i] == delim[j] && info->parse->opn == 0)
			{
				token =	allocate_str(line_cp, i + 1, info, delim[j]);
				line_cp = line_cp + i + 1;
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
	if (*line_cp == '\0')
		return (NULL);
	return(line_cp);
}

void parse(t_info *info)
{
	char *line;
	char *line_cp;
	char *token;

	info->parse = init_parse(info);
	//check_line_error(info->history->text);
	line = ft_strtrim(info->history->text, " ");
	line_cp = line;
	token = ft_strtok(line_cp,info, "|<>"); // РАЗОБРАТЬСЯ С МАЛЛОКАМИ
	info->command->argv = ft_split(token, ' ');
	while (token != NULL)
	{
		token = ft_strtok(NULL ,info, "|<>");
	}
}
