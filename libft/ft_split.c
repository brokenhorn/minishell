/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:41:44 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/14 18:48:54 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_counts(const char *strim, char c)
{
	int	j;

	j = 0;
	while (*strim != c && *strim != '\0')
	{
		j++;
		strim++;
	}
	return (j);
}

int	ft_clear(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
	return (0);
}

int	ft_fitin(char **a, int i, char *strim, char c)
{
	int	j;
	int	k;

	k = 0;
	while (*strim == c)
		strim++;
	while (i--)
	{
		j = ft_counts(strim, c);
		a[k] = (char *)malloc((j + 1) * sizeof(char));
		if (a[k] == 0)
			return (ft_clear(a));
		j = 0;
		while (*strim != c && *strim != '\0')
		{
			a[k][j] = *strim;
			j++;
			strim++;
		}
		a[k][j] = '\0';
		while (*strim == c && *strim != '\0')
			strim++;
		k++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	char	*strim;
	size_t	slen;
	int		i;

	if (s == 0)
		return (0);
	i = 0;
	strim = (char *)s;
	slen = ft_strlen(strim);
	while (*strim != '\0')
	{
		if ((*(strim + 1) == c || *(strim + 1) == '\0') && *strim != c)
			i++;
		strim++;
	}
	strim = strim - slen;
	a = (char **)malloc((i + 1) * sizeof(char *));
	if (a == 0)
		return (0);
	a[i] = NULL;
	if (ft_fitin(a, i, strim, c) == 0)
		return (NULL);
	return (a);
}
