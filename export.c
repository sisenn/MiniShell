#include "./minishell.h"

void	init_tmp(t_core *core)
{
	core->i = 0;
	core->j = 0;
	core->lexer = core->lexer->next;
	core->lex_tmp = core->lexer;
	while (core->lexer && core->lexer->type == 2)
	{
		core->i++;
		core->lexer = core->lexer->next;
	}
	while (core->export[core->j])
		core->j++;
	core->i += core->j;
	core->j = -1;
	core->tmp = malloc(sizeof(char *) * (core->i + 1));
	while (core->export[++core->j])
		core->tmp[core->j] = core->export[core->j];
	while (core->tmp[++core->i])
		printf("%s\n", core->tmp[core->i]);
	core->lexer = core->lex_tmp;
	while (core->lexer && core->lexer->type == 2)
	{
		core->tmp[core->j++] = core->lexer->content;
		core->lexer = core->lexer->next;
	}
	env_and_exp(core);
}

void	env_and_exp(t_core	*core)
{
	core->j = 0;
	while (core->export[core->j])
		free(core->export[core->j++]);
	core->j = 0;
	while (core->env[core->j])
		free(core->env[core->j++]);
	free(core->export);
	free(core->env);
	//core->export = malloc(sizeof(char *) * core->i + 1);
	core->export = malloc(sizeof(char **));
	/*while (core->tmp[core->k])
	{
		if (ft_strchr(core->tmp[core->k], '='))
			core->l++;
		core->k++;
	}*/
	core->env = malloc(sizeof(char **));
	core->k = -1;
	core->l = 0;
	while (core->tmp[++core->k])
	{
		if (ft_strchr(core->tmp[core->k], '='))
			core->env[core->l++] = core->tmp[core->k];
		core->export[core->k] = core->tmp[core->k];
	}
	core->i = -1;
	while (core->tmp[++core->i])
		printf("%s\n", core->tmp[core->i]);
}

