/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 06:34:15 by btrifle           #+#    #+#             */
/*   Updated: 2020/06/01 15:12:44 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_bool	init_paths_individually(t_map *f)
{
	int i;
	int j;

	i = 0;
	while (i < f->max_paths)
	{
		f->paths[i] = (int *)malloc(sizeof(int) * f->max_order);
		if (!f->paths[i])
		{
			j = 0;
			while (j < i)
			{
				free(f->paths[j]);
				j++;
			}
			return (false);
		}
		arr_fill_in_with_value(f->paths[i], f->max_order, -1);
		i++;
	}
	return (true);
}

/*
** here we initialize paths.
** f->max_paths is min of neighbours of start and end vertice
** if f->max_paths == 0 then return false
** f->paths is array of arrays (allocated max_order pieces)
*/

t_bool	init_paths(t_map *f)
{
	f->max_paths = min_of_two(count_neighb(f->g[f->start_vertex]),
			count_neighb(f->g[f->end_vertex]));
	if (f->max_paths < 1)
	{
		ft_printf("ERROR: couldn't find path\n");
		return (false);
	}
	f->paths = (int **)malloc(sizeof(int *) * f->max_paths);
	if (f->paths == NULL)
	{
		ft_printf("ERROR: memory allocation for paths\n");
		return (false);
	}
	if (init_paths_individually(f) == false)
	{
		ft_printf("ERROR: memory allocation for individual path\n");
		return (false);
	}
	return (true);
}

/*
** bfs_order used in bfs. Not initialized
** shortest_path is allocated and initialized with -1
** the error message for init_paths in that function
*/

t_bool	init_bfs_ord_short_path_paths(t_map *f)
{
	f->bfs_order = (int *)malloc(sizeof(int) * f->max_order);
	f->shortest_path = (int *)malloc(sizeof(int) * f->max_order);
	if (f->bfs_order == NULL || f->shortest_path == NULL)
	{
		if (f->bfs_order)
			free(f->bfs_order);
		if (f->shortest_path)
			free(f->shortest_path);
		ft_printf("ERROR memory allocation for bfs_order or shorteest path\n");
		return (false);
	}
	arr_fill_in_with_value(f->shortest_path, f->max_order, -1);
	if (init_paths(f) == false)
		return (false);
	return (true);
}

void	count_paths_length(t_map *f)
{
	int i;
	int j;

	i = 0;
	while (i <= f->current_path)
	{
		j = 0;
		while (j < f->max_order && f->paths[i][j] != -1)
			j++;
		f->len[i] = j;
		i++;
	}
}

void	set_0_ants_in_paths(t_map *f)
{
	int i;

	i = 0;
	while (i <= f->current_path)
	{
		f->ants_in_paths[i] = 0;
		i++;
	}
}
