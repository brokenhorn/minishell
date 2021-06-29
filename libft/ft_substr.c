/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:52:43 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/08 19:01:41 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (size <= start)
	{
		substr = malloc(1);
		*substr = '\0';
		return (substr);
	}
	size = ft_min(size - start, len);
	len = 0;
	substr = malloc(size + 1);
	if (substr == 0)
		return (0);
	while (len++ < size)
		substr[len - 1] = s[start + len - 1];
	substr[len - 1] = '\0';
	return (substr);
}
