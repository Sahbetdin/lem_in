/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 18:05:48 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/26 18:06:03 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** s_n is source name
** d_n is destination name
*/

t_bool	compare_src_dest(char *d_n, char *s_n)
{
	if (!(ft_strcmp(d_n, s_n)))
	{
		ft_printf("ERROR link with self-loop found\n");
		return (false);
	}
	return (true);
}

/*
** s_n is source name
** d_n is destination name
*/

t_bool	search_for_duplicate(t_linked *head, int ord, char *s_n, char *d_n)
{
	while (head)
	{
		if (head->data == ord)
		{
			ft_printf("ERROR: found duplicate edge: %s->%s\n", s_n, d_n);
			return (false);
		}
		head = head->next;
	}
	return (true);
}

/*
** this function accepts two vertice
** it assigns u2 as neighbour to u1->neighbour linked list
** it assigns u2's order.
*/

t_bool	link_neighbour(t_vertex *dest, t_vertex *src)
{
	t_linked	*list_elem;

	if (compare_src_dest(dest->name, src->name) == false)
		return (false);
	if (search_for_duplicate(dest->neighbour, src->order,
		src->name, dest->name) == false)
		return (false);
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

/*
** we take the string in form v1-v2
** we assigns v2 as neighbor of v1 and vice verses
** if error, returns false
** in if (f->flag_rooms == false) //first, we set that the rooms are finished
*/

t_bool	parse_links(t_map *f, char *line, char *dash)
{
	t_vertex	*v1;
	t_vertex	*v2;

	if (f->flag_rooms == false)
		f->flag_rooms = true;
	v1 = find_vertex(f, line, dash - line);
	v2 = find_vertex(f, dash + 1, ft_strlen(dash + 1));
	if (v1 == NULL || v2 == NULL)
	{
		ft_printf("ERROR couldn't find rooms for linking\n");
		return (false);
	}
	if (link_neighbour(v1, v2) == false || link_neighbour(v2, v1) == false)
		return (false);
	if (f->flag_links == false)
		f->flag_links = true;
	return (true);
}
