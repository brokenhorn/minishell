#include "../includes/minishell.h"

void	cntrl_d(void)
{
	printf("\b\b");
	printf("exit\n");
	exit(0);
}
