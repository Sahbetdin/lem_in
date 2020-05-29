/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_bfs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 17:04:23 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/29 18:33:18 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_bool	work_with_bfs(t_map *f)
{
	char	b;

	if (bfs(f, f->start_vertex) == false || f->bfs_order[f->end_vertex] == -1)
	{
		ft_printf("ERROR during finding more than 1 path\n");
		farm_delete(f);
		return (false);
	}
	path_assign(f, f->paths[0]);
	print_path(f->paths[0], f->max_order);
	put_back_removed_arcs(f);
	if ((b = find_shortest_path_vertice_in_current_path(f)) == 2)
		b_2(f);
	else if (b == 1)
		b_1(f);
	else if (b == 0)
		b_0(f);
	ft_printf("b = %d\n", b);
	return (true);
}
