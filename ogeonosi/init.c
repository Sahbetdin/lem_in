#include "lem_in.h"

t_vertex *vertex_init(char *name, int len, t_status st, int order)
{
	t_vertex *v_tmp;

	if (!(v_tmp = (t_vertex *) malloc(sizeof(t_vertex))))
		exit(0);
	v_tmp->name = ft_strndup(name, len);
	v_tmp->len = len;
	v_tmp->bfs_order = 0;
	v_tmp->neighbour = NULL;
	v_tmp->status = st;
	v_tmp->in = 0;
	v_tmp->out = 0;
	v_tmp->order = order;
	return (v_tmp);
}

void	farm_init(t_map *f)
{
	f->hash_size = 10;
	f->flag_ants = FALSE;
	f->flag_start = FALSE;
	f->flag_end = FALSE;
	f->flag_rooms = FALSE;
	f->flag_links = FALSE;
	f->max_order = 0;
	f->fd = 0;
	f->first_raw = hashmap_init(f->first_raw, f->hash_size);
}

t_stack	*initiate_stack(int n)
{
	t_stack *tmp_stack;

	if ((tmp_stack = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	if ((tmp_stack->arr = (int *)malloc(sizeof(int) * n)) == NULL)
	{
		free(tmp_stack);
		return (NULL);
	}
	tmp_stack->len = n;
	tmp_stack->ptr = n;
	return (tmp_stack);
}


