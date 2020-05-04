/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ee3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:16:09 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 19:16:10 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dig_db(double a)
{
	int i;

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

int	ft_get_k_for_e(double x, t_s *sp)
{
	int k;
	int dig;

	if (sp->decim > 0)
		sp->point = 1;
	else
		sp->point = 0;
	k = sp->numb - sp->decim - sp->point;
	dig = ft_dig_db(x);
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

int	ft_put_whole_sci(double x, t_s *sp)
{
	int n;
	int k;

	k = ft_get_k_for_e(x, sp);
	if (sp->minus)
	{
		ft_put_sign(sp);
		n = ft_put_sci(x, sp);
		ft_put_n_chars(32, k);
		return (k + n);
	}
	else
	{
		ft_put_n_chars(32, k);
		ft_put_sign(sp);
		return (ft_put_sci(x, sp) + k);
	}
}
