#include "minishell.h"

void	init_core(t_core *core)
{
	core->i = 0;
	core->j = 0;
	core->k = 0;
	core->l = 0;
	core->t = 0;
	core->flag = 0;
	core->err_code = 0;
	core->env = NULL;
	core->expanded = NULL;
	core->pwd = NULL;
}
