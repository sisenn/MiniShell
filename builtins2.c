
#include "./minishell.h"

void	ft_pwd_management(t_core	*core)
{
	core->pwd = getcwd(core->pwd, 0);
	printf("%s\n", core->pwd);
}

void	ft_env_management(t_core	*core)
{
	core->i = 0;
	while (core->env[core->i] && core->env[core->i] != NULL)
		printf("%s\n", core->env[core->i++]);
}

void	ft_chdir(t_core	*core)
{
	core->i = 0;
	core->pwd = ft_strjoin("\033[0;35m", getcwd(core->pwd, 0));

	if (core->lexer->next)
		core->lexer = core->lexer->next;
	if (core->lexer && core->lexer->type == 2)
		core->i = chdir(core->lexer->content);
	else if (!core->lexer->next)
		core->i = chdir("/Users/sisen");
	else if (core->lexer->next && core->lexer->next->type == 2)
		printf("cd: too many arguments\n");
	if (core->i < 0)
		printf("cd: no such file or directory: %s\n"
			, core->lexer->content);
	core->pwd = ft_strjoin("\033[0;35m", getcwd(core->pwd, 0));
	core->readline = ft_strjoin(core->pwd, " > monkeys 🙉🙊🙈 :\033[0;37m ");
}