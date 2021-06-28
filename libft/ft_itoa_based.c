/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_based.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:28:26 by vmaricru          #+#    #+#             */
/*   Updated: 2021/01/22 15:29:38 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkintb(long int n, int zero, int base)
{
	long int	n1;

	n1 = n;
	while (n1 != 0)
	{
		zero++;
		n1 /= base;
	}
	return (zero);
}

char	*ft_fitb(char *m, long int n1, int zero, int base)
{
	int	chk;
	int	d;

	*(m + zero - 1) = '\0';
	while (n1 != 0)
	{
		d = ft_isdigit(chk = n1 % base + '0');
		if (d)
			*(m + zero - 2) = chk;
		else
			*(m + zero - 2) = chk + 'a' - 10 - '0';
		n1 /= base;
		zero--;
	}
	if (zero == 2)
		*m = '-';
	return (m);
}

char	*ft_ifzerob(char *m)
{
	m = malloc(2 * sizeof(char));
	if (m == 0)
		return (0);
	m[0] = '0';
	m[1] = '\0';
	return (m);
}

char	*ft_itoa_based(long int n, int base)
{
	int			zero;
	long int	n1;
	char		*m;

	n1 = n;
	m = 0;
	if (n == 0)
		return (ft_ifzerob(m));
	zero = 1;
	n1 = n;
	zero = ft_checkintb(n1, zero, base);
	m = malloc(zero * sizeof(char));
	if (m == 0)
		return (0);
	return (ft_fitb(m, n1, zero, base));
}
