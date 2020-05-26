/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_edges.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 08:21:15 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/26 08:31:40 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** in path_assign we find the shortest path from bfs
** arc, arc2 are the arcs from start_vertex to 1st nearest node
** determined by bfs
*/

void	delete_edge_temporaly(t_map *f)
{
	if (f->found_shortest_path == false)
	{
		path_assign(f, f->shortest_path);
		f->arc1 = delete_arc(f, f->start_vertex, f->shortest_path[0]);
		f->arc2 = delete_arc(f, f->shortest_path[0], f->start_vertex);
		if (f->arc1 == NULL || f->arc2 == NULL)
			ft_printf("no arcs!!\n");
		f->found_shortest_path = true;
	}
}

/*
** bring back deleted edge
** to each vertex
*/

void	put_back_removed_arcs(t_map *f)
{
	f->arc2->next = f->g[f->arc1->data];
	f->g[f->arc1->data] = f->arc2;
	f->arc1->next = f->g[f->arc2->data];
	f->g[f->arc2->data] = f->arc1;
}
