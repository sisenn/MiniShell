/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:51:53 by ckarakus          #+#    #+#             */
/*   Updated: 2023/12/11 05:45:31 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process(t_main *main)
{
	if (main->process_iterator != 0)
	{
		dup2(main->exec_fd, 0);
		close(main->exec_fd);
	}
	if (main->process_iterator != main->pipe_count)
	{
		dup2(main->io[1], 1);
		close(main->exec_fd);
	}
	close(main->io[0]);
	close(main->io[1]);
	ft_access(main);
	clear_history();
	if (!ft_strncmp(main->lexer_list->content, "<<", 2))
	{
		dup2(main->heredoc_fd[0], STDIN_FILENO);
		close(main->heredoc_fd[1]);
	}
	execve(main->res[main->k], main->arg, main->env2);
}
