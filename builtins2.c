
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