/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisen <sisen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:02:12 by sisen             #+#    #+#             */
/*   Updated: 2023/12/14 17:02:14 by sisen            ###   ########.fr       */
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

int	err_syntax(t_main *main)
{
	main->err_no = 258;
	printf("monkeshell: syntax error near unexpected token\n");
	return (0);
}

void	err_unexpected(void)
{
	printf("monkeshell: syntax error near unexpected token `newline'\n");
	exit(1);
}
