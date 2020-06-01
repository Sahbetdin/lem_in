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

void		visual2(t_map *f)
{
	FILE	*file;
	char	*a = "{ \"data\": { \"id\": \"";
	char	*b = "\"}},\n";
	char	*start = f->rooms_ordered[f->start_vertex];
	char	*end = f->rooms_ordered[f->end_vertex];
	int		cp = 0;
	int		i = 0;

	file = fopen("./visual/data.json", "ad");
//   	print_all_paths(f->paths, f->max_paths, f->max_order);
   	while (cp <= f->current_path)
   	{
   	    i = 0;
   	    fprintf(file, "{ \"id\": %d, \"ants\": %d, \"nodes\":[", cp, f->ants_in_paths[cp]);
//		fprintf(file, " \"%s\", ", start);
		while (i < f->max_order && f->paths[cp][i] != -1)
   	    {
       	   	fprintf(file, "\"%s\"", f->rooms_ordered[f->paths[cp][i]] );
			i++;
			if (i < f->max_order && f->paths[cp][i] != -1)
				fprintf(file, ", ");
			else
				fprintf(file, "] }");
		}
		cp++;
		if (cp <= f->current_path)
			fprintf(file, ",\n");

	}
   	fprintf(file, "],\n\"ants\": %d,\n", f->ants);
   	fprintf(file, "\"paths_count\": %d\n", f->current_path+1);
   	fprintf(file, "}\n");
	system("if ! ps aux | grep -v grep | grep 'php -S localhost:8000' &>/dev/null; then php -S localhost:8000 &>/dev/null & fi");
	system("open -a \"Google Chrome\" http://localhost:8000/visual/");
}
