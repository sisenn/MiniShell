/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:20:53 by ckarakus          #+#    #+#             */
/*   Updated: 2023/12/10 16:21:53 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_builtin2(t_main *main)
{
	if (!ft_strcmp(main->lexer_list->content, "export") && \
	!main->pipe_count && !main->redir_count)
		ft_export(main);
	else if (!ft_strcmp(main->lexer_list->content, "unset") && \
	!main->pipe_count && !main->redir_count)
		ft_unset(main);
	else if (!ft_strcmp(main->lexer_list->content, "env") && \
	!main->pipe_count && !main->redir_count)
		ft_env(main);
	else
		ft_exec(main);
}
