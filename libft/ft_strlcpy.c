/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 22:34:54 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/12 22:13:18 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		n;
	size_t	size_copy;

	if (!(dst) || !(src))
		return (0);
	size_copy = size;
	n = 0;
	while (src[n] != '\0' && size-- > 1)
	{
		dst[n] = src[n];
		n++;
	}
	if (size_copy > 0)
		dst[n] = '\0';
	return ((size_t)ft_strlen(src));
}
