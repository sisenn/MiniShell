/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisen <sisen@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:04:12 by sisen             #+#    #+#             */
/*   Updated: 2023/12/14 17:04:13 by sisen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dollar_manage3(t_main *main, char *string)
{
	main->lexer_list->content = ft_string_join \
	(main->lexer_list->content, ft_substr(&string[main->a], 0, 1));
}
