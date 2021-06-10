/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:36:00 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/08 18:40:44 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	m;

	if (fd == -1)
		return ;
	m = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		m = m * (-1);
	}
	if (m > 9)
	{
		ft_putnbr_fd(m / 10, fd);
		ft_putnbr_fd(m % 10, fd);
	}
	else
		ft_putchar_fd(m + '0', fd);
}
