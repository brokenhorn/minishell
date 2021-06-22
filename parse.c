#include "minishell.h"

void find_envp(t_info *info, char **envp)
{

}

char *check_quotes(t_info *info, char *line, char **envp)
{
	int qu;
	int opn;
	int i;
	char *cmd;
	char *cp;

	cp = malloc(sizeof(char) * 2);
	cp[1] = '\0';
	i = 0;
	qu = 0;
	opn = 0;
	while (line[i] != '\0')
	{
		cp[0] = line[i]; // команда заканчивается пробелом проверить первый символ редирект
		if (line[i] != ' ')
		{
			if (cmd == NULL)
				cmd = ft_strjoin(cmd,cp);
			if (line[i] !=)
		}
		if (line[i] == '\'' && qu != 2)
		{
			qu = 1;
			opn++;
		}
		else if(line[i] == '"' && qu != 1)
		{
			qu = 2;
			opn++;
		}
		if(line[i] == '$')
		{
			if (qu != 1)
				find_envp(info, envp); // объединять строки
		}
		if (opn == 2)
			opn = 0;
		i++;
	}
	if (opn == 1)
		exit(-1); // error
}
void parse(t_info *info, char **envp)
{
	char *line;

	line = info->history->text;
	line = check_quotes(info, line, envp);
}