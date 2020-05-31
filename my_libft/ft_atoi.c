/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:33:26 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/29 18:58:53 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts an ASCII decimal number string nptr into an int.
*/

int			ft_cut_backspaces(const char *s)
{
	int i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' \
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r'))
		i++;
	return (i);
}

/*
** standard atoi function. Parses string and returns number.
** in case it's out of int for positives returns negative and vice versus.
** for out of long returns -1 for positives and 1 for negatives
*/

int			ft_atoi(const char *str)
{
	int			i;
	long long	res;
	long long	sign;

	res = 0;
	i = 0;
	sign = 1;
	i += ft_cut_backspaces(&str[i]);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res < 0 && sign == 1)
			return (-1);
		else if (res < 0 && sign == -1)
			return (0);
		i++;
	}
	return (sign * res);
}

/*
** the same as ft_atoi, parses string and puts it to *n
** returns char pointer to next character which might be NULL
** Used in lem-in, for example for parsing room coordinates,
** e.g. name1 100 150
*/

char		*ft_atoi_pointer(const char *str, int *n)
{
	int i;

	i = 0;
	i += ft_cut_backspaces(str);
	*n = ft_atoi(str + i);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return ((char *)str + i);
}
