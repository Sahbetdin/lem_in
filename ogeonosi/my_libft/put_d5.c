/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:46:01 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 19:46:05 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_cast_num(long num, t_s *sp)
{
	if (sp->s == 'h')
	{
		if (sp->s1 == 'd' || sp->s1 == 'i')
			num = (short)num;
		else if (sp->s1 == 'h' && (sp->s2 == 'd' || sp->s2 == 'i'))
			num = (char)num;
	}
	else if (sp->s == 'l')
	{
		if (sp->s1 == 'd')
			num = (long)num;
	}
	else if (sp->s == 'd' || sp->s == 'i')
		num = (int)num;
	return (num);
}

int		ft_put_d_if_specif1(long num, t_s *sp, int k, int l)
{
	if (sp->plus && !sp->sign && sp->minus)
	{
		ft_put_d_pl_si_mi(num, k, l, sp);
		return (1);
	}
	else if (sp->plus && !sp->sign && sp->zero)
	{
		ft_put_d_pl_nsi_ze(num, k, l, sp);
		return (1);
	}
	else if (sp->plus && !sp->sign)
	{
		ft_put_d_pl_nsi(num, k, l, sp);
		return (1);
	}
	else if (!sp->plus && !sp->sign && sp->minus && sp->backsp)
	{
		ft_put_d_npl_nsi_mi_ba(num, &k, l, sp);
		return (1);
	}
	else
		return (0);
}

int		ft_put_d_if_specif2(long num, t_s *sp, int k, int l)
{
	if (!sp->plus && !sp->sign && sp->zero)
	{
		ft_put_d_npl_nsi_ze(num, k, l, sp);
		return (1);
	}
	else if (sp->sign && sp->minus)
	{
		ft_put_d_si_mi(num, k, l);
		return (1);
	}
	else if (sp->sign && sp->zero)
	{
		ft_put_si_ze(num, k, l, sp);
		return (1);
	}
	else
		return (0);
}

int		ft_put_d_with_numb_point(long num, t_s *sp, int dig)
{
	int l;
	int k;

	if (sp->point && num == 0)
		dig = 0;
	l = (sp->decim > dig) ? sp->decim - dig : 0;
	k = (sp->decim > dig) ? sp->numb - sp->decim : sp->numb - dig;
	k -= sp->sign || sp->plus;
	if (k < 0)
		k = 0;
	if (ft_put_d_if_specif1(num, sp, k, l))
		;
	else if (!sp->plus && !sp->sign && sp->zero && sp->backsp)
		k = k - ft_put_npl_nsi_ze_ba(num, k, l, sp);
	else if (!sp->plus && !sp->sign && sp->minus)
		ft_put_d_npl_nsi_mi(num, k, l, sp);
	else if (!sp->plus && !sp->sign && sp->backsp)
		k = k - ft_put_npl_nsi_ba(num, k, l, sp);
	else if (ft_put_d_if_specif2(num, sp, k, l))
		;
	else if (sp->sign && sp->backsp)
		k = k - ft_put_si_ba(num, k, l);
	else
		ft_put_else(num, k, l, sp);
	return (dig + (sp->sign || sp->plus || sp->backsp) + l + k);
}

int		ft_put_d(long num, t_s *sp)
{
	int dig;

	num = ft_cast_num(num, sp);
	dig = digits_in_base(num, 10);
	if (num == -2147483648)
		return (ft_put_int_min_with_spec(sp));
	if (num < 0)
	{
		num = -num;
		sp->sign = 1;
	}
	if (sp->numb || sp->point)
		return (ft_put_d_with_numb_point(num, sp, dig));
	else
		return (ft_put_d_without_numb_point(num, sp) + dig);
	return (0);
}
