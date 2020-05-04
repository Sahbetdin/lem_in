#include "lem_in.h"

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
	// ft_printf("v1->name = %s", v1->name);
	if ((v2 = find_vertex(f, dash + 1, ft_strlen(dash + 1))) == NULL)
		return (false);
	link_neighbour(v1, v2);
	link_neighbour(v2, v1);
	if (f->flag_links == false)
		f->flag_links = true;
	return (true);
}