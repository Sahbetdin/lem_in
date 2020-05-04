/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:32:44 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/11 14:11:06 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strrchr finds the last occurrence of c in the string pointed to by s.
** The search includes the null terminating character.
** c is converted to a char before the search begins.
** Returns a pointer to the last occurrence of the character.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*ptr;

	ch = (char)c;
	ptr = (char *)s;
	while (*ptr)
		ptr++;
	if (ch == '\0')
		return (ptr);
	while (ptr >= (char *)s && *ptr != ch)
		ptr--;
	if (*ptr == ch)
		return (ptr);
	return (NULL);
}
