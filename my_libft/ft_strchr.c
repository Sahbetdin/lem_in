/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:32:35 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/11 14:14:35 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strchr finds the first occurrence of c in the string s.
** The search includes the null terminating character.
** c is converted to a char before the search begins.
** If the character is found, strchr returns a pointer
** to the matched character.
** It returns a NULL pointer if the character c is not in the string.
** const char *s	A pointer to the string to be searched.
** int c		The character to be searched for.
*/

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}
