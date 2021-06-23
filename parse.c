#include "minishell.h"

void init_parse(t_info *info)
{
	info->parse->qu = 0;
	info->parse->opn = 0;
	info->parse->rd_nbr = 0;
}

void find_envp(t_info *info)
{

}

char *get_cmd(char *line)
{
	int i;
	int j;
	char *cp;

	i = 0;
	j = 0;
	while(line[i] != ' ' && line[i] != '$' && line[i] != '|' &&
	line[i] != '\'' && line[i] != '"')
		i++;
	cp = (char *) malloc(sizeof(char) * i + 1);
	while (j != i)
	{
		cp[j] = line[i];
		j++;
	}
	cp[i] = '\0';
	return(cp);
}

int get_text(t_info *info, int i, char *line, char smb)
{
	int j;
	int q;

	q = i;
	j = 0;
	i++;
	while (line[q] != smb)
	{
		q++;
		j++;
	}


}

int get_redirect(t_info *info, int i, char *line) // НАПИСАТЬ РЕДИРЕКТ РЕАЛОК
{
	if (line[i + 1] == '<' && line[i] == '<')
		redirect_realloc(info, S2);
	else if (line[i + 1] == '>' && line[i] == '>')
		redirect_realloc(info, B2);
	if (line[i] == '<')
		redirect_realloc(info, S1);
	if (line[i] == '>')
		redirect_realloc(info, B1);
}

char *check_input(t_info *info, char *line)
{
	int opn;
	int i;
	char *cmd;
	char *cp;

	cmd = NULL;
	i = 0;
	while (line[i] != '\0')
	{
		 //  проверить первый символ редирект
		 if ((line[i] == '<' || line[i] == '>') && info->parse->opn != 1 )
		 	i = get_redirect(info, i, line);
		if (line[i] == '|' && cmd == NULL && info->parse->opn != 1)
			exit(-1); // error
		if (line[i] == '\'' && info->parse->qu != 2)
		{
			info->parse->qu = 1;
			info->parse->opn++;
			i = get_text(info, i, line,'\'');
		}
		else if(line[i] == '"' && info->parse->qu != 1)
		{
			info->parse->qu = 2;
			info->parse->opn++;
			i = get_text(info, i, line, '"');
		}
		if(line[i] == '$' && info->parse->qu != 1)
		{
			if (info->parse->qu != 1)
				find_envp(info); // объединять строки плюсануть текст
		}
		if (line[i] != ' ' && line[i] != '<' &&
			line[i] != '>' && line[i] != '|' && opn != 1 && cmd == NULL)
			cmd = get_cmd(&line[i]); // malloc
		if ((line[i] == '<' || line[i] == '>') && info->parse->opn != 1 )
		{

		}
		if (info->parse->opn == 2)
		{
			info->parse->opn = 0;
			info->parse->qu = 0;
		}
		i++;
	}
	if (info->parse->opn == 1)
		exit(-1); // error
}
void parse(t_info *info)
{
	char *line;

	init_parse(info);
	info->command->text = (char *)malloc(sizeof(char));

	line = info->history->text;
	line = check_input(info, line);
}