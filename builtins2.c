/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:11:52 by ckarakus          #+#    #+#             */
/*   Updated: 2023/12/10 15:24:53 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_main *main)
{
	char	*str;

	str = NULL;
	if (main->pwd != NULL)
		free(main->pwd);
	main->pwd = getcwd(str, 0);
	printf("%s\n", main->pwd);
}

void	ft_env(t_main *main)
{
	main->i = 0;
	main->env_list = main->env_head;
	if (main->lexer_list->next && main->lexer_list->next->type == ARGUMENT)
		printf("env: %s: No such file or directory\n", main->lexer_list->next->content);
	else
	{
		while (main->env_list)
		{
			printf("%s\n", main->env_list->content);
			main->env_list = main->env_list->next;
		}
		main->env_list = main->env_head;
	}
}

void	ft_export(t_main	*main)
{
	main->i = 0;
	main->export_list = main->export_head;
	if (main->lexer_list->next == NULL || main->lexer_list->next->type != 2)
	{
		while (main->export_list)
		{
			main->i++;
			main->export_list = main->export_list->next;
		}
		main->export_list = main->export_head;
		print_export(main);
	}
	else
		add_export_env(main);
}

void	print_export(t_main	*main)
{
	main->flag = 0;
	while (0 < --main->i)
	{
		while (main->export_list->next)
		{
			if (main->export_list->content[0] > \
			main->export_list->next->content[0])
			{
				main->export_tmp = main->export_list->next->content;
				main->export_list->next->content = main->export_list->content;
				main->export_list->content = main->export_tmp;
			}
			main->export_list = main->export_list->next;
		}
		main->export_list = main->export_head;
	}
	main->i = 0;
	while (main->export_list)
		declare_export(main);
}

void	add_export_env(t_main	*main)
{
	main->lexer_list = main->lexer_list->next;
	main->l = 0;
	export_lstadd_back(&main->export_list,
		export_listnew(ft_strdup(main->lexer_list->content)));
	while (main->lexer_list->content[main->l])
	{
		if (main->lexer_list->content[main->l] == '=')
		{
			env_lstadd_back(&main->env_list,
				env_listnew(ft_strdup(main->lexer_list->content)));
			break ;
		}
		main->l++;
	}
	if (main->lexer_list->next != NULL \
	&& main->lexer_list->next->type == ARGUMENT)
		add_export_env(main);
}
