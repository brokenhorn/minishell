/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:06:52 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/10/30 20:06:54 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *copy;
	unsigned char value;

	copy = (unsigned char *)b;
	value = (unsigned char)c;
	while (len--)
	{
		*copy = value;
		copy++;
	}
	return (b);
}
