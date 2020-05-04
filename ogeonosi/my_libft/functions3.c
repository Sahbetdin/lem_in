/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:42:45 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 18:42:48 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digits_in_base(long value, int base)
{
	int		i;

	i = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

int	digits_in_base_unsigned(t_ulong u_value, int base)
{
	int		i;

	i = 0;
	if (u_value == 0)
		return (1);
	while (u_value)
	{
		u_value /= base;
		i++;
	}
	return (i);
}

int	ft_putnbr_positive(int n)
{
	int		i;

	i = (n < 0) ? 1 : 0;
	if (n > 9)
		i += ft_putnbr_positive(n / 10);
	ft_putchar(n % 10 + '0');
	i++;
	return (i);
}

int	ft_putlong(long n)
{
	int		i;
	long	max_d;
	long	digit;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		i++;
	}
	max_d = 1;
	while (max_d <= n / 10)
		max_d *= 10;
	while (max_d)
	{
		digit = n / max_d;
		ft_putchar(digit + '0');
		n -= max_d * digit;
		max_d /= 10;
		i++;
	}
	return (i);
}
