#include "../minishell.h"

char	*exit_status_variable(t_info *info, char *str)
{
	free(str);
	str = ft_itoa(info->exit_status);
	return (str);
}

char	*skip_alpha(char *str)
{
	while (ft_isalpha(*str))
		str++;
	return (str);
}
