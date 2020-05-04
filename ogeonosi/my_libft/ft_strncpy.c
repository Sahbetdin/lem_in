/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:32:03 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/11 14:12:29 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strncpy copies up to n characters from the source string (pointed to by s2)
** into the destination array (pointed to by s1).
** The behavior of strncpy is undefined if the source and destination overlap.
** If the source string is less than n characters long,
** the extra spaces in the destination array will be
** filled with null characters.
** Returns the unchanged value of s1.
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*p1;
	char	*p2;
	size_t	i;

	p1 = (char *)dst;
	p2 = (char *)src;
	i = 0;
	while (p2[i] && i < len)
	{
		p1[i] = p2[i];
		i++;
	}
	while (i < len)
	{
		p1[i] = '\0';
		i++;
	}
	return (dst);
}
