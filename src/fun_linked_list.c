/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_linked_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 09:18:16 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/26 08:34:13 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	delete_simple_linked_list(t_linked **head)
{
	t_linked	*prev;
	t_linked	*curr;

	prev = *head;
	while (prev)
	{
		curr = prev->next;
		free(prev);
		prev = curr;
	}
	*head = NULL;
}

void	delete_hash_node(t_hash **head)
{
	t_hash		*prev;
	t_hash		*curr;

	prev = *head;
	while (prev)
	{
		curr = prev->next;
		free(prev);
		prev = curr;
	}
	*head = NULL;
}

/*
** from all neighbors of node deletes it as neighbour.
** That means to delete it in linked lists. Then
** delete all neighbors of node such that it becomes isolated.
** t_linked *tmp is the node
*/

void	delete_node(t_map *f, int node)
{
	t_linked	*tmp;
	t_linked	*lst;

	tmp = f->g[node];
	while (tmp)
	{
		if ((lst = delete_arc(f, tmp->data, node)))
			free(lst);
		tmp = tmp->next;
	}
	delete_simple_linked_list(f->g + node);
}
