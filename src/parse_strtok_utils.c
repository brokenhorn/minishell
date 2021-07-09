#include "../includes/minishell.h"

void close_opn(t_info *info)
{
	if(info->parse->opn == 2)
	{
		info->parse->opn = 0;
		info->parse->qu = 0;
	}
}
void rise_one_q(t_info *info, char sym)
{
	if(sym == '\'' && info->parse->qu != 2)
	{
		info->parse->qu = 1;
		info->parse->opn++;
	}
}

void rise_two_q(t_info *info, char sym)
{
	if (sym == '"' && info->parse->qu != 1)
	{
		info->parse->qu = 2;
		info->parse->opn++;
	}
}

void check_delim(t_info *info, char delim, char next_s)
{
	if (delim == '|')
		info->command->flag = PIPE;
	else if (delim == '<' && next_s != delim)
		info->command->flag = S1;
	else if (delim == '>' && next_s != delim)
		info->command->flag = B1;
}