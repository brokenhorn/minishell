/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:09:52 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/08 18:40:18 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_power(int a, int b)
{
	long int	answer;

	if (b == 0)
		return (1);
	answer = a;
	while (b-- > 1)
		answer = answer * a;
	return (answer);
}
