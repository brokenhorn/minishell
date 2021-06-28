/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:34:03 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/14 17:51:51 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len;
	size_t		dstlen;
	int			srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen((char *)src);
	len = dstlen + srclen;
	if (size <= dstlen)
		return (srclen + size);
	while (*dst)
		dst++;
	i = 0;
	while ((i < size - dstlen - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
