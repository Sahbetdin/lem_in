/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 16:36:15 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/26 17:32:43 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

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
	int i;

	i = 0;
	while (i < f->ants)
	{
		f->pos[i].way = -1;
		f->pos[i].loc = 0;
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

int		move_one_step(t_map *f)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (i < f->ants && f->pos[i].loc < f->max_order)
	{
		if (f->pos[i].way != -1 &&
		f->paths[f->pos[i].way][f->pos[i].loc] != -1)
		{
			f->pos[i].loc++;
			flag = 1;
		}
		i++;
	}
	return (flag);
}

/*
** это сложно, но вроде справился.
** назначаем первому пришедшему мур самый короткий путь.
** уменьшаем ants_curr (текущее кол-во мур на 1). Теперь аккуратно!
** Надо решить, оставить ДРУГИХ мур ждать след ход, чтобы протащить их
** через тот же короткий путь, либо использовать следущий по длине путь, чтобы
** протащить 1-го муравья в текущем шаге.
** Чтобы протащать оставшееся кол-во через короткий путь надо
** ants_curr + len[0] - 1 путей. Чтобы протащить 1го мур в тек шаге нужно
** len[1] шагов. Их и сравниваем
** if not *ants_n - these are the ants in start, we only return.
** if (f->current_path == 1) - means only one path
** then: more than 1 ants at start and more than 1 paths
** in f->pos[f->ants - *ants_n].way = 0; we assign first ant in queue
** to shortest path
*/

void	assign_paths_to_start(t_map *f, int *ants_n)
{
	int i;

	if (*ants_n == 0)
		return ;
	if (f->current_path == 1)
	{
		f->pos[f->ants - *ants_n].way = 0;
		return ;
	}
	f->pos[f->ants - *ants_n].way = 0;
	(*ants_n)--;
	i = 1;
	while (i <= f->current_path)
	{
		if (f->len[i] <= *ants_n + f->len[0] - 1)
		{
			f->pos[f->ants - *ants_n].way = i;
			(*ants_n)--;
		}
		else
			break ;
		i++;
	}
	return ;
}

/*
** int curr_ants; - number of ants in the start
*/

t_bool	caravane_goes_farward(t_map *f)
{
	int curr_ants;
	int flag;

	add_start_end_to_paths(f);
	if (set_path_lengths(f) == false)
		return (false);
	curr_ants = f->ants;
	flag = 1;
	f->pos[0].way = 0;
	while (flag)
	{
		assign_paths_to_start(f, &curr_ants);
		flag = move_one_step(f);
		if (flag)
			print_positions(f);
	}
	free(f->len);
	free(f->pos);
	return (true);
}
