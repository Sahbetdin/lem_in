/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:15:13 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 19:15:16 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_d_npl_nsi_mi_ba(long num, int *k, int l, t_s *sp)
{
	*k = *k - 1;
	write(1, " ", 1);
	ft_put_n_chars(48, l);
	if (!(sp->point && num == 0))
		ft_put_long(num);
	ft_put_n_chars(32, *k);
}

void	ft_put_d_npl_nsi_ze(long num, int k, int l, t_s *sp)
{
	if (sp->point)
		ft_put_n_chars(32, k);
	else
		ft_put_n_chars(48, k);
	ft_put_n_chars(48, l);
	if (!(sp->point && num == 0))
		ft_put_long(num);
}

void	ft_put_d_npl_nsi_mi(long num, int k, int l, t_s *sp)
{
	ft_put_n_chars(48, l);
	if (!(sp->point && num == 0))
		ft_put_long(num);
	ft_put_n_chars(32, k);
}

void	ft_put_d_si_mi(long num, int k, int l)
{
	write(1, "-", 1);
	ft_put_n_chars(48, l);
	ft_put_long(num);
	ft_put_n_chars(32, k);
}

void	ft_put_si_ze(long num, int k, int l, t_s *sp)
{
	if (sp->point)
	{
		ft_put_n_chars(32, k);
		write(1, "-", 1);
	}
	else
	{
		write(1, "-", 1);
		ft_put_n_chars(48, k);
	}
	ft_put_n_chars(48, l);
	ft_put_long(num);
}
