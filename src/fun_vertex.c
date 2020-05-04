#include "../lem_in.h"

/*
** initialize vertex.
** all it's fields are zeros except
** name which is ft_strdup(line)
*/

t_vertex *vertex_init(char *name, int len, t_status st, int order)
{
	t_vertex *v_tmp;

	if (!(v_tmp = (t_vertex *)malloc(sizeof(t_vertex))))
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
