/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:00:59 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/25 11:29:12 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len(char const *str)
{
	if (str == NULL)
		return (0);
	return (ft_strlen(str));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ptr;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = ft_len(s1);
	j = ft_len(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	k = 0;
	while (k < i)
	{
		ptr[k] = s1[k];
		k++;
	}
	while (k < i + j)
	{
		ptr[k] = s2[k - i];
		k++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}
