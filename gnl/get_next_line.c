/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:40:01 by vmaricru          #+#    #+#             */
/*   Updated: 2021/04/22 23:26:46 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rmd(char *buffer)
{
	char		*m;
	int			i;

	i = 0;
	while (*buffer != '\n')
		buffer++;
	m = (char *)malloc(sizeof(char) * ft_strlen(buffer));
	if (m == 0)
		return (NULL);
	buffer++;
	while (buffer[i] != '\0')
	{
		m[i] = buffer[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}

int	ft_er_clean(char *str, char **rmd, char *buffer)
{
	if (str)
		free(str);
	if (*rmd)
		free(*rmd);
	*rmd = NULL;
	if (buffer)
		free(buffer);
	return (-1);
}

int	ft_read_line(char **rmd, int fd, char **line, char *buffer)
{
	int			rd;
	char		*str;

	str = ft_strjoin(NULL, *rmd);
	rd = read(fd, buffer, BUFFER_SIZE);
	while (rd)
	{
		if (rd == -1)
			return (ft_er_clean(str, rmd, buffer));
		buffer[rd] = '\0';
		str = ft_strjoin(str, buffer);
		if (ft_strchr(buffer, '\n'))
		{
			if (*rmd)
				free(*rmd);
			*rmd = ft_rmd(buffer);
			if (!*rmd)
				return (-1);
			free_strbuffer(str, buffer, line);
			return (1);
		}
		rd = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_rd_zero(line, rmd, str, buffer));
}

int	ft_check_rmd(char **rmd, char **line)
{
	char		*str;
	char		*rmd_free;

	rmd_free = *rmd;
	str = ft_strjoin(NULL, *rmd);
	if (ft_strchr(*rmd, '\n'))
	{
		ft_strchngz_zero(str);
		*rmd = ft_rmd(*rmd);
		if (!*rmd)
			return (-1);
		free(rmd_free);
		*line = ft_strjoin(NULL, str);
		free(str);
		return (1);
	}
	else
		free(str);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*rmd = NULL;
	int			check;
	int			f;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	check = 0;
	if (rmd)
		check = ft_check_rmd(&rmd, line);
	if (check)
		return (1);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	f = ft_read_line(&rmd, fd, line, buffer);
	return (f);
}
