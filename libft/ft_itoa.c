/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:04:55 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/17 17:54:29 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_itoa_malloc(char **str, long int ncopy, int size)
{
	if (ncopy < 0)
		*str = malloc(size + 2);
	else
		*str = malloc(size + 1);
}

char			*ft_itoa(int n)
{
	int			size;
	char		*str;
	long int	ncopy;

	ncopy = n;
	size = ft_nbrlen(n);
	ft_itoa_malloc(&str, ncopy, size);
	if (str == 0)
		return (0);
	if (ncopy < 0)
	{
		str[0] = '-';
		ncopy = ncopy * (-1);
		size++;
	}
	str[size--] = '\0';
	if (ncopy == 0)
		str[size] = '0';
	while (ncopy)
	{
		str[size--] = ncopy % 10 + '0';
		ncopy = ncopy / 10;
	}
	return (str);
}
