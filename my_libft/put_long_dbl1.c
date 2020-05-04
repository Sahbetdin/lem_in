/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_long_dbl1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:09:50 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 22:09:53 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_long	*ft_create_long_pre(t_long_dbl *num_dbl)
{
	double		log2;
	t_long		*lng2;
	t_uint		exp;
	int			n;

	log2 = 0.30103;
	lng2 = (t_long *)malloc(sizeof(t_long));
	lng2->flag = 1UL << 62;
	if (num_dbl->parts.exponent >= 16383)
	{
		exp = num_dbl->parts.exponent - 16383;
		n = log2 * exp + 4;
		lng2->whole = power_of_2(exp, n);
	}
	else
	{
		if (!(lng2->whole = (t_uint *)malloc(sizeof(t_uint) * 2)))
			return (0);
		lng2->whole[0] = 1;
		lng2->whole[1] = 0;
	}
	return (lng2);
}

t_long	*ft_create_long_whole(t_long_dbl *num_dbl)
{
	t_long		*lng2;
	t_uint		exp;
	int			n;
	t_uint		*b;

	lng2 = ft_create_long_pre(num_dbl);
	if (num_dbl->parts.exponent >= 16383)
	{
		exp = num_dbl->parts.exponent - 16383;
		n = (int)(0.30103 * exp + 4.0);
		b = power_of_2(exp, n);
		while (exp > 0)
		{
			divide_by_2(b);
			if (lng2->flag & num_dbl->parts.mantissa)
				add_arithmetics(lng2->whole, b);
			lng2->flag = lng2->flag >> 1;
			exp--;
		}
		free(b);
	}
	return (lng2);
}

int		ft_create_n_temp(t_uint exp_, int d, t_uint z)
{
	int			n;
	double		log2;
	double		log5;

	log2 = 0.30103;
	log5 = 0.69897;
	if (exp_ >= z)
		n = (d > 64) ? d + 4 : 64;
	else
	{
		exp_ = z - exp_;
		n = (log5 * exp_ + d + 50);
	}
	return (n);
}

t_uint	*ft_create_b_temp(t_uint exp_, t_uint n)
{
	t_uint		*b;

	if (exp_ >= 16383)
		b = divide_by_minus_2(NULL, n);
	else
	{
		exp_ = 16383 - exp_;
		b = divide_by_minus_2(NULL, n);
		while (exp_ > 1)
		{
			divide_by_minus_2(b, n);
			exp_--;
		}
	}
	return (b);
}

void	ft_create_long_decimal(t_long *lng2, t_long_dbl *num_dbl, int d)
{
	t_uint		*b;
	t_uint		n;

	n = ft_create_n_temp(num_dbl->parts.exponent, d, 16383);
	b = ft_create_b_temp(num_dbl->parts.exponent, n);
	if (num_dbl->parts.exponent >= 16383)
	{
		if (!(lng2->decimal = set_arithmetic_zeros(n)))
			return ;
	}
	else
	{
		if (!(lng2->decimal = set_arithmetic_zeros(n)))
			return ;
		add_arithmetics_minus(lng2->decimal, b);
		divide_by_minus_2(b, n);
	}
	while (lng2->flag)
	{
		if (lng2->flag & num_dbl->parts.mantissa)
			add_arithmetics_minus(lng2->decimal, b);
		divide_by_minus_2(b, n);
		lng2->flag = lng2->flag >> 1;
	}
	free(b);
}
