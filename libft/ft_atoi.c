/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:46:54 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/14 17:38:53 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkborder(long s)
{
	if (s == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	r;
	long	s;
	int		i;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		if (r == 999999999)
			return (ft_checkborder(s));
		i++;
	}
	return (s * r);
}
