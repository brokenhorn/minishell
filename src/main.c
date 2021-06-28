#include "../minishell.h"

t_command	*new_com()
{
	t_command *com;

	com = (t_command *)malloc(sizeof(t_command));
	com->command = 0;
	com->file = 0;
	com->flag = 0;
	return (com);
}

int		main(__unused int argc,__unused char **argv, char **envp)
{
	t_command	*com;
	t_info		*info;

	com = new_com();
	info = (t_info *)malloc(sizeof(t_info));
	info->command = com;

	export(envp);
//	char* const args1[] = {"/bin/pwd", NULL};
//	execv("/bin/pwd", args1);
//
//	char* const args[] = {"/bin/cd", "Testing"};
//	execv("/bin/cd", args);
//	char* const args2[] = {"/bin/pwd", NULL};
//	execv("/bin/pwd", args1);
//	while (1)
//	{
//		list->text = readline("BulochkaBao% ");
//		parse(info, envp);
//	}
	return (0);
}
