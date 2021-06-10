/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:07:13 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/02 19:31:51 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*answer;

	answer = 0;
	while (*s != '\0')
	{
		if (*s == c)
			answer = (char *)s;
		s++;
	}
	if (*s == c)
		answer = (char *)s;
	return (answer);
}
