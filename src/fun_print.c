#include "../lem_in.h"

void	print_graph(t_linked **g, int n)
{
	int i;
	t_linked *tmp_lst;

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

void	print_linked_list(t_linked **head)
{
	t_linked *lst;

	lst = *head;
	while (lst)
	{
		ft_printf("%d->", lst->data);
		lst = lst->next;
	}
	ft_printf("NULL\n");
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
	int i;

	i = -1;
	ft_printf("visited order: ");
	while (++i < n)
		ft_printf("(%d, %d)\n", i, vis[i]);
}

void	print_in_out_neutral(t_map *f)
{
	int i;

	i = 0;
	while (i < f->max_order)
	{
		ft_printf("i =  %d, status = %d, bfs_order = %d, ", i, f->status[i], f->bfs_order[i]);
		ft_printf("in = %d, out = %d, neutral = %d\n", f->in[i], f->out[i], f->neutral[i]);
		i++;
	}
}

