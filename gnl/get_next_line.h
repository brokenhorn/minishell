/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:35:41 by vmaricru          #+#    #+#             */
/*   Updated: 2021/01/16 21:16:33 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 20
int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strchngz_zero(char *str);
size_t	ft_strlenn(char *s);
int		ft_rd_zero(char **line, char **rmd, char *str, char *buffer);
char	*ft_rmd(char *buffer);
int		ft_read_line(char **rmd, int fd, char **line, char *buffer);
int		ft_check_rmd(char **rmd, char **line);
void	free_strbuffer(char *str, char *buffer, char **line);
#endif
