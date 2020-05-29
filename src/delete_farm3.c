/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_farm3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:27:31 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/29 17:33:09 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	farm_delete(t_map *f)
{
	delete_hash_table(f->first_raw, f->hash_size);
	del_bfs_order(f);
	del_shortest_path(f);
	del_graph(f);
	del_paths(f);
	del_ants_in_paths_len_pos(f);
}
