/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:22:29 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/10 17:40:20 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	pl;

	s1 = (unsigned char *)s;
	pl = (unsigned char)c;
	while (n--)
	{
		if (*s1 == pl)
			return (s1);
		s1++;
	}
	return (0);
}
