/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:03:17 by yokten            #+#    #+#             */
/*   Updated: 2023/11/06 20:03:40 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "structs.h"
# include "libft/libft.h"

t_lexer	*lexer_listnew(char *content);
t_lexer	*lexer_lstlast(t_lexer *lst);
t_env	*env_listnew(char   *name, char *value);
t_env	*env_lstlast(t_env *lst);
void	env_lstadd_back(t_env **lst, t_env *new);
void	lexer_lstadd_back(t_lexer **lst, t_lexer *new);
void    ft_error_handling(t_core    *core, int  flag);
void    init_core(t_core *core);
void    ft_builtins(t_core   *core);
void    ft_echo_management(t_core   *core);
void    ft_exit_management(t_core   *core);
int     echo_n_control(t_core   *core);

#endif
