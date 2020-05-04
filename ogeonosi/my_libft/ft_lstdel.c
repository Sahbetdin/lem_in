/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:17:47 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/25 16:50:13 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp1;
	t_list *tmp2;

	tmp1 = *alst;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		del((tmp1)->content, (tmp1)->content_size);
		free(tmp1);
		tmp1 = tmp2;
	}
	*alst = NULL;
}
