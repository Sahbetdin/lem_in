/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:32:27 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/11 14:13:08 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strncat copies a maximum of n characters from s2 onto
** the end of the string s1. The first character of s2 overwrites
** the null terminating character of s1. A null terminating character is
** appended to the end of the result.
** The string s1 must be large enough to accept the extra characters from s2.
** Returns the unchanged value of s1.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*p1;
	char	*p2;
	size_t	i;

	p1 = (char *)s1;
	p2 = (char *)s2;
	while (*p1)
		p1++;
	i = 0;
	while (p2[i] && i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	p1[i] = '\0';
	return (s1);
}
