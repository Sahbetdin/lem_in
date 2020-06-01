/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_circuit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 16:31:54 by btrifle           #+#    #+#             */
/*   Updated: 2020/06/01 16:41:47 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

char	*end_room_name(t_map *f)
{
	int			i;
	t_hash		*h;
	t_linked	*tmp;

	i = 0;
	while (i < f->hash_size)
	{
		h = f->first_raw[i];
		while (h)
		{
			if (h->v->status == 2)
				return (h->v->name);
			h = h->next;
		}
		i++;
	}
	return (NULL);
}

void	print_short_circuit(t_map *f, char *str)
{
	int			i;

	i = 0;
	while (i < f->ants)
	{
		ft_printf("L%d-%s ", i + 1, str);
		i++;
	}
	ft_printf("\n");
}

/*
** if start-end are linked we return 1
** otherwise return 0;
*/

t_bool	find_start_linked_list(t_map *f)
{
	int			i;
	t_hash		*h;
	t_linked	*tmp;

	i = 0;
	while (i < f->hash_size)
	{
		h = f->first_raw[i];
		while (h && h->v->order != f->start_vertex)
			h = h->next;
		if (h)
		{
			tmp = h->v->neighbour;
			while (tmp)
			{
				if (tmp->data == f->end_vertex)
					return (true);
				tmp = tmp->next;
			}
		}
		i++;
	}
	return (false);
}

t_bool	process_short_circuit(t_map *f)
{
	char	*end_n;

	if (find_start_linked_list(f) == false)
		return (false);
	end_n = end_room_name(f);
	print_short_circuit(f, end_n);
	delete_hash_map_with_neighbours_without_graph(f);
	return (true);
}
