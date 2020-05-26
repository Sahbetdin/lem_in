/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_farm2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 09:18:24 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/26 18:52:22 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	delete_names(t_hash **h, int hash_size)
{
	t_hash		*tmp;
	int			i;
	char		*ptr;

	i = 0;
	while (i < hash_size)
	{
		tmp = h[i];
		while (tmp)
		{
			ptr = tmp->v->name;
			free(ptr);
			ptr = NULL;
			tmp = tmp->next;
		}
		i++;
	}
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

void	del_paths(t_map *f)
{
	int	i;

	if (f->paths > 0)
	{
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
}

void	del_hash_table(t_map *f)
{
	t_linked	*lst;
	t_hash		*h;
	int			i;
	t_vertex	*v;

	i = 0;
	while (i < f->hash_size)
	{
		h = f->first_raw[i];
		while (h)
		{
			v = h->v;
			del_name(v->name);
			lst = v->neighbour;
			delete_simple_linked_list(&lst);
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

void	farm_delete(t_map *f)
{
	delete_hash_table(f->first_raw, f->hash_size);
	del_bfs_order(f);
	del_shortest_path(f);
	del_graph(f);
	del_paths(f);
}
