/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohnnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:55:22 by tjohnnie          #+#    #+#             */
/*   Updated: 2020/11/20 17:40:25 by tjohnnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_split_count(const char *s, char c)
{
	int		size;

	size = 0;
	while (*s != '\0' && *s != c)
	{
		size++;
		s++;
	}
	return (size);
}

static const char	*ft_split_skip(const char *s, char c)
{
	while (*s == c && *s != '\0')
		s++;
	return (s);
}

static char			**ft_split_free(char **str, int n)
{
	while (n--)
		free(str[n]);
	free(str);
	return (0);
}

static char			**ft_split_end(char **str, int n)
{
	if (str)
		str[n] = 0;
	return (str);
}

char				**ft_split(char const *s, char c)
{
	char	**str;
	int		size;
	int		n;

	if (!s)
		return (0);
	n = 0;
	size = 1;
	while (s[n] != '\0')
		if (s[n++] != c && (s[n] == '\0' || s[n] == c))
			size++;
	if (!(str = (char **)malloc(size * sizeof(char *))))
		return (0);
	n = 0;
	s = ft_split_skip(s, c);
	while (*s != '\0' && str)
	{
		size = ft_split_count(s, c);
		if (!(str[n] = malloc(size + 1)))
			str = ft_split_free(str, n);
		else
			ft_strlcpy(str[n++], s, size + 1);
		s = ft_split_skip(s + size, c);
	}
	return (ft_split_end(str, n));
}
