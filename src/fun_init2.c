/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 09:18:10 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/31 13:06:06 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** initialize vertex.
** all it's fields are zeros except
** name which is ft_strdup(line)
*/

t_vertex	*vertex_init(char *name, int len, t_status st, int order)
{
	t_vertex *v_tmp;

	if (!(v_tmp = (t_vertex *)malloc(sizeof(t_vertex))))
		return (NULL);
	v_tmp->name = ft_strndup(name, len);
	if (v_tmp->name == NULL)
	{
		free(v_tmp);
		return (NULL);
	}
	v_tmp->len = len;
	v_tmp->neighbour = NULL;
	v_tmp->status = st;
	v_tmp->order = order;
	return (v_tmp);
}

/*
** farm_init(f); //initialize variables without allocation
** f->first_raw ... //initialize hash map
** all error messages during reading are in the functions
** for all erraneous things with map we free line here
** 	if (flag_read_map == false)
**		free(line);
*/

t_bool		initiate_all_variables(t_map *f)
{
	char	*line;
	t_bool	flag_read_map;

	line = NULL;
	farm_init(f);
	if ((f->first_raw = hashmap_init(f->first_raw, f->hash_size)) == NULL)
		return (0);
	flag_read_map = read_map(f, &line);
	if (flag_read_map == false)
	{
		ft_printf("ERROR in map\n");
		free(line);
		line = NULL;
		delete_hash_map_with_neighbours_without_graph(f);
		return (false);
	}
	if (graph_fill_in(f) == false ||
	init_bfs_order_short_path_paths(f) == false || bfs(f, f->start_vertex)
	== false || is_graph_connected(f) == false)
	{
		delete_hash_map_without_neighbours_with_others(f);
		return (false);
	}
	return (true);
}
