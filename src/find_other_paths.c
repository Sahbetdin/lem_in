/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_other_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:48:24 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/31 13:05:27 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** here we determine count and n_elem which are used in
** find_shortest_path_vertice_in_current_path
*/

void	count_rooms_in_current_path(t_map *f, int *c_addr, int *n_elem_addr)
{
	int i;
	int j;

	i = 0;
	while (i < f->max_order && f->shortest_path[i] != -1)
	{
		j = 0;
		while (j < f->max_order && f->paths[f->current_path][j] != -1)
		{
			if (f->shortest_path[i] == f->paths[f->current_path][j])
			{
				(*c_addr)++;
				break ;
			}
			j++;
		}
		(*n_elem_addr)++;
		i++;
	}
}

/*
** if f->shortest_path is totally present in f->paths[i],
** i.e. each vertex is present, then return 2
** else if f->shortest_path is partially present in f->paths[i], i.e.
** at least one, then return 1
** else if f->shortest_path doesn't have any common vertice
** with f->paths[i] then return 0
*/

char	find_shortest_path_vertice_in_current_path(t_map *f)
{
	int count;
	int	n_elem;

	count = 0;
	n_elem = 0;
	count_rooms_in_current_path(f, &count, &n_elem);
	if (n_elem == count)
		return (2);
	else if (count > 0)
		return (1);
	else
		return (0);
}

void	b_2(t_map *f)
{
	copy_paths(f->paths[0], f->shortest_path, f->max_order);
	delete_trace(f, f->paths[f->current_path]);
	while (f->current_path < f->max_paths)
	{
		bfs(f, f->start_vertex);
		if (f->bfs_order[f->end_vertex] == -1)
			break ;
		f->current_path++;
		path_assign(f, f->paths[f->current_path]);
		delete_trace(f, f->paths[f->current_path]);
	}
}

void	b_1(t_map *f)
{
	while (f->current_path < f->max_paths)
	{
		delete_trace(f, f->paths[f->current_path]);
		bfs(f, f->start_vertex);
		if (f->bfs_order[f->end_vertex] == -1)
			break ;
		f->current_path++;
		path_assign(f, f->paths[f->current_path]);
	}
}

/*
** if (f->bfs_order[f->end_vertex] == -1) //this case
** means that the graph is disconnected
** f->current_path = 1; //the next one is the 2nd
*/

void	b_0(t_map *f)
{
	copy_paths(f->paths[1], f->paths[0], f->max_order);
	copy_paths(f->paths[0], f->shortest_path, f->max_order);
	delete_trace(f, f->paths[0]);
	delete_trace(f, f->paths[1]);
	f->current_path = 1;
	while (f->current_path < f->max_paths)
	{
		bfs(f, f->start_vertex);
		if (f->bfs_order[f->end_vertex] == -1)
			break ;
		f->current_path++;
		path_assign(f, f->paths[f->current_path]);
		delete_trace(f, f->paths[f->current_path]);
	}
}
