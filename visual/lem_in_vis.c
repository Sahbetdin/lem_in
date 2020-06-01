/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_vis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 09:18:37 by btrifle           #+#    #+#             */
/*   Updated: 2020/06/01 13:56:45 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

/*
** some constrains: ant number is integer
** x, y room coordinates are greater than 0
** farm.max_paths is initiated and calculated in graph_fill_in
*/

int			flags(int argc, char **argv)
{
	int		i;
	int		ret;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-h") || ft_strequ(argv[i], "--help"))
		{
			ft_putstr("Usage:\n./lem-in [-h --help] [-v --visual] < map");
			return (0);
		}
		if (ft_strequ(argv[i], "-v") || ft_strequ(argv[i], "--visual"))
			return (1);
		i++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_map	farm;
	t_bool	vis;
	int		i;

	vis = false;
	if (flags(argc, argv) == 1)
		vis = true;
	if (initiate_all_variables(&farm) == false)
		return (0);
	if (vis == true)
		visual1(&farm);
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
	if (vis == true)
		visual2(&farm);
	delete_hash_map_without_neighbours_with_others(&farm);
	return (0);
}
