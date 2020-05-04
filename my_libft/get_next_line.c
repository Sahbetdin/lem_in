/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:45:19 by btrifle           #+#    #+#             */
/*   Updated: 2019/10/23 16:09:36 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We start with checking  residue (res).
** If nothing passed as res, we set up *line as \0.
** if it's not null we try to inspect \n there.
** it has ASCII code 10. If find, we divide res into two
** parts at place where \n is. 1st part strdup to *line,
** the other part copy so that res starts from it.
** if we can't find \n, we strdup the whole res to *line.
** and then clear the res.
** We return pointer (s) to \n in res  only in case we find \n.
** Otherwise, return NULL;
** After all, we have *line with memory allocated
** and res which was not freed.
*/

char		*read_from_res(char **res, char **line)
{
	char	*s;

	s = ft_strchr(*res, 10);
	if (s)
	{
		*s = '\0';
		*line = ft_strdup(*res);
		ft_strcpy(*res, ++s);
	}
	else
	{
		*line = ft_strdup(*res);
		ft_strclr(*res);
	}
	return (s);
}

/*
** This function starts work with res. It calls read_from_res.
** If it returns some place where
** \n lives [which is pointer s from read_from_res function],
** we finish the program. if it returns NULL, we go into cycle
** and read fd into buf until encounter \n.
** Afterwards, we have res with allocated memory.
** To pay attention to start with ret = 1.
** And we use pointer s for 2 purposes: to find \n in res and
** to find \n in buf [which is obviously read bytes].
*/

int			get_line(const int fd, char **line, char *res)
{
	char	buf[BUFF_SIZE + 1];
	char	*s;
	char	*tmp;
	int		ret;

	s = read_from_res(&res, line);
	ret = 1;
	while (!s && ((ret = read(fd, buf, BUFF_SIZE))))
	{
		buf[ret] = '\0';
		if ((s = ft_strchr(buf, 10)))
		{
			*s = '\0';
			ft_strcpy(res, ++s);
		}
		if (ret < 0)
			return (-1);
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || ret < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return ((ft_strlen(*line) || (res && ft_strlen(res)) || ret) ? 1 : 0);
}

/*
** function takes current list structure element with given fd.
** It releases list content, then releases list element.
*/

void		free_list(t_list **t, const int fd)
{
	t_list	*tmp;
	t_list	*head;

	head = *t;
	if (head->content_size == (size_t)fd)
	{
		free(head->content);
		tmp = head;
		head = head->next;
		free(tmp);
		*t = head;
		return ;
	}
	while (head)
	{
		tmp = head->next;
		if (tmp->content_size == (size_t)fd)
		{
			head->next = tmp->next;
			free(tmp->content);
			free(tmp);
		}
		head = head->next;
	}
}

/*
** This is main function as interface for the whole process
** described above. It creates linked list element with fd
** which comes as parameter. In case of new fd's it creates
** new list element. During different calls it first finds
** necessary list element then passes it to get_line function.
*/

int			get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*tmp;
	int				k;

	if (fd < 0 || line == 0)
		return (-1);
	if (!head)
		head = ft_lstnew_gnl(BUFF_SIZE, (size_t)fd);
	tmp = head;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			break ;
		else if (tmp->next == NULL)
			tmp->next = ft_lstnew_gnl(BUFF_SIZE, (size_t)fd);
		tmp = tmp->next;
	}
	k = get_line(fd, line, tmp->content);
	if (k == 0)
		free_list(&head, fd);
	return (k);
}
