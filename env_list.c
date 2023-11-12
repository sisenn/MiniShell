/* 
#include "minishell.h"

t_env	*env_listnew(char   *name, char *value)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->v_name = ft_strdup(name);
    new->v_value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

t_env	*env_lstlast(t_env *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	env_lstadd_back(t_env **lst, t_env *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	else
		env_lstlast(*lst)->next = new;
}
 */