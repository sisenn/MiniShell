/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:47:01 by ckarakus          #+#    #+#             */
/*   Updated: 2022/12/23 16:30:49 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p;
	unsigned char	*s;

	s = (unsigned char *)src;
	p = (unsigned char *)dst;
	if (!s && !p)
		return (0);
	if (s < p)
		while (len--)
			p[len] = s[len];
	else
		ft_memcpy(p, s, len);
	return (dst);
}
