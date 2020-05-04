/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_Le.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:52:49 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 20:52:52 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_sci_ldbl(long double x, t_s *sp)
{
	int			j;
	t_long		*lng;
	t_uint		*arr;
	t_long_dbl	num;

	if (x == 0)
		return (ft_put_e_zero(sp));
	num.l_dbl = x;
	lng = ft_create_long_whole(&num);
	ft_create_long_decimal(lng, &num, sp->decim);
	if (!(arr = create_one_array_e(lng)))
		return (0);
	j = ft_find_exp(lng);
	ft_fill_in_one_arr_e(arr, lng, j);
	free_long_arithm(lng);
	j = ft_put_value_in_e(arr, sp, j);
	if (sp->decim > 0)
		return (4 + sp->decim + (sp->plus || sp->sign) + ft_put_exp_value(j));
	else
		return (3 + (sp->plus || sp->sign) + ft_put_exp_value(j));
}

int		ft_dig_long(long double a)
{
	int			i;

	if (a < 1)
		return (1);
	i = 0;
	while (a >= 1)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int		ft_get_k_for_e_ldbl(long double x, t_s *sp)
{
	int			k;
	int			dig;

	if (sp->decim > 0)
		sp->point = 1;
	else
		sp->point = 0;
	k = sp->numb - sp->decim - sp->point;
	dig = ft_dig_ldbl(x);
	if (dig < 100)
		k -= 2 + 3;
	else if (dig < 1000)
		k -= 3 + 3;
	if (sp->plus || sp->sign)
		k--;
	if (k < 0)
		k = 0;
	if (k == 0 && sp->backsp)
		k = 1;
	return (k);
}

int		ft_put_whole_sci_ldbl(long double x, t_s *sp)
{
	int			n;
	int			k;

	k = ft_get_k_for_e_ldbl(x, sp);
	if (sp->minus)
	{
		ft_put_sign(sp);
		n = ft_put_sci_ldbl(x, sp);
		ft_put_n_chars(32, k);
		return (k + n);
	}
	else
	{
		ft_put_n_chars(32, k);
		ft_put_sign(sp);
		return (ft_put_sci_ldbl(x, sp) + k);
	}
}
