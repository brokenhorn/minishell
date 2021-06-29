/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:32:40 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/17 19:30:00 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	dlen;

	dlen = ft_strlen(dst);
	len = ft_min(dlen, size) + ft_strlen(src);
	if (size > dlen)
	{
		dst = dst + dlen;
		size = size - dlen;
		while (size-- > 1 && *src != '\0')
			*dst++ = *src++;
		*dst = '\0';
	}
	return (len);
}
