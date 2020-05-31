/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 20:54:33 by mjacques          #+#    #+#             */
/*   Updated: 2020/05/30 15:04:29 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


typedef struct	s_gnl_var
{
	int			size;
	char		buff[BUFF_SIZE + 1];
	char		*pos;
	char		*tmp;
}				t_gnl_var;

char	*free_join(char *s1, char *s);
char	*free_append(char *s1, char s);
char	*ft_strappend(char *str, char c);
char	*ft_strmcpy(const char *src, size_t len);


char	*free_join(char *s1, char *s)
{
	char *tmp;

	tmp = ft_strjoin(s1, s);
	ft_strdel(&s1);
	s1 = tmp;
	return (s1);
}

char	*free_append(char *s1, char s)
{
	char *tmp;

	tmp = ft_strappend(s1, s);
	ft_strdel(&s1);
	s1 = tmp;
	return (s1);
}

char	*ft_strappend(char *str, char c)
{
	int		len;
	char	*newstr;

	len = ft_strlen(str);
	newstr = (char *)malloc(sizeof(char) * len + 2);
	ft_strcpy(newstr, str);
	newstr[len] = c;
	newstr[len + 1] = '\0';
	return (newstr);
}


char	*ft_strmcpy(const char *src, size_t len)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	i = -1;
	while (src[++i] && i < len)
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}


int		get_next_line(const int fd, char **line)
{
	t_gnl_var	var;
	static char *str[8192];

	ft_memset(var.buff, 0, BUFF_SIZE);
	if (fd < 0 || fd > 8192 || !line || (var.size = read(fd, var.buff, 1)) < 0)
		return (-1);
	!str[fd] ? str[fd] = ft_strnew(0) : 0;
	if (var.size == 0 && !(ft_strchr(str[fd], '\n'))
		&& ft_strlen(str[fd]) < 1)
		return (0);
	str[fd] = free_append(str[fd], var.buff[0]);
	while (!(var.pos = ft_strchr(str[fd], '\n'))
		&& (var.size = read(fd, var.buff, BUFF_SIZE)))
	{
		var.buff[var.size] = '\0';
		str[fd] = free_join(str[fd], var.buff);
	}
	var.size = (int)(var.pos - str[fd]);
	(!var.pos) ? (var.size = ft_strlen(str[fd])) : 0;
	*line = ft_strmcpy(str[fd], var.size);
	(var.pos) ? (var.size += 1) : 0;
	var.tmp = ft_strdup(&str[fd][var.size]);
	ft_strdel(&str[fd]);
	str[fd] = var.tmp;
	return (1);
}
