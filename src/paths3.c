/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 04:14:18 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/31 09:46:21 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** copy src_path to dest_path max n elements.
** if encounter -1 then stop
** the result is that all src_path should be in dest_path.
** even -1 elements
*/

void	copy_paths(int *dest_path, int *src_path, int n)
{
	int			i;

	i = 0;
	while (i < n && (src_path[i] != -1 || dest_path[i] != -1))
	{
		dest_path[i] = src_path[i];
		i++;
	}
}

/*
** used for reversing paths since, the elements start from end_vertex.
** the path consists of nodes and then -1's
** reverses arr without taking into account -1's;
** b is temporary value
*/

void	reverse_array(int *arr, int n)
{
	int			i;
	int			i_2;
	int			j;
	int			b;

	i = -1;
	while (i < n && arr[++i] != -1)
		;
	i_2 = i / 2;
	j = 0;
	while (j < i_2)
	{
		b = arr[j];
		arr[j] = arr[i - 1 - j];
		arr[i - 1 - j] = b;
		j++;
	}
}

/*
** we take bfs_order and from that find the current paths
** we go frontwards starting from end_vertex to next neighbour
** which has bfs_order 1 less than the node's
** after all we reverse that path, so that it starts with initial room
*/

void	path_assign(t_map *f, int *arr)
{
	int			node;
	int			i;
	t_linked	*tmp;

	node = f->end_vertex;
	i = 0;
	while (f->bfs_order[node] != 1)
	{
		tmp = f->g[node];
		while (tmp)
		{
			if (f->bfs_order[tmp->data] == f->bfs_order[node] - 1)
				break ;
			tmp = tmp->next;
		}
		arr[i] = tmp->data;
		i++;
		node = tmp->data;
	}
	reverse_array(arr, f->max_order);
}

/*
** start - initial room index
** n - number of ants
** loc - location field is initialized with start's index which is obviusly 0
** way - which path is chosen? Initialized with -1.
** i is ant index
*/

void	set_all_ant_initial_location(t_map *f)
{
	int			i;

	i = 0;
	while (i < f->ants)
	{
		f->pos[i].way = -1;
		f->pos[i].loc = -1;
		i++;
	}
}

/*
** Now there are ants in the paths. We see that if the pos[i].way is not -1
** Thus until we haven't reached the end room
** we move pos[i].loc to the next location.
** if moved than return 1
** else we can't move and should stop
** here, room_n changed to max_order.
*/

t_bool	move_one_step(t_map *f)
{
	int			i;
	t_bool		flag;

	i = 0;
	flag = false;
	while (i < f->ants && f->pos[i].loc < f->max_order &&
	f->pos[i].way != -1)
	{
		if (f->paths[f->pos[i].way][f->pos[i].loc] != -1)
		{
			f->pos[i].loc++;
			flag = true;
		}
		i++;
	}
	return (flag);
}
