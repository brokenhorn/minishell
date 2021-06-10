/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:47:42 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/10/30 20:47:45 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
		int c, size_t n)
{
	unsigned char *d;
	unsigned char *s;
	unsigned char value;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	value = (unsigned char)c;
	while (n--)
	{
		*d = *s++;
		if (*d == value)
			return (d + 1);
		d++;
	}
	return (0);
}
