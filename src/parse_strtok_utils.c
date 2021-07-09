#include "../includes/minishell.h"

void	close_opn(t_info *info)
{
	if (info->parse->opn == 2)
	{
		info->parse->opn = 0;
		info->parse->qu = 0;
	}
}

void	rise_one_q(t_info *info, char sym)
{
	if (sym == '\'' && info->parse->qu != 2)
	{
		info->parse->qu = 1;
		info->parse->opn++;
	}
}

void	rise_two_q(t_info *info, char sym)
{
	if (sym == '"' && info->parse->qu != 1)
	{
		info->parse->qu = 2;
		info->parse->opn++;
	}
}

int	check_delim(t_info *info, char delim, char next_s)
{
	int	step;

	step = 0;
	if (delim == '|')
		info->command->flag = PIPE;
	else if (delim == '<' && next_s != delim)
		info->command->flag = S1;
	else if (delim == '>' && next_s != delim)
		info->command->flag = B1;
	if (delim == '<' && next_s == delim)
	{
		info->command->flag = S2;
		step++;
	}
	else if (delim == '>' && next_s == delim)
	{
		info->command->flag = B2;
		step++;
	}
	return (step);
}

int	cmp_delim(char *delim, char **line_cp, t_info *info, char **token)
{
	int	j;

	j = 0;
	while (delim[j] != '\0')
	{
		if ((*line_cp)[info->parse_i] == delim[j] && info->parse->opn == 0)
		{
			*token = allocate_str(line_cp, info->parse_i + 1, info, delim[j]);
			return (1);
		}
		j++;
	}
	return (0);
}
