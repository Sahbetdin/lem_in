/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_farm1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 17:40:45 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/26 18:52:25 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	delete_hash_table(t_hash **h, int hash_size)
{
	t_hash		*tmp;
	int			i;

	i = 0;
	while (i < hash_size)
	{
		tmp = h[i];
		delete_hash_node(&tmp);
		i++;
	}
	free(h);
}

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
	if (f->g)
	{
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
