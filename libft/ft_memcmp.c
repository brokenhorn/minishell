/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:48:16 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/02 20:53:19 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	unsigned char	value1;
	unsigned char	value2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (n--)
	{
		if (*c1 != *c2)
		{
			value1 = (unsigned char)*c1;
			value2 = (unsigned char)*c2;
			return (value1 - value2);
		}
		c1++;
		c2++;
	}
	return (0);
}
