/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 13:54:48 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/06/01 13:59:28 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		print_tail_and_system(FILE *file, t_map *f)
{
	fprintf(file, "],\n\"ants\": %d,\n", f->ants);
	fprintf(file, "\"paths_count\": %d\n", f->current_path + 1);
	fprintf(file, "}\n");
	system("if ! ps aux | grep -v grep | grep 'php -S localhost:8000'\
		&>/dev/null; then php -S localhost:8000 &>/dev/null & fi");
	system("open -a \"Google Chrome\" http://localhost:8000/visual/");
}

void		visual2(t_map *f)
{
	FILE	*file;
	int		cp;
	int		i;

	cp = 0;
	i = 0;
	file = fopen("./visual/data.json", "ad");
	while (cp <= f->current_path)
	{
		i = 0;
		fprintf(file, "{ \"id\": %d, \"ants\": %d, \"nodes\":[",
				cp, f->ants_in_paths[cp]);
		while (i < f->max_order && f->paths[cp][i] != -1)
		{
			fprintf(file, "\"%s\"", f->rooms_ordered[f->paths[cp][i++]]);
			if (i < f->max_order && f->paths[cp][i] != -1)
				fprintf(file, ", ");
			else
				fprintf(file, "] }");
		}
		cp++;
		if (cp <= f->current_path)
			fprintf(file, ",\n");
	}
	print_tail_and_system(file, f);
}
