/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisen <sisen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:03:37 by sisen             #+#    #+#             */
/*   Updated: 2023/12/14 17:03:38 by sisen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_node_t_exp(t_exp **exp, char *content)
{
	t_exp	*prev;
	t_exp	*node;

	prev = NULL;
	node = *exp;
	while (node != NULL)
	{
		if (ft_strncmp(node->content, content, ft_strlen(content)) == 0)
		{
			if (prev == NULL)
				*exp = node->next;
			else
				prev->next = node->next;
			free(node->content);
			free(node);
			return ;
		}
		prev = node;
		node = node->next;
	}
}

void	delete_node_t_env(t_env **env, char *content)
{
	t_env	*prev;
	t_env	*node;

	prev = NULL;
	node = *env;
	while (node != NULL)
	{
		if (ft_strncmp(node->content, content, ft_strlen(content)) == 0)
		{
			if (prev == NULL)
				*env = node->next;
			else
				prev->next = node->next;
			free(node->content);
			free(node);
			return ;
		}
		prev = node;
		node = node->next;
	}
}

void	replace_or_add_env(t_env **list, char *content)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = *list;
	while (content[i] && content[i] != '=')
		i++;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, content, i) == 0)
		{
			free(tmp->content);
			tmp->content = ft_strdup(content);
			return ;
		}
		tmp = tmp->next;
	}
	env_lstadd_back(list, env_listnew(ft_strdup(content)));
}

void	replace_or_add_exp(t_exp **list, char *content)
{
	t_exp	*tmp;
	int		i;

	i = 0;
	tmp = *list;
	if (!ft_isalpha(content[0]))
	{
		printf("minishell: export:`%s': not a valid identifier\n", content);
		return ;
	}
	while (content[i] && content[i] != '=')
		i++;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, content, i) == 0)
		{
			free(tmp->content);
			tmp->content = ft_strdup(content);
			return ;
		}
		tmp = tmp->next;
	}
	export_lstadd_back(list, export_listnew(ft_strdup(content)));
}
