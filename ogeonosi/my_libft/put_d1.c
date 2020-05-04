/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:14:51 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 19:14:53 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_n_chars(char c, int n)
{
	if (n > 0)
	{
		while (n)
		{
			write(1, &c, 1);
			n--;
		}
	}
}

void	ft_put_long(long num)
{
	long	c;
	long	m;
	int		i;
	int		dig;

	m = num;
	i = 0;
	c = 1;
	while (m > 9 || m < -9)
	{
		m /= 10;
		c *= 10;
		i++;
	}
	if (num < 0)
		c = -c;
	while (i >= 0)
	{
		dig = num / c;
		ft_putchar(dig + '0');
		num -= dig * c;
		c /= 10;
		i--;
	}
}

int		ft_put_int_min(int k, t_s *sp)
{
	int		dig;

	dig = 0;
	if (sp->zero && !sp->minus)
	{
		write(1, "-", 1);
		ft_put_n_chars(48, k);
		write(1, "2147483648", 10);
		dig += k;
	}
	else if (!sp->minus)
	{
		ft_put_n_chars(32, k);
		write(1, "-2147483648", 11);
		dig += k;
	}
	else if (sp->minus)
	{
		k = (k > 1) ? k - 1 : 0;
		write(1, "-2147483648", 11);
		ft_put_n_chars(32, k);
		dig += (sp->numb > 11) ? k + 1 : k;
	}
	return (dig);
}

void	ft_put_int_min_ze_nmi(int k)
{
	write(1, "-", 1);
	ft_put_n_chars(48, k);
	write(1, "2147483648", 10);
}

int		ft_put_int_min_with_point(t_s *sp)
{
	int		k;
	int		dig;

	dig = 11;
	k = (sp->numb > dig) ? sp->numb - dig : 0;
	dig += ft_put_int_min(k, sp);
	if (sp->zero && !sp->minus)
	{
		ft_put_int_min_ze_nmi(k);
		dig += k;
	}
	else if (!sp->minus)
	{
		ft_put_n_chars(32, k);
		write(1, "-2147483648", 11);
		dig += k;
	}
	else if (sp->minus)
	{
		k = (k > 1) ? k - 1 : 0;
		write(1, "-2147483648", 11);
		ft_put_n_chars(32, k);
		dig += (sp->numb > 11) ? k + 1 : k;
	}
	return (dig);
}
