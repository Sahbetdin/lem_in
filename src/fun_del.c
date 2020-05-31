/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 09:17:27 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/30 07:41:11 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** delete all nodes from one of the paths which is arr here
** we walk through arr until encounter -1
*/

void		delete_trace(t_map *f, int *arr)
{
	int			i;

	i = 0;
	while (i < f->max_order && arr[i] != -1)
	{
		delete_node(f, arr[i]);
		i++;
	}
}

t_linked	*del_list_element(t_linked *lst)
{
	lst->next = NULL;
	free(lst);
	return (NULL);
}

/*
** temporary delete edge: from g[haystack] extract and return
** needle(t_linked element) of haystack
** E.g. g[haystack] : .., .., needle, .. ..
** we are sure that g[haystack] != NULL and it has at least one element.
** these arcs are temproraly kept in f->arc1, f->arc2
** if (curr == NULL) //means that didn't find anything
*/

t_linked	*delete_arc(t_map *f, int haystack, int needle)
{
	t_linked	*curr;
	t_linked	*prev;

	curr = f->g[haystack];
	if (curr->data == needle)
	{
		f->g[haystack] = curr->next;
		curr->next = NULL;
		return (curr);
	}
	while (curr)
	{
		if (curr->data == needle)
			break ;
		prev = curr;
		curr = curr->next;
	}
	if (curr == NULL)
		return (NULL);
	prev->next = curr->next;
	curr->next = NULL;
	return (curr);
}
