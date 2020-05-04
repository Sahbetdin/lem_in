/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:31:23 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/25 19:19:22 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** if s1 != s2 and s1 < s2 then returns negative number and vice versus.
** memcmp compares the first n characters of the areas of memory pointed to
** by s1 and s2.
** const void *s1	A pointer to one of the areas of memory to be compared.
** const void *s2	A pointer to the other area of memory to be compared.
** size_t n	The number of characters to be compared.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (int)(p1[i] - p2[i]);
		i++;
	}
	return (0);
}
