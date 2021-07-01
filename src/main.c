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
	info->envp = malloc_envp(envp);

//	EXPORT
//	char **a = ft_split("p=123 12r r PWD=", ' ');
//	export(info, a);
//	export(info, NULL);
//	free_2arr(a);

// PUT_VARIABLE
	char *sstr = (char *)malloc(sizeof(char) * 52);
	ft_strlcpy(sstr, "hello $PWD\nhaha $r\n'$PATH'\n\"'$PATH'\"\n\'$\'PWD\n\"$\"PWD", 52);
	sstr = put_variable(sstr, info->envp);
	printf("%s\n", sstr);
	free(sstr);



//	while (1)
//	{
//		list->text = readline("BulochkaBao% ");
//		parse(info, envp);
//	}
	return (0);
}
