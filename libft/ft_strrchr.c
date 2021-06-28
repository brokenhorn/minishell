/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:38:04 by vmaricru          #+#    #+#             */
/*   Updated: 2020/10/30 18:50:21 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*s1;

	s1 = 0;
	ch = c;
	while (*s != '\0')
	{
		if (*s == ch)
			s1 = (char *)s;
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	if (s1 != 0)
		return ((char *)s1);
	return (0);
}
