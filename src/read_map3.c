/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 09:19:36 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/29 18:04:15 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		count_neighb(t_linked *lst)
{
	int count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int		min_of_two(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_bool	allocate_graph_and_rooms_ordered(t_map *f)
{
	if (!(f->g = (t_linked **)malloc(sizeof(t_linked *) * f->max_order)))
	{
		ft_printf("ERROR memory allocation for graph(t_linked **)\n");
		return (false);
	}
	if (!(f->rooms_ordered = (char **)malloc(sizeof(char *) * f->max_order)))
	{
		free(f->g);
		ft_printf("ERROR memory allocation for rooms_ordered(char **)\n");
		return (false);
	}
	return (true);
}

/*
** alocate memory of links for neighbours.
** then assign to each node (which is type of t_linked)
** its own neighbour
*/

t_bool	graph_fill_in(t_map *f)
{
	int			i;
	t_hash		*tmp_h;
	t_vertex	*tmp_v;
	t_linked	*tmp_lst;

	if (allocate_graph_and_rooms_ordered(f) == false)
		return (false);
	i = -1;
	while (++i < f->hash_size)
	{
		tmp_h = f->first_raw[i];
		while (tmp_h)
		{
			tmp_v = tmp_h->v;
			tmp_lst = tmp_v->neighbour;
			f->g[tmp_v->order] = tmp_v->neighbour;
			f->rooms_ordered[tmp_v->order] = tmp_v->name;
			tmp_h = tmp_h->next;
		}
	}
	return (true);
}
