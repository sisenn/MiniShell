/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:16:39 by ckarakus          #+#    #+#             */
/*   Updated: 2023/12/10 12:32:17 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	declare_export(t_main	*main)
{
	printf("declare -x ");
	while (main->export_list->content[main->i])
	{
		printf("%c", main->export_list->content[main->i]);
		if (main->export_list->content[main->i] == '=')
		{
			main->flag = 1;
			printf("%c", 34);
		}
		main->i++;
		if (main->export_list->content[main->i] == '\0' && main->flag == 1)
		{
			printf("%c", 34);
			main->flag = 0;
		}
	}
	main->i = 0;
	main->export_list = main->export_list->next;
	printf("\n");
}

void	ft_unset(t_main *main)
{
	if (main->lexer_list->next)
		main->lexer_list = main->lexer_list->next;
	if (main->lexer_list->content)
	{
		main->tmp_joined = ft_strjoin(main->lexer_list->content, "=");
		delete_node_t_exp(&main->export_head, main->tmp_joined);
		delete_node_t_env(&main->env_head, main->tmp_joined);
	}
}

int	exit_numeric_control(char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
	{
		i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}