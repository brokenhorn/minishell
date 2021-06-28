/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:54:40 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/14 18:31:08 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned const char	*a1;
	unsigned const char	*a2;

	a1 = (unsigned const char *)s1;
	a2 = (unsigned const char *)s2;
	i = 0;
	while (i < n)
	{
		if (a1[i] == '\0')
			return (-a2[i]);
		if (a2[i] == '\0')
			return (a1[i]);
		if (a1[i] > a2[i] || a2[i] > a1[i])
			return (a1[i] - a2[i]);
		i++;
	}
	return (0);
}
