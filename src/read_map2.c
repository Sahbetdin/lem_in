#include "../lem_in.h"

/*
** this function accepts two vertice
** it assigns u2 as neighbour to u1->neighbour linked list
** it assigns u2's order.
*/

t_bool link_neighbour(t_vertex *dest, t_vertex *src)
{
	t_linked *list_elem;

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
	int n;
	int i;
	t_hash *tmp_h;
	t_vertex *v1;
	t_vertex *v2;

	if (f->flag_rooms == false) //first, we set that the rooms are finished
		f->flag_rooms = true;
	if ((v1 = find_vertex(f, line, dash - line)) == NULL)
		return (false);
	if ((v2 = find_vertex(f, dash + 1, ft_strlen(dash + 1))) == NULL)
		return (false);
	if (!(ft_strcmp(v1->name, v2->name)))
	{
		printf("\nERROR!\n");
		return (false);
	}
	link_neighbour(v1, v2);
	link_neighbour(v2, v1);
	if (f->flag_links == false)
		f->flag_links = true;
	return (true);
}

int		count_neighb(t_linked *lst)
{
	int count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int		min_of_two(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

/*
** alocate memory of links for neighbours.
** then assign to each node (which is type of t_linked)
** its own neighbour
*/
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

	f->bfs_order = arr_init(f->max_order, -1);
	f->shortest_path = arr_init(f->max_order, -1);
	//get max_paths value which is min of neighbours of start and end vertice
	f->max_paths = min_of_two(count_neighb(f->g[f->start_vertex]), 
			count_neighb(f->g[f->end_vertex]));
	f->paths = (int **)malloc(sizeof(int *) * f->max_paths);
	i = 0;
	while (i < f->max_paths)
	{ //each path is not longer than number of elements in graph
		f->paths[i] = arr_init(f->max_order, -1);
		i++;
	}
	return (true);
}
