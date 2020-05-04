/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:29:12 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/11 14:16:06 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** void	*dest	A pointer to the area of memory to be filled.
** int	c	The character to be used for filling.
** size_t	n	The number of characters in the area of memory be filled.
** memset fills the first n characters of dest with
** the value of the character c.
** c is converted to an unsigned char before it is written into s.
** Returns the unchanged value of s.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	char			*p;
	size_t			i;

	ch = (unsigned char)c;
	p = (char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = ch;
		i++;
	}
	return (b);
}
