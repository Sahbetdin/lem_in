/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 21:33:36 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 21:33:38 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_p_zero(t_s *sp)
{
	int k;
	int l;

	l = (sp->point > 0) ? sp->decim : 1;
	if (sp->point)
		k = (sp->numb > sp->decim + 2 + l) ? sp->numb - sp->decim - 2 - l : 0;
	else
		k = (sp->numb > 2 + l) ? sp->numb - 2 - l : 0;
	if (sp->minus)
	{
		write(1, "0x", 2);
		ft_put_n_chars(48, l);
		ft_put_n_chars(32, k);
	}
	else
	{
		ft_put_n_chars(32, k);
		write(1, "0x", 2);
		ft_put_n_chars(48, l);
	}
	return (k + l + 2);
}

int		ft_put_p_minus(long num, int l, int k)
{
	int k1;

	write(1, "0x", 2);
	ft_put_n_chars(48, l);
	if (num != 0)
		k1 = ft_itoa_base_unsigned(num, 16, 0) + 2;
	else
		return (2 + k);
	ft_put_n_chars(32, k);
	k += k1;
	return (k);
}

int		ft_put_p(long num, t_s *sp)
{
	int k;
	int l;
	int dig;

	if (num == 0)
		return (ft_put_p_zero(sp));
	dig = digits_in_base(num, 16);
	l = (sp->decim > dig) ? sp->decim - dig : 0;
	k = (sp->numb > dig + 2) ? sp->numb - dig - 2 : 0;
	if (sp->minus)
		return (ft_put_p_minus(num, l, k));
	else
	{
		ft_put_n_chars(32, k);
		write(1, "0x", 2);
		ft_put_n_chars(48, l);
		if (num != 0)
			k += ft_itoa_base_unsigned(num, 16, 0) + 2;
		else
			return (2 + k);
	}
	return (k + l);
}
