/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:48:55 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/31 09:33:36 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** watch out! 	while (i <= f->current_path) <= !!!
*/

t_bool	init_path_lengths(t_map *f)
{
	if ((f->len = (int *)malloc(sizeof(int) * (f->current_path + 1))) == NULL)
		return (false);
	if ((f->pos = (t_position *)malloc(sizeof(t_position) * f->ants)) == NULL)
	{
		free(f->len);
		f->len = NULL;
		return (false);
	}
	if ((f->ants_in_paths = (int *)malloc(sizeof(int) *
	(f->current_path + 1))) == NULL)
	{
		free(f->pos);
		f->pos = NULL;
		free(f->len);
		f->len = NULL;
		return (false);
	}
	count_paths_length(f);
	set_all_ant_initial_location(f);
	set_0_ants_in_paths(f);
	return (true);
}

void	add_start_end_to_paths(t_map *f)
{
	int i;
	int j;

	i = 0;
	while (i <= f->current_path)
	{
		j = 0;
		while (j < f->max_order)
		{
			if (f->paths[i][j] == -1)
				break ;
			j++;
		}
		if (j + 1 < f->max_order)
			f->paths[i][j + 1] = f->end_vertex;
		while (j > 0)
		{
			f->paths[i][j] = f->paths[i][j - 1];
			j--;
		}
		f->paths[i][0] = f->start_vertex;
		i++;
	}
}

/*
** if sth wrong then free all memory here
** otherwise we print all ants going forward
** and free all farm in main.c
*/

t_bool	caravane_goes_farward(t_map *f)
{
	int curr_ants;

	add_start_end_to_paths(f);
	if (init_path_lengths(f) == false)
		return (false);
	curr_ants = f->ants;
	count_ants_in_paths(f, &curr_ants);
	curr_ants = f->ants;
	set_and_move_ants(f, &curr_ants);
	return (true);
}
