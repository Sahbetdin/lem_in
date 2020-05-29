/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_print1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 09:18:19 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/29 18:11:28 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	print_graph(t_linked **g, int n)
{
	int			i;
	t_linked	*tmp_lst;

	ft_printf("\nPRINT GRAPH:\n");
	i = 0;
	while (i < n)
	{
		tmp_lst = g[i];
		ft_printf("G[%d]: ", i);
		while (tmp_lst)
		{
			ft_printf("%d -> ", tmp_lst->data);
			tmp_lst = tmp_lst->next;
		}
		ft_printf("nil\n");
		i++;
	}
}

void	print_bfs_order(int *arr, int n)
{
	int			i;

	i = 0;
	while (i < n)
	{
		ft_printf("i = %d, bfs_order = %d\n", i, arr[i]);
		i++;
	}
}

void	print_linked_visited(t_linked *lst, int *vis)
{
	while (lst)
	{
		ft_printf("(%d, %d)->", lst->data, vis[lst->data]);
		lst = lst->next;
	}
	ft_printf("nil\n");
}

void	print_visited(int *vis, int n)
{
	int			i;

	i = -1;
	ft_printf("visited order: ");
	while (++i < n)
		ft_printf("(%d, %d)\n", i, vis[i]);
}
