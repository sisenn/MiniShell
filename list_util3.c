/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:09:31 by ckarakus          #+#    #+#             */
/*   Updated: 2023/12/10 12:37:29 by ckarakus         ###   ########.fr       */
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
