#include "lem_in.h"

t_bool	graph_fill_in(t_map *f)
{
	int i;
	t_hash *tmp_h;
	t_vertex *tmp_v;
	t_linked *tmp_lst;

	if (!(f->g = (t_linked **)malloc(sizeof(t_linked *) * f->max_order)))
		return (false);
	i = -1;
	while (++i < f->hash_size)
	{
		tmp_h = f->first_raw[i];
		while (tmp_h)
		{
			tmp_v = tmp_h->v;
			tmp_lst = tmp_v->neighbour;
			f->g[tmp_v->order] = tmp_v->neighbour;
			tmp_h = tmp_h->next;
		}
	}
	return (true);
}

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
