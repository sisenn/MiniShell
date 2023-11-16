/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisen <sisen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:03:17 by yokten            #+#    #+#             */
/*   Updated: 2023/11/16 08:33:09 by sisen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "structs.h"
# include "libft/libft.h"

void	ft_unset_management(t_core *core);
t_lexer	*lexer_listnew(char *content);
t_lexer	*lexer_lstlast(t_lexer *lst);
void	lexer_lstadd_back(t_lexer **lst, t_lexer *new);
void	ft_error_handling(t_core *core, int flag);
void	init_core(t_core *core);
void	ft_builtins(t_core *core);
void	ft_echo_management(t_core	*core);
void	ft_exit_management(t_core	*core);
void	ft_pwd_management(t_core	*core);
void	ft_env_management(t_core	*core);
void	ft_export_management(t_core	*core);
void	add_to_export(t_core	*core);
int		echo_n_control(t_core *core);
void	ft_chdir(t_core	*core);

#endif
