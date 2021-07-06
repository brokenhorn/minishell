#include "../includes/minishell.h"

void sig_exit()
{
	exit(0);
}

void sig_init(int *signal)
{
	*signal = 1;
}