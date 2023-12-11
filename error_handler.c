/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:12:14 by ckarakus          #+#    #+#             */
/*   Updated: 2023/12/11 06:15:19 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_code(t_main	*main)
{
	main->lexer_list->content = ft_itoa(main->err_no);
}

void	start_shell2(t_main	*main, int status)
{
	if (main->input)
		ft_parser(main);
	main->lexer_list = main->lexer_head;
	while (main->lexer_list != NULL)
	{
		if (main->lexer_list->type == COMMAND)
			ft_builtin(main);
		if (!main->lexer_list || main->lexer_list->next == NULL)
			break ;
		main->lexer_list = main->lexer_list->next;
	}
	while (++main->x < main->pipe_count + 1)
		waitpid(main->pid2, &status, 0);
	main->err_no = status / 256;
	free_main(main);
	main->pipe_count = 0;
	main->redir_count = 0;
}
