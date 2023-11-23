#include    "minishell.h"

void    childforpipe(t_core *core, int flag)
{
	core->pipes[++core->z] = malloc(sizeof(char) * 2);
    if (flag <= 2)
    {
        pipe(core->pipes[core->z]);
        if ( pipe(core->pipes[core->z]) == -1)
            perror("pipe error!");
        else if (pipe(core->pipes[core->z]) == 0)
        {
            close (core->pipes[core->z][0]);
            dup2(core->pipes[core->z][1], 1);
            close (core->pipes[core->z][1]);
            core->lexer = core->lexer->next;
        }
    }
    else if (flag >= 2)
    {
        pipe(core->pipes[core->z]);
        if ( pipe(core->pipes[core->z]) == -1)
            perror("pipe error!");
        else if (pipe(core->pipes[core->z]) == 0)
        {
            dup2(1,1);
            dup2(core->pipes[core->z-1][0], 0);
            close(core->pipes[core->z-1][1]);
            close(core->pipes[core->z][0]);
        }
    }
}