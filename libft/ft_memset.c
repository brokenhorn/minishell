/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:25:12 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/01 19:10:14 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b1;
	unsigned char	c1;

	b1 = (unsigned char *)b;
	c1 = (unsigned char)c;
	while (len != 0)
	{
		*b1 = c1;
		b1++;
		len--;
	}
	return (b);
}
