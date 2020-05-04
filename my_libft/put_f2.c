/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:43:58 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 20:44:00 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_double_help_npl_nsi_mi_ba(double a, t_s *sp, int k)
{
	write(1, " ", 1);
	ft_put_f_double(a, sp);
	ft_put_n_chars(32, k);
}

void	ft_put_double_help_npl_mi(double a, t_s *sp, int k)
{
	if (sp->sign)
		write(1, "-", 1);
	else if (sp->backsp)
		write(1, " ", 1);
	ft_put_f_double(a, sp);
	ft_put_n_chars(32, k);
}

void	ft_put_double_help_npl_nsi_ba(double a, t_s *sp, int k)
{
	write(1, " ", 1);
	if (sp->zero)
		ft_put_n_chars(48, k);
	else
		ft_put_n_chars(32, k);
	ft_put_f_double(a, sp);
}

void	ft_put_double_help_si_ze(double a, t_s *sp, int k)
{
	write(1, "-", 1);
	ft_put_n_chars(48, k);
	ft_put_f_double(a, sp);
}
