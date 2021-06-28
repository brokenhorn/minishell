/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:37:34 by vmaricru          #+#    #+#             */
/*   Updated: 2021/04/22 23:52:22 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3_libft/includes/get_next_line.h"

size_t	ft_strlen(char *s)
{
	int		i;

	if (s == NULL)
		return (0);
	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*s1;

	s1 = 0;
	ch = c;
	while (*s != '\0')
	{
		if (*s == ch)
			s1 = (char *)s;
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	if (s1 != 0)
		return ((char *)s1);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*m;
	char	*tmp;

	tmp = s1;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	m = malloc(sizeof(char) * len + 1);
	if (m == 0)
		return (0);
	while ((s1 != NULL) && (*s1 != '\0'))
		*m++ = *s1++;
	while ((s2 != NULL) && (*s2 != '\0'))
		*m++ = *s2++;
	*m = '\0';
	free(tmp);
	return (m - len);
}

void	ft_strchngz_zero(char *str)
{
	if (str == NULL)
		return ;
	while (*str)
	{
		if (*str == '\n')
			*str = '\0';
		str++;
	}
}

int	ft_rd_zero(char **line, char **rmd, char *str, char *buffer)
{
	if (!str)
	{
		*line = malloc(sizeof(char) * 1);
		if (*line == 0)
			return (-1);
		**line = '\0';
		free(*rmd);
		free(buffer);
		return (0);
	}
	*line = ft_strjoin(NULL, str);
	free(*rmd);
	*rmd = NULL;
	free(str);
	free(buffer);
	return (0);
}
