/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_bfs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 17:04:23 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/26 17:04:43 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_bool	work_with_bfs(t_map *f)
{
	char	b;

	if (bfs(f, f->start_vertex) == false)
		return (false);
	if (f->bfs_order[f->end_vertex] != -1)
		path_assign(f, f->paths[f->current_path]);
	else
		return (false);
	put_back_removed_arcs(f);
	if ((b = find_shortest_path_vertice_in_current_path(f)) == 2)
		b_2(f);
	else if (b == 1)
		b_1(f);
	else if (b == 0)
		b_0(f);
	return (true);
}
