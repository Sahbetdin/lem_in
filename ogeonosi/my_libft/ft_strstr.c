/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:32:51 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/18 21:12:35 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strstr finds the first occurrence of the s2 string
** (except '\0') in the s1 string.
** Returns a pointer to s1, if found. If s2 points is of zero length,
** the function returns s1. If the s2 string does not occur within the
** s1 string,returns NULL.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	n1;
	size_t	n2;

	n1 = ft_strlen(haystack);
	n2 = ft_strlen(needle);
	if (n2 == 0)
		return (char *)(haystack);
	j = 0;
	while (j < n1)
	{
		i = 0;
		while (haystack[i + j] && haystack[j + i] \
				== needle[i] && i < n2)
			i++;
		if (needle[i] == '\0')
			return (char *)(haystack + j);
		j++;
	}
	return (NULL);
}
