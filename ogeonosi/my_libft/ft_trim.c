/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:10:10 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/25 18:23:34 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates (with malloc(3)) two pointer array tr.
** tr[0] contains pointer to place in s which contains first occurence of
** charcater which is not equal to c.
** tr[1] contains pointer to place in s which is the next to last
** occurence of charcter which is not c.
*/

char	**ft_trim(char *s, char ch)
{
	char *str;
	char **tr;

	tr = (char **)malloc(sizeof(char *) * 2);
	if (tr == NULL)
		return (NULL);
	str = s;
	while (*str && *str == ch)
		str++;
	tr[0] = str;
	while (*str)
		str++;
	str--;
	while (*str == ch)
		str--;
	str++;
	tr[1] = str;
	return (tr);
}
