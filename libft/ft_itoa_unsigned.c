/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:24:48 by vmaricru          #+#    #+#             */
/*   Updated: 2021/01/22 15:26:04 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_malloc(char **str, long int ncopy, int size)
{
	if (ncopy < 0)
		*str = malloc(size + 2);
	else
		*str = malloc(size + 1);
}

int	ft_nbrlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	int				size;
	char			*str;
	long int		ncopy;

	ncopy = n;
	size = ft_nbrlen(n);
	ft_itoa_malloc(&str, ncopy, size);
	if (str == 0)
		return (0);
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
