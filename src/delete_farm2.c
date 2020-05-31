/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_farm2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 09:18:24 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/31 12:54:45 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	del_bfs_order(t_map *f)
{
	if (f->bfs_order)
	{
		free(f->bfs_order);
		f->bfs_order = NULL;
	}
}

void	del_shortest_path(t_map *f)
{
	if (f->shortest_path)
	{
		free(f->shortest_path);
		f->shortest_path = NULL;
	}
}

void	del_graph(t_map *f)
{
	int		i;

	if (f->g)
	{
		i = 0;
		while (i < f->max_order)
		{
			if (f->g[i])
				delete_simple_linked_list(f->g + i);
			i++;
		}
		free(f->g);
		f->g = NULL;
	}
}

void	del_name(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	del_vertice(t_map *f)
{
	int		i;
	t_hash	*h;

	i = 0;
	while (i < f->hash_size)
	{
		h = f->first_raw[i];
		while (h)
		{
			if (h->v)
			{
				free(h->v);
				h->v = NULL;
			}
			h = h->next;
		}
		i++;
	}
}
