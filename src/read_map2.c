#include "../lem_in.h"

/*
** this function accepts two vertice
** it assigns u2 as neighbour to u1->neighbour linked list
** it assigns u2's order.
*/

t_bool link_neighbour(t_vertex *dest, t_vertex *src)
{
	t_linked	*list_elem;

	if ((list_elem = (t_linked *)malloc(sizeof(t_linked))) == NULL)
		return (false);

	list_elem->next = NULL;
	list_elem->data = src->order;

	if (dest->neighbour == NULL)
		dest->neighbour = list_elem;
	else
	{
		list_elem->next = dest->neighbour;
		dest->neighbour = list_elem;
	}
	return (true);
}


//in the link v1-v2
//assigns v2 as neighbor of v1 and vice verses
//if error, returns false
t_bool	parse_links(t_map *f, char *line, char *dash)
{
	int			n;
	int			i;
	t_hash		*tmp_h;
	t_vertex	*v1;
	t_vertex	*v2;

	if (f->flag_rooms == false) //first, we set that the rooms are finished
		f->flag_rooms = true;
	if ((v1 = find_vertex(f, line, dash - line)) == NULL)
		return (false);
	// ft_printf("v1->name = %s", v1->name);
	// нужна проверка на зеркальность
	// нужна проверка на name1-name1
	if ((v2 = find_vertex(f, dash + 1, ft_strlen(dash + 1))) == NULL)
		return (false);
	link_neighbour(v1, v2);
	link_neighbour(v2, v1);
	if (f->flag_links == false)
		f->flag_links = true;
	return (true);
}


/*
** alocate memory of links for neighbours.
** then assign to each node (which is type of t_linked)
** its own neighbour
*/
t_bool	graph_fill_in(t_map *f)
{
	int			i;
	t_hash		*tmp_h;
	t_vertex	*tmp_v;
	t_linked	*tmp_lst;

	if (!(f->g = (t_linked **)malloc(sizeof(t_linked *) * f->max_order)))
		return (false);
	if (!(f->status = (t_status *)malloc(sizeof(t_status) * f->max_order)))
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
			f->status[tmp_v->order] = tmp_v->status;
			tmp_h = tmp_h->next;
		}
	}
	f->bfs_order = arr_init(f->bfs_order, f->max_order, -1);
	f->in = arr_init(f->in, f->max_order, 0);
	f->out = arr_init(f->out, f->max_order, 0);
	f->neutral = arr_init(f->neutral, f->max_order, 0);
	return (true);
}