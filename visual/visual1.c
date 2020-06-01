/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:06:58 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/06/01 17:59:10 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void			remove_comma(FILE *file)
{
	int			position;

	fseeko(file, -2, SEEK_END);
	position = ftello(file);
	ftruncate(fileno(file), position);
}

void			print_edge(FILE *file, t_map *f)
{
	int			i;
	int			j;
	t_linked	*tmp_lst;

	i = 0;
	j = 0;
	fprintf(file, "],\n\"edges\":\n[");
	while (i < f->max_order)
	{
		tmp_lst = f->g[i];
		while (tmp_lst)
		{
			fprintf(file, "{ \"data\": { \"id\": \"e%d\",\"source\":\""
				"%s\",\"target\":\"%s\"}},\n",
				j, f->rooms_ordered[i], f->rooms_ordered[tmp_lst->data]);
			tmp_lst = tmp_lst->next;
			j++;
		}
		i++;
	}
	remove_comma(file);
	fprintf(file, "],\n\"paths\":\n[");
}

void			visual1(t_map *f)
{
	FILE		*file;
	int			s;

	s = 0;
	file = fopen("./visual/data.json", "w");
	fprintf(file, "{\n\"nodes\": \n[");
	fprintf(file, "{ \"data\": { \"id\": \"%s\", \"type\": \"start\"}},\n",
			f->rooms_ordered[f->start_vertex]);
	fprintf(file, "{ \"data\": { \"id\": \"%s\", \"type\": \"end\"}},\n",
			f->rooms_ordered[f->end_vertex]);
	while (s < f->max_order)
	{
		if (f->rooms_ordered[s] == f->rooms_ordered[f->start_vertex]
			|| f->rooms_ordered[s] == f->rooms_ordered[f->end_vertex])
			s++;
		else
		{
			fprintf(file, "{ \"data\": { \"id\": \"%s", f->rooms_ordered[s]);
			fprintf(file, "\"}},\n");
			s++;
		}
	}
	fseeko(file, -2, SEEK_END);
	ftruncate(fileno(file), ftello(file));
	print_edge(file, f);
}
