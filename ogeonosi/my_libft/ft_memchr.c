/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:31:14 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/25 19:10:25 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** memchr finds the first occurrence of c in the first n characters in s.
** c is converted to an unsigned char before the search begins.
** If the character is found, memchr returns a pointer to the matched character.
** It returns a NULL pointer if the character c is not in the first n
** characters of the area of memory.
** const void *s	A pointer to the area of memory to be searched.
** int c			The character to be searched for.
** size_t n			The size in bytes ofthe area of memory to be searched.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;
	unsigned char	ch;

	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*ptr == ch)
			return (ptr);
		i++;
		ptr++;
	}
	return (NULL);
}
