/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:45:47 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/16 13:58:53 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” substring from
** the string given as argument. The substring begins at index start
** and is of size len. If start and len aren’t refering to a valid
** substring, the behavior is undefined. If the allocation fails,
** the function returns NULL.
** len - the size of the substring.
** Returns substring.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	if (!(sub = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = ptr[start + i];
		if (ptr[start + i] == '\0')
		{
			sub[i] = '\0';
			return (sub);
		}
		i++;
	}
	sub[len] = '\0';
	return (sub);
}
