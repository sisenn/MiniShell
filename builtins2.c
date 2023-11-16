
#include "./minishell.h"

void	ft_pwd_management(t_core	*core)
{
	core->pwd = getcwd(core->pwd, 0);
	printf("%s\n", core->pwd);
}

void	ft_env_management(t_core	*core)
{
	core->i = 0;
	while (core->env[core->i])
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
		core->i = chdir("/Users/sisen"/*yokten*/);
	else if (core->lexer->next && core->lexer->next->type == 2)
		printf("cd: too many arguments\n");
	if (core->i < 0)
		printf("cd: no such file or directory: %s\n"
			, core->lexer->content);
	core->pwd = ft_strjoin("\033[0;35m", getcwd(core->pwd, 0));
	core->readline = ft_strjoin(core->pwd, " > monkeys 🙉🙊🙈 :\033[0;37m ");
}

void	add_to_export(t_core	*core)
{
	core->lexer = core->lexer->next;
	core->i = 0;
	while (core->export[core->i])
		core->i++;
	
}

void	ft_export_management(t_core	*core)
{
	core->i = 0;
	core->k = 0;
	if (core->lexer->next == NULL || core->lexer->next->type != 2)
	{
		while (core->export[core->k++]);
		core->k -= 2;
		while (0 < core->k)
		{
			while (core->i < core->k)
			{
				if (core->export[core->i][0] > core->export[core->i + 1][0])
				{
					core->swap = core->export[core->i + 1];
					core->export[core->i + 1] = core->export[core->i];
					core->export[core->i] = core->swap;
				}
				core->i++;
			}
			core->k--;
			core->i = 0;
		}
		core->i = 0;
		core->j = 0;
		while (core->export[core->i])
		{
			printf("declare -x ");
			while (core->export[core->i][core->j])
			{
				printf("%c", core->export[core->i][core->j++]);
				if (core->export[core->i][core->j - 1] == '=' || core->export[core->i][core->j] == '\0')
					printf("%c", 34);
			}
			printf("\n");
			core->i++;
			core->j = 0;
		}
	}
	else
	{
		add_to_export(core);
	}
}

/*	{
		printf("declare -x ");
		while (core->env[core->i][core->j])
		{
			printf("%c", core->env[core->i][core->j++]);
			if (core->env[core->i][core->j - 1] == '=' || core->env[core->i][core->j] == '\0')
				printf("%c", 34);
		}
		printf("\n");
		core->i++;
		core->j = 0;
	}*/