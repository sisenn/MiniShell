/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:59:21 by yokten            #+#    #+#             */
/*   Updated: 2022/12/28 19:24:22 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (s[len])
	{
		if (s[len] == (unsigned char)c)
			return ((char *)&s[len]);
		len++;
	}
	if (c == '\0')
		return ((char *)&s[len]);
	return (NULL);
}
