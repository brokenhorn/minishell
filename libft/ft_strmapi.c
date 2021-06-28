/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:48:14 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/10 18:07:09 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*m;
	int		i;

	if (s == 0)
		return (0);
	i = 0;
	m = malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (m == 0)
		return (0);
	*(m + ft_strlen((char *)s)) = '\0';
	while (s[i] != '\0')
	{
		m[i] = (*f)(i, s[i]);
		i++;
	}
	return (m);
}
