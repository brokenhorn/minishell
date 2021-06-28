/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:55:14 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/10 18:00:53 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*s1;
	int		i;

	if (s == 0)
		return (0);
	s1 = (char *)s;
	i = len;
	str = malloc(1 * len + 1);
	if (str == 0)
		return (0);
	s1 = s1 + start;
	if (start >= ft_strlen((char *)s))
	{
		*str = '\0';
		return (str);
	}
	while (i--)
		*str++ = *s1++;
	*str = '\0';
	str = str - len;
	return (str);
}
