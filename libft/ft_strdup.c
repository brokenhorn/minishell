/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:58:06 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/10 17:46:01 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*m;

	m = malloc(1 * ft_strlen((char *)s1) + 1);
	if (m == 0)
		return (0);
	ft_strlcpy(m, s1, ft_strlen((char *)s1) + 1);
	return (m);
}
