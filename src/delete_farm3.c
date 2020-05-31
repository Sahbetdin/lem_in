/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_farm3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 12:50:32 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/31 12:51:34 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	del_nodes(t_map *f)
{
	int		i;
	t_hash	*tmp;

	i = 0;
	while (i < f->hash_size)
	{
		tmp = f->first_raw[i];
		delete_hash_node(&tmp);
		i++;
	}
}

void	del_raws(t_map *f)
{
	if (f->first_raw)
	{
		free(f->first_raw);
		f->first_raw = NULL;
	}
}

void	del_rooms(t_map *f)
{
	if (f->rooms_ordered)
	{
		free(f->rooms_ordered);
		f->rooms_ordered = NULL;
	}
}

void	del_ants_in_paths_len_pos(t_map *f)
{
	if (f->ants_in_paths)
	{
		free(f->ants_in_paths);
		f->ants_in_paths = NULL;
	}
	if (f->len)
	{
		free(f->len);
		f->len = NULL;
	}
	if (f->pos)
	{
		free(f->pos);
		f->pos = NULL;
	}
	if (f->rooms_ordered)
	{
		free(f->rooms_ordered);
		f->rooms_ordered = NULL;
	}
}

void	del_paths(t_map *f)
{
	int		i;

	i = 0;
	while (i < f->max_paths)
	{
		free(f->paths[i]);
		f->paths[i] = NULL;
		i++;
	}
	free(f->paths);
	f->paths = NULL;
}
