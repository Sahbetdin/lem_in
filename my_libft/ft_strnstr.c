/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:32:58 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/18 21:25:55 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strnstr() function finds the first occurrence of the
** null-terminated string s2 in the s1, where not more than n
** characters are searched in s1.
** Characters that appear after a '\0' character are not searched.
** If s2 is an empty string, s1 is returned; if s2 occurs nowhere in s1,
** NULL is returned; otherwise a pointer to the
** first character of the first occurrence of s2 is returned.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n1;
	size_t	n2;

	n1 = ft_strlen(haystack);
	n2 = ft_strlen(needle);
	if (n2 == 0)
		return ((char *)(haystack));
	if (n1 < len)
		len = n1;
	j = 0;
	while (j < len)
	{
		i = 0;
		while (i + j < len && i < n2 && haystack[i + j] && \
				haystack[i + j] == needle[i])
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack + j);
		j++;
	}
	return (NULL);
}
