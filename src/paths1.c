/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 16:36:15 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/29 18:12:10 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

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

void	set_arr_temporarly(t_map *f, int *arr)
{
	int i;

	i = 0;
	while (i <= f->current_path)
	{
		arr[i] = f->ants_in_paths[i];
		i++;
	}
}

void	set_ants_to_paths_tmp(t_map *f, t_bool flag, int *arr, int *ants_n)
{
	int i;

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
}

/*
** here 'flag' means that there are ants left
** and we can still assign them to paths.
*/

t_bool	set_and_move_ants(t_map *f, int *ants_n)
{
	t_bool	flag;
	int		*arr;

	if ((arr = (int *)malloc(sizeof(int) * f->current_path + 1)) == NULL)
		return (false);
	set_arr_temporarly(f, arr);
	flag = true;
	set_ants_to_paths_tmp(f, flag, arr, ants_n);
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
	return (true);
}
