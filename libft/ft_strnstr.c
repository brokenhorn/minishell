/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:13:28 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/02 19:32:13 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack,
		const char *needle, size_t len)
{
	int		n;

	n = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		while (haystack[n] == needle[n] && len - n > 0)
		{
			if (needle[n + 1] == '\0')
				return ((char *)haystack);
			n++;
		}
		n = 0;
		haystack++;
		len--;
	}
	return (0);
}
