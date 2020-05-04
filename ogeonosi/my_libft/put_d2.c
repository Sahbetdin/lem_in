/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:14:56 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 19:14:57 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_int_min_with_spec(t_s *sp)
{
	int l;
	int k;
	int dig;

	dig = 11;
	if (!sp->numb && !sp->point)
		write(1, "-2147483648", 11);
	else if (!sp->point)
		dig += ft_put_int_min_with_point(sp);
	else
	{
		l = sp->decim - dig + 1;
		if (l < 0)
			l = 0;
		k = (sp->decim > dig) ? sp->numb - sp->decim : sp->numb - dig;
		ft_put_int_min_minus(sp, k, l);
		dig += l + k;
	}
	return (dig);
}

int		ft_put_d_without_numb_point(long num, t_s *sp)
{
	if (sp->plus && !sp->sign)
		write(1, "+", 1);
	else if (sp->backsp && !sp->sign)
		write(1, " ", 1);
	if (sp->sign)
		write(1, "-", 1);
	ft_put_long(num);
	return (sp->plus || sp->backsp || sp->sign);
}

void	ft_put_d_pl_si_mi(long num, int k, int l, t_s *sp)
{
	write(1, "+", 1);
	ft_put_n_chars(48, l);
	if (!(sp->point && num == 0))
		ft_put_long(num);
	ft_put_n_chars(32, k);
}

void	ft_put_d_pl_nsi_ze(long num, int k, int l, t_s *sp)
{
	if (sp->point)
	{
		ft_put_n_chars(32, k);
		write(1, "+", 1);
	}
	else
	{
		write(1, "+", 1);
		ft_put_n_chars(48, k);
	}
	ft_put_n_chars(48, l);
	if (!(sp->point && num == 0))
		ft_put_long(num);
}

void	ft_put_d_pl_nsi(long num, int k, int l, t_s *sp)
{
	ft_put_n_chars(32, k);
	write(1, "+", 1);
	ft_put_n_chars(48, l);
	if (!(sp->point && num == 0))
		ft_put_long(num);
}
