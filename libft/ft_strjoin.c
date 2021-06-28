/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:57:32 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/10 18:02:38 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*m;

	if (s1 == 0 || s2 == 0)
		return (0);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	m = malloc(1 * len + 1);
	if (m == 0)
		return (0);
	while (*s1 != '\0')
		*m++ = *s1++;
	while (*s2 != '\0')
		*m++ = *s2++;
	*m = '\0';
	return (m - len);
}
