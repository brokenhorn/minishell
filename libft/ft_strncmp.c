/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 13:37:34 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/02 21:27:11 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int answer;

	answer = 0;
	if (n > 0)
	{
		while (*s1 == *s2 && *s2 != '\0' && *s1 != '\0' && n > 1)
		{
			s1++;
			s2++;
			n--;
		}
		answer = (unsigned char)*s1 - (unsigned char)*s2;
	}
	return (answer);
}
