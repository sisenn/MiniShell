/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisen <sisen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:04:30 by yokten            #+#    #+#             */
/*   Updated: 2023/11/16 14:43:59 by sisen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_lexer
{
	char			*content;
	int				type;
	struct s_lexer	*next;
}	t_lexer;

typedef struct s_core
{
	char			*input;
	t_lexer			*lexer;
	t_lexer			*lexer_head;
	t_lexer			*lex_tmp;
	char			**env;
	char			**expanded;
	int				i;
	int				j;
	int				k;
	int				l;
	int				t;
	int				control34;
	int				control39;
	int				exp_env_size;
	int				flag;
	int				err_code;
	char			*env_joined;
	char			*pwd;
	char			*readline;
	char			**export;
	char			**tmp;
	char			**exp_env;
	char			*swap;
	char			*expander;
}	t_core;

#endif
