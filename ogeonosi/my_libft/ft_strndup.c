/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:42:59 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/23 19:20:51 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*ptr;
	size_t	len;

	len = 0;
	while (s[++len])
		;
	if (n >= len)
		n = len;
	if (!(ptr = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ptr[n] = '\0';
	while (n--)
		*(ptr + n) = *(s + n);
	return (ptr);
}
