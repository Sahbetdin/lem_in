/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:00:59 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/23 18:24:23 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	k = 0;
	while (k < i)
	{
		ptr[k] = s1[k];
		k++;
	}
	while (k < (i + j))
	{
		ptr[k] = s2[k - i];
		k++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}
