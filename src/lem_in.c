/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 09:18:37 by btrifle           #+#    #+#             */
/*   Updated: 2020/06/01 16:39:38 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** some constrains: ant number is integer
** x, y room coordinates are greater than 0
** farm.max_paths is initiated and calculated in graph_fill_in
*/

int		flags1(int argc, char **argv)
{
	if (argc != 1 || ft_strequ(argv[0], "-h") || ft_strequ(argv[0], "--help"))
	{
		ft_putstr("Usage:\n./lem-in [-h --help] < map");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_map	farm;
	int		i;

	if (flags1(argc, argv) == 0)
		return (0);
	if (initiate_all_variables(&farm) == false)
		return (0);
	if (farm.max_paths == 1)
		path_assign(&farm, farm.paths[0]);
	else
	{
		delete_edge_temporaly(&farm);
		if (work_with_bfs(&farm) == false)
			return (0);
	}
	if (caravane_goes_farward(&farm) == false)
		ft_printf("ERROR in paths");
	delete_hash_map_without_neighbours_with_others(&farm);
	return (0);
}
