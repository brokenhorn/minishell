/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:21:25 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/02 21:22:58 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*copy;
	unsigned char	value;

	copy = (unsigned char *)s;
	value = (unsigned char)c;
	while (n--)
	{
		if (*copy == value)
			return (copy);
		copy++;
	}
	return (0);
}
