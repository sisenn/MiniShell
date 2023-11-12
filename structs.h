/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:04:30 by yokten            #+#    #+#             */
/*   Updated: 2023/11/06 20:08:22 by yokten           ###   ########.fr       */
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

typedef	struct	s_env
{
	char	*v_name;
	char	*v_value;
	struct	s_env *next;
}	t_env;

typedef struct s_core
{
	char			*input;
	t_lexer			*lexer;
	t_lexer			*lexer_head;
	char			**env;
	char			**expanded;
	int				i;
	int				j;
	int				k;
	int				l;
	int				t;
	int				control34;
	int				control39;
	int				flag;
	int				err_code;
}	t_core;

#endif
