/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:27:16 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/14 17:31:18 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkint(long int n, int zero)
{
	long int	n1;

	n1 = n;
	while (n1 != 0)
	{
		zero++;
		n1 /= 10;
	}
	return (zero);
}

char	*ft_fit(char *m, long int n1, int zero)
{
	*(m + zero - 1) = '\0';
	while (n1 != 0)
	{
		*(m + zero - 2) = n1 % 10 + '0';
		n1 /= 10;
		zero--;
	}
	if (zero == 2)
		*m = '-';
	return (m);
}

char	*ft_ifzero(char *m)
{
	m = malloc(2 * sizeof(char));
	if (m == 0)
		return (0);
	m[0] = '0';
	m[1] = '\0';
	return (m);
}

char	*ft_itoa(long int n)
{
	int			zero;
	long int	n1;
	char		*m;

	n1 = n;
	m = 0;
	if (n == 0)
		return (ft_ifzero(m));
	zero = 1;
	n1 = n;
	if (n < 0)
	{
		n1 = n1 * (-1);
		zero++;
	}
	zero = ft_checkint(n1, zero);
	m = malloc(zero * sizeof(char));
	if (m == 0)
		return (0);
	return (ft_fit(m, n1, zero));
}
