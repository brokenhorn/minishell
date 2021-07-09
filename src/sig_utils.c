#include "../includes/minishell.h"

void	sig_slash(int code)
{
	(void)code;
	printf("\b\b");
}

void	sig_init(int code)
{
	(void)code;
	//g_sig.sigint = 1;
//	rl_redisplay();

}
