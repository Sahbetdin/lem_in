/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:30:52 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/15 16:15:47 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** memccpy function copies bytes from one memory area to other,
** stopping after the first occurrence of some byte c
** (converted to an Unsigned char)
** or after n bytes are copied, whichever comes first.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	unsigned char	ch;
	size_t			i;

	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
		if (p2[i - 1] == ch)
			return (dst + i);
	}
	return (NULL);
}
