/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 09:17:52 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/26 08:29:32 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** function that calculates hashes for
** string *str of length len
** we do % only in case the value exceeds the ring
*/

int		hash_calculate(char *str, int len, int hash_size)
{
	int		value;
	int		i;

	value = 0;
	i = 0;
	while (i < len)
	{
		value = value * 37 + str[i];
		if (value >= hash_size)
			value = value % hash_size;
		i++;
	}
	return (value);
}

void	assign_start_end_status(t_map *f, t_status st)
{
	if (st == begin)
		f->start_vertex = f->max_order;
	else if (st == end)
		f->end_vertex = f->max_order;
	f->max_order++;
}

/*
** function creates v vertex and assigns st status (start,middle,end)
** name of vertex *line [without coordinates!], and order in graph
** then increases f->max_order by 1.
** Obviosely, when finished max_order will keep total number of vertice
** We parse the room until backspace
** Then we parse room coordinates
** The room coordinates end strictly with some digit.
*/

t_bool	assign_line_to_hashmap(t_map *f, t_status st, char *line)
{
	int		place;
	t_hash	*tmp_h;
	char	*backsp;

	if (!(tmp_h = (t_hash *)malloc(sizeof(t_hash))))
		return (false);
	tmp_h->next = NULL;
	if ((backsp = ft_strchr(line, ' ')) == NULL ||
	((tmp_h->v = vertex_init(line, backsp - line, st, f->max_order))) == NULL)
		return (false);
	assign_start_end_status(f, st);
	place = hash_calculate(line, backsp - line, f->hash_size);
	if (f->first_raw[place] == NULL)
		f->first_raw[place] = tmp_h;
	else
	{
		tmp_h->next = f->first_raw[place];
		f->first_raw[place] = tmp_h;
	}
	backsp = ft_atoi_pointer(backsp, &(tmp_h->v->x));
	backsp = ft_atoi_pointer(backsp, &(tmp_h->v->y));
	if (*backsp != '\0')
		return (false);
	return (true);
}

/*
** now we have encountered ##start or ##end
** it means we need to free the current line and read next line
** the next line should be room.
** The next coming line after free(line) should be not 0 length,
** doesn't contain '-' and not comment
*/

char	*assign_start_end_to_hashmap(t_map *f, char *line, t_status st)
{
	int		res;

	free(line);
	res = get_next_line(0, &line);
	if (res == 0)
		return (NULL);
	if (!is_room(line))
		return (NULL);
	if (assign_line_to_hashmap(f, st, line) == false)
		return (NULL);
	return (line);
}
