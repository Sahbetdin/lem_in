/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:44:04 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 20:44:08 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_double_help_si_ba(double a, t_s *sp, int k)
{
	ft_put_n_chars(32, k);
	write(1, "-", 1);
	ft_put_f_double(a, sp);
}

void	ft_put_double_help_else(double a, t_s *sp, int k)
{
	if (sp->zero)
		ft_put_n_chars(48, k);
	else
		ft_put_n_chars(32, k);
	if (sp->sign)
		write(1, "-", 1);
	ft_put_f_double(a, sp);
}

void	process_sp_for_double(double a, t_s *sp, int k)
{
	if (sp->plus && sp->minus)
		ft_put_double_help_pl_mi(a, sp, k);
	else if (sp->plus && !sp->sign && sp->zero)
		ft_put_double_help_pl_nsi_ze(a, sp, k);
	else if (sp->plus && !sp->sign)
		ft_put_double_help_pl_nsi2(a, sp, k);
	else if (!sp->plus && !sp->sign && sp->minus && sp->backsp)
		ft_put_double_help_npl_nsi_mi_ba(a, sp, k);
	else if (!sp->plus && sp->minus)
		ft_put_double_help_npl_mi(a, sp, k);
	else if (!sp->plus && sp->minus)
		ft_put_double_help_npl_mi(a, sp, k);
	else if (!sp->plus && !sp->sign && sp->backsp)
		ft_put_double_help_npl_nsi_ba(a, sp, k);
	else if (sp->sign && sp->zero)
		ft_put_double_help_si_ze(a, sp, k);
	else if (sp->sign && sp->backsp)
		ft_put_double_help_si_ba(a, sp, k);
	else
		ft_put_double_help_else(a, sp, k);
}

int		ft_put_whole_double(double a, t_s *sp)
{
	int			k;
	int			n;
	int			dig;

	if ((n = check_double_inf(a, sp)))
		return (n);
	if (a < 0)
	{
		sp->sign = 1;
		a = -a;
	}
	if (sp->s == 'e' || sp->s == 'E')
		return (ft_put_whole_sci(a, sp));
	dig = digits_in_base((long)a, 10);
	if (!(sp->numb || sp->decim))
		return (ft_put_double_help_pl_nsi(a, sp));
	n = ft_put_double_set_k(sp, dig);
	k = (sp->numb > n) ? sp->numb - n : 0;
	process_sp_for_double(a, sp, k);
	return (k + n);
}
