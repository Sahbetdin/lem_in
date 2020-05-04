/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:28:01 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 18:28:13 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_uint	*add_arithmetics(t_uint *a, t_uint *b)
{
	t_uint		i;

	i = 1;
	while (i < a[0])
	{
		a[i] += b[i];
		if (a[i] > 9)
		{
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
		i++;
	}
	return (a);
}

t_uint	*set_arithmetic_zeros(int n)
{
	t_uint	*s;
	int		i;

	if (!(s = (t_uint *)malloc(sizeof(t_uint) * (n + 1))))
		return (NULL);
	s[0] = n;
	i = 0;
	while (++i <= n)
		s[i] = 0;
	return (s);
}

t_uint	*add_arithmetics_minus(t_uint *a, t_uint *b)
{
	int		i;

	i = b[0];
	while (i && b[i] == 0)
		i--;
	while (i > 0)
	{
		a[i] += b[i];
		if (a[i] > 9)
		{
			a[i - 1] += a[i] / 10;
			a[i] %= 10;
		}
		i--;
	}
	return (a);
}
