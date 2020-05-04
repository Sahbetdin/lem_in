/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:57:53 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/25 17:08:25 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		n_length(int n)
{
	size_t i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	unsigned int	m;
	char			*s;
	size_t			len;

	len = n_length(n);
	m = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	s = ft_strnew(len);
	if (!s)
		return (NULL);
	if (n < 0)
		s[0] = '-';
	while (m > 9)
	{
		s[len - 1] = m % 10 + '0';
		m = m / 10;
		len--;
	}
	s[len - 1] = m + '0';
	return (s);
}
