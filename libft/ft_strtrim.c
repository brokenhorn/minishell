/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:11:28 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/10 18:03:21 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*m;
	size_t	s1size;
	int		len;

	if (s1 == 0 || set == 0)
		return (0);
	s1size = ft_strlen((char *)s1);
	while (s1size != 0 && ft_strchr(set, *(s1 + s1size - 1)))
		s1size--;
	while (s1size != 0 && ft_strchr(set, *s1))
	{
		s1++;
		s1size--;
	}
	m = malloc(1 * s1size + 1);
	len = s1size;
	if (m == 0)
		return (0);
	while (*s1 != '\0' && s1size > 0)
	{
		*m++ = *s1++;
		s1size--;
	}
	*m = '\0';
	return (m - len);
}
