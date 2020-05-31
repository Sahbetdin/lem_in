/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_farm3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:27:31 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/31 09:23:57 by btrifle          ###   ########.fr       */
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
	int			i;

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

void del_vertice(t_map *f)
{
	int			i;
	t_hash		*h;
	
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

void	del_nodes(t_map *f)
{
	int			i;
	t_hash		*tmp;

	i = 0;
	while (i < f->hash_size)
	{
		tmp = f->first_raw[i];
		delete_hash_node(&tmp);
		i++;
	}
}

void	del_raws(t_map *f)
{
	if (f->first_raw)
	{
		free(f->first_raw);
		f->first_raw = NULL;
	}
}

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

void	del_rooms(t_map *f)
{
	if (f->rooms_ordered)
	{
		free(f->rooms_ordered);
		f->rooms_ordered = NULL;
	}
}


void	del_ants_in_paths_len_pos(t_map *f)
{
	if (f->ants_in_paths)
	{
		free(f->ants_in_paths);
		f->ants_in_paths = NULL;
	}
	if (f->len)
	{
		free(f->len);
		f->len = NULL;
	}
	if (f->pos)
	{
		free(f->pos);
		f->pos = NULL;
	}
	if (f->rooms_ordered)
	{
		free(f->rooms_ordered);
		f->rooms_ordered = NULL;
	}
}

void	del_paths(t_map *f)
{
	int			i;

	i = 0;
	while (i < f->max_paths)
	{
		free(f->paths[i]);
		f->paths[i] = NULL;
		i++;
	}
	free(f->paths);
	f->paths = NULL;
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
