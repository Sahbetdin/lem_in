/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_farm1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:27:31 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/31 12:55:31 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	delete_hash_map_with_neighbours_without_graph(t_map *f)
{
	int			i;
	t_hash		*h;
	t_vertex	*v;

	i = 0;
	while (i < f->hash_size)
	{
		h = f->first_raw[i];
		while (h)
		{
			v = h->v;
			del_name(v->name);
			if (v->neighbour)
				delete_simple_linked_list(&v->neighbour);
			h = h->next;
		}
		i++;
	}
	del_vertice(f);
	del_nodes(f);
	del_raws(f);
}

void	delete_hash_map_without_neighbours_with_others(t_map *f)
{
	int			i;
	t_hash		*h;
	t_vertex	*v;

	i = 0;
	while (i < f->hash_size)
	{
		h = f->first_raw[i];
		while (h)
		{
			v = h->v;
			del_name(v->name);
			h = h->next;
		}
		i++;
	}
	del_graph(f);
	del_vertice(f);
	del_nodes(f);
	del_raws(f);
	del_bfs_order(f);
	del_shortest_path(f);
	del_rooms(f);
	del_paths(f);
	del_ants_in_paths_len_pos(f);
}

void	delete_adj_list(t_hash **h, int hash_size)
{
	t_hash		*tmp;
	t_linked	*head;
	int			i;

	i = 0;
	while (i < hash_size)
	{
		tmp = h[i];
		while (tmp)
		{
			head = tmp->v->neighbour;
			if (head)
				delete_simple_linked_list(&head);
			tmp = tmp->next;
		}
		i++;
	}
}
