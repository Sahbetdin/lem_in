/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 09:18:45 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/28 19:55:29 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** n is number of paths
** m is number of elements in a path (-1s inclusive)
** ft_printf("\033[0;33m"); //yellow
** ft_printf("\033[0m"); //white
*/

void	print_all_paths(int **arr, int n, int m)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		ft_printf("\033[0;33m");
		ft_printf("path[%d]:", i);
		ft_printf("\033[0m");
		j = 0;
		while (j < m && arr[i][j] != -1)
		{
			ft_printf(" %d ", arr[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_path(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		ft_printf("%d ", arr[i++]);
	ft_printf("\n");
}

void	print_all_positions(t_map *f)
{
	int i;

	ft_printf("\npositions:\n");
	i = 0;
	while (i < f->ants)
		ft_printf("%8d", i++);
	ft_printf("\n");
	i = 0;
	while (i < f->ants)
	{
		if (f->pos[i].way != -1)
			ft_printf("(%d,%d,[%d])  ", f->pos[i].way,
			f->pos[i].loc, f->paths[f->pos[i].way][f->pos[i].loc]);
		else
			ft_printf("(%d,%d)  ", f->pos[i].way, f->pos[i].loc);
		i++;
	}
	ft_printf("\n");
}

void	print_positions(t_map *f)
{
	int		i;
	t_bool	flag;

	i = 0;
	flag = false;
	while (i < f->ants)
	{
		// ft_printf("in printing pos: i = %d\n", i);
		if (f->pos[i].way != -1 &&
		f->paths[f->pos[i].way][f->pos[i].loc] != -1)
		{
			ft_printf("L%d-%d ", i + 1,
			f->paths[f->pos[i].way][f->pos[i].loc]);
			flag = true;
		}
		i++;
	}
	if (flag)
	ft_printf("\n");
}
