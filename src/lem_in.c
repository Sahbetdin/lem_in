/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 09:18:37 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/28 17:26:51 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	print_usage(void)
{
	ft_printf("	USAGE: bla-bla-bla \n");
}

/*
** some constrains: ant number is integer
** x, y room coordinates are greater than 0
** farm.max_paths is initiated and calculated in graph_fill_in
*/

int		main(int argc, char **argv)
{
	t_map	farm;

	if (argc != 1)
	{
		print_usage();
		return (0);
	}
	if (initiate_all_variables(&farm) == false)
		return (0);
ft_printf("farm.max_paths = %d\n", farm.max_paths);
	// int i;
	// i = 0;
	// while (i < farm.max_order)
	// {
	// 	ft_printf("room[%d] is %s\n", i, farm.rooms_ordered[i]);
	// 	i++;
	// }
	if (farm.max_paths == 1)
		path_assign(&farm, farm.paths[0]);
	else
	{
		delete_edge_temporaly(&farm);
		if (work_with_bfs(&farm) == false)
			return (0);
	}

// ft_printf("farm.curr+path = %d\n", farm.current_path);
// print_all_paths(farm.paths, farm.current_path + 1, farm.max_order);

	if (caravane_goes_farward(&farm) == false)
		ft_printf("ERROR in paths");
	farm_delete(&farm);
	return (0);
}
