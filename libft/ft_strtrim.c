/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:44:08 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/08 19:03:45 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	size;
	size_t	size_copy;

	if (!s1 || !set)
		return (0);
	size = ft_strlen(s1);
	while (size > 0 && ft_strchr(set, s1[size - 1]))
		size--;
	while (size > 0 && ft_strchr(set, *s1))
	{
		s1++;
		size--;
	}
	str = malloc(size + 1);
	if (str == 0)
		return (0);
	size_copy = size;
	while (size_copy--)
		*str++ = *s1++;
	*str = '\0';
	return (str - size);
}
