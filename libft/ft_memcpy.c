/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:37:43 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/10 17:41:15 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*wdst;
	unsigned char	*wsrc;

	if (dst == 0 && src == 0)
		return (dst);
	wdst = (unsigned char *)dst;
	wsrc = (unsigned char *)src;
	while (n--)
		*wdst++ = *wsrc++;
	return (dst);
}
