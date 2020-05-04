/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:29:30 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/11 11:49:00 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** bzero() erases the data in the n bytes of the memory starting at s,
** by writing zeros (bytes containing '\0') to that area.
*/

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	int				i;
	int				n1;

	p = (unsigned char *)s;
	i = 0;
	n1 = (int)n;
	while (i < n1)
	{
		*p = '\0';
		p++;
		i++;
	}
}
