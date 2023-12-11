/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 06:08:08 by ckarakus          #+#    #+#             */
/*   Updated: 2023/12/11 06:29:06 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_heredoc(t_main	*main)
{
	char	*input;

	input = readline("> ");
	if (main->lexer_list->next->next && (
			main->lexer_list->next->next->type == REDIRECTION))
		start_heredoc2(main, input);
	if (!input || (!ft_strncmp(input, main->lexer_list->next->content,
				ft_strlen(main->lexer_list->next->content))
			&& ft_strlen(input) == \
			ft_strlen(main->lexer_list->next->content)))
	{
		free(input);
		return ;
	}
	else
	{
		write(main->heredoc_fd[1], input, ft_strlen(input));
		write(main->heredoc_fd[1], "\n", 1);
		free(input);
	}
}

void	start_heredoc2(t_main	*main, char *input)
{
	if (!ft_strncmp(main->lexer_list->next->content, input,
			ft_strlen(main->lexer_list->next->content)))
	{
		main->lexer_list = main->lexer_list->next->next;
	}
	ft_redirections(main);
	return ;
}
