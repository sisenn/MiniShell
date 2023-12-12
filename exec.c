/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:25:17 by ckarakus          #+#    #+#             */
/*   Updated: 2023/12/11 05:44:49 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(t_main	*main)
{
	pipe(main->io);
	if (main->lexer_list->content[0] != '\0')
	{
		main->pid2 = fork();
		if (main->pid2 < 0)
		{
			printf("fork error\n");
			exit(1);
		}
		if (main->pid2 == 0)
			child_process(main);
		if (main->process_iterator != 0)
			close(main->exec_fd);
		close(main->io[1]);
		main->exec_fd = main->io[0];
		main->process_iterator++;
	}
}

void	ft_access(t_main *main)
{
	main->z = -1;
	main->env2 = malloc(sizeof(char *) * 100);
	parse_path(main);
	main->z = count_args(main);
	main->arg = malloc(sizeof(char *) * (main->z + 1));
	create_arg(main);
	main->env_list = main->env_head;
	main->z = 0;
	while (main->env_list)
	{
		main->env2[main->z++] = main->env_list->content;
		main->env_list = main->env_list->next;
	}
}

int	count_args(t_main *main)
{
	int	i;

	i = 1;
	main->lexer_tmp = main->lexer_list;
	while (main->lexer_list->next && (main->lexer_list->next->type == ARGUMENT
			|| main->lexer_list->next->type == REDIRECTION))
	{
		i++;
		main->lexer_list = main->lexer_list->next;
	}
	main->lexer_list = main->lexer_tmp;
	return (i);
}

void	parse_path(t_main *main)
{
	char	*slash_content;

	main->env_list = main->env_head;
	while (main->env_list)
	{
		if (!ft_strncmp(main->env_list->content, "PATH=", 5))
			break ;
		main->env_list = main->env_list->next;
	}
	if (main->lexer_list->content[0] != '/' && ft_strncmp(main->lexer_list->content, "./", 2))
	{
		main->res = ft_split(&main->env_list->content[5], ':');
		slash_content = ft_strjoin("/", main->lexer_list->content);
		while (main->res[++main->z])
			main->res[main->z] = ft_strjoin(main->res[main->z], slash_content);
	}
	else
		main->res = ft_split(main->lexer_list->content, '\0');
	main->k = -1;
	while (main->res[++main->k])
	{
		if (!access(main->res[main->k], F_OK))
			break ;
	}
	if (main->res[main->k] == NULL)
	{
		if (ft_strcmp(main->lexer_list->content, "exit"))
			printf("command not found: %s\n", main->lexer_list->content);
		exit(127);
	}
}

void	create_arg(t_main *main)
{
	main->arg[0] = main->lexer_list->content;
	main->z = 1;
	while (main->lexer_list->next && (main->lexer_list->next->type == ARGUMENT
			|| main->lexer_list->next->type == REDIRECTION))
	{
		main->lexer_list = main->lexer_list->next;
		if (main->lexer_list->type == ARGUMENT)
		{
			main->arg[main->z] = main->lexer_list->content;
			main->z++;
		}
		if (main->lexer_list->type == REDIRECTION)
		{
			ft_redirections(main);
			break ;
		}
	}
	main->arg[main->z] = NULL;
}
