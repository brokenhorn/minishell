#include "../includes/minishell.h"

void	parse_place_bin(t_info *info)
{
	t_command *tmp;

	tmp = info->command;
	while (info->command)
	{
		search_bin(info);
		info->command= info->command->next;
	}
	info->command = tmp;
}

void parse_get_token_util(t_info *info, char **token)
{
	info->command->argv = ft_split(*token, ' ');
	if (info->parse->line_cp != NULL && *(info->parse->line_cp) != '\0')
	{
		info->command->next = ft_new_com();
		info->command = info->command->next;
	}
}