/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 16:36:15 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/28 21:22:54 by btrifle          ###   ########.fr       */
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

t_bool		move_one_step(t_map *f)
{
	int i;
	t_bool flag;

	i = 0;
	flag = false;
	while (i < f->ants && f->pos[i].loc < f->max_order)
	{
		if (f->pos[i].way != -1 &&
		f->paths[f->pos[i].way][f->pos[i].loc] != -1)
		{
			f->pos[i].loc++;
			flag = true;
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
/*
void	assign_paths_to_start(t_map *f, int *ants_n)
{
	int i;

	if (*ants_n == 0)
		return ;
	if (f->current_path == 0)
	{
		f->pos[f->ants - *ants_n].way = 0;
		return ;
	}
	f->pos[f->ants - *ants_n].way = 0;
	(*ants_n)--;
	f->ants_in_paths[0]++;
	i = 0;
	while (i <= f->current_path)
	{
		if (f->ants_in_paths[i] + f->len[i] < f->ants_in_paths[i + 1] + f->len[i + 1])
		
		if (f->len[i] <= f->ants_in_paths[i - 1] + f->len[i - 1])
		{
			f->pos[f->ants - *ants_n].way = i;
			(*ants_n)--;
			f->ants_in_paths[i]++;
		}
		else
			break ;
		i++;
	}
	return ;
}
*/

/*
** int curr_ants; - number of ants in the start
*/
/*
t_bool	caravane_goes_farward(t_map *f)
{
	int curr_ants;
	int flag;

	add_start_end_to_paths(f);
	if (set_path_lengths(f) == false)
		return (false);
// ft_printf("len[0] = %d\n", f->len[0]);
// ft_printf("len[1] = %d\n", f->len[1]);

	int i;
	i = 0;
	while (i < f->current_path)
	{
		ft_printf("len[%d] = %d\n", i, f->len[i]);
		i++;
	}

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
*/

void	assign_one_ant(t_map *f, int *j_addr, int *ants_n)
{
		(*ants_n)--;
		f->ants_in_paths[*j_addr]++;
		*j_addr = 0;
}


/*
** we take ant and look the sum: ants_in_path[i] + len[i].
** we compare it with the next i: ants_in_path[i + 1] + len[i + 1]
** if the first sum is greater or equal the second then we go to i + 1;
** otherwise count it to the current i;
** if we reach last path, then count ant to it.
*/

void	count_ants_in_paths(t_map *f, int *ants_n)
{
	int i;
	int j;

	if (f->current_path == 0)
	{
		f->ants_in_paths[0] = f->ants;
		return ;
	}
	i = 0;
	j = 0;
	while (j < f->current_path && *ants_n > 0)
	{
		if (f->len[j] + f->ants_in_paths[j] >=
		f->len[j + 1] + f->ants_in_paths[j + 1])
		{
			j++;
		}
		else
			assign_one_ant(f, &j, ants_n);
		if (j == f->current_path)
			assign_one_ant(f, &j, ants_n);
	}
}



	// i = 0;
	// while (i <= f->current_path)
	// {
	// 	f->ants_in_paths[i] = 0;
	// 	i++;
	// }

	// i = 0;
	// while (i <= f->current_path)
	// {
	// 	ft_printf("len[%d] = %d\n", i, f->len[i]);
	// 	i++;
	// }

void	set_and_move_ants(t_map *f, int *ants_n)
{
	// print_all_positions(f);
	t_bool flag; //можем кидать в пути
	int i;
	int *arr;
	
	arr = (int *)malloc(sizeof(int) * f->current_path + 1);
	i = 0;
	while (i <= f->current_path)
	{
		arr[i] = f->ants_in_paths[i];
		i++;
	}
	
	flag = true;
	while (flag)
	{
		i = 0;
		while (i <= f->current_path)
		{
			if (arr[i])
			{
				f->pos[f->ants - *ants_n].way = i;
				f->pos[f->ants - *ants_n].loc = 0;
				arr[i]--;
				(*ants_n)--;
			}
			i++;
		}
		flag = move_one_step(f);
		print_positions(f);
	}
	free(arr);
}


t_bool	caravane_goes_farward(t_map *f)
{
	int curr_ants;
	int i;
	
	add_start_end_to_paths(f);
	print_all_paths(f->paths, f->current_path + 1, f->max_order);

	if (set_path_lengths(f) == false)
		return (false);
	curr_ants = f->ants;
	i = 0;
	while (i < f->current_path)
	{
		f->ants_in_paths[i] = 0;
		i++;
	}
	count_ants_in_paths(f, &curr_ants);
	i = 0;
	while (i <= f->current_path)
	{
		ft_printf("ants in path[%d] = %d\n", i, f->ants_in_paths[i]);
		i++;
	}
	i = 0;
	while (i <= f->current_path)
	{
		ft_printf("len[%d] = %d\n", i, f->len[i]);
		i++;
	}
	curr_ants = f->ants;

	set_and_move_ants(f, &curr_ants);


	free(f->ants_in_paths);
	free(f->len);
	free(f->pos);
	return (true);
}
