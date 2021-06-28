/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:16:57 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/10 17:39:50 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*wdst;
	const unsigned char	*wsrc;
	unsigned char		c1;

	c1 = (unsigned char)c;
	wdst = (unsigned char *)dst;
	wsrc = (const unsigned char *)src;
	while (n--)
	{
		*wdst = *wsrc;
		if (*wdst == c1)
		{
			*wdst = *wsrc;
			return ((wdst + 1));
		}
		wdst++;
		wsrc++;
	}
	return (0);
}
