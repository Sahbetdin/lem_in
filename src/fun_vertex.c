/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 09:18:29 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/26 08:40:43 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** we search the string *start_search of length n in hashmap
** and return vertex which name coincides with *start_search
** of length n
** flag_found for searching links
*/

t_vertex	*find_vertex(t_map *f, char *start_search, int n)
{
	int			i;
	t_vertex	*v1;
	t_bool		flag_found;
	t_hash		*tmp_h;
	int			place;

	i = 0;
	flag_found = false;
	v1 = NULL;
	place = hash_calculate(start_search, n, f->hash_size);
	tmp_h = f->first_raw[place];
	while (tmp_h && flag_found == false)
	{
		if (!ft_strncmp(start_search, tmp_h->v->name, n) && n == tmp_h->v->len)
		{
			flag_found = true;
			v1 = tmp_h->v;
		}
		else
			tmp_h = tmp_h->next;
	}
	return (v1);
}
