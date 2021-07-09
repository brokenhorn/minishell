#include "../includes/minishell.h"

void sig_slash()
{
	printf("\b\b");
}

void sig_init()
{
	g_sig.sigint = 1;
}