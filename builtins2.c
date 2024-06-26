/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisen <sisen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:01:54 by sisen             #+#    #+#             */
/*   Updated: 2023/12/14 17:01:56 by sisen            ###   ########.fr       */
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
		printf("env: %s: No such file or directory\n", \
		main->lexer_list->next->content);
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
