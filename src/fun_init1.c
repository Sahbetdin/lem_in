/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_init1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 09:17:58 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/28 11:58:53 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** initialize farm variables
** hash_size 100 used
** the only place where we allcate memory is hashmap_init
*/

void	farm_init(t_map *f)
{
	f->ants = 0;
	f->start_vertex = 0;
	f->end_vertex = 0;
	f->hash_size = 5;
	f->ants = 0;
	f->flag_ants = false;
	f->flag_start = false;
	f->flag_end = false;
	f->flag_rooms = false;
	f->flag_links = false;
	f->found_shortest_path = false;
	f->max_order = 0;
	f->bfs_order = NULL;
	f->g = NULL;
	f->shortest_path = NULL;
	f->paths = NULL;
	f->current_path = 0;
	f->max_paths = 0;
	f->arc1 = NULL;
	f->arc2 = NULL;
	f->pos = NULL;
	f->len = NULL;
	f->ants_in_paths = NULL;
}

/*
** allocate memory for hash table and initialize it with NULLs
*/

t_hash	**hashmap_init(t_hash **h, int hash_size)
{
	int i;

	h = (t_hash **)malloc(sizeof(t_hash *) * hash_size);
	if (h == NULL)
		return (NULL);
	i = -1;
	while (++i < hash_size)
		h[i] = NULL;
	return (h);
}

/*
** allocate memory of length n
** and initialize it with value
*/

int		*arr_init(int n, int value)
{
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
		arr[i++] = value;
	return (arr);
}

void	arr_fill_in_with_value(int *arr, int n, int value)
{
	int i;

	i = 0;
	while (i < n)
	{
		arr[i] = value;
		i++;
	}
}
