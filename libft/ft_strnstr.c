/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:51:09 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/10 17:56:40 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	char	*hs;

	hs = (char *)haystack;
	i = 0;
	if (*needle == '\0')
		return (hs);
	while (len != 0)
	{
		while ((*(hs + i) == *(needle + i)) && (len - i != 0))
		{
			if (*(needle + i + 1) == '\0')
				return (hs);
			i++;
		}
		i = 0;
		hs++;
		len--;
	}
	return (0);
}
