/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:15:22 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 19:15:23 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_int_min_minus(t_s *sp, int k, int l)
{
	if (sp->minus)
	{
		write(1, "-", 1);
		ft_put_n_chars(48, l);
		write(1, "2147483648", 10);
		ft_put_n_chars(32, k);
	}
	else
	{
		ft_put_n_chars(32, k);
		write(1, "-", 1);
		ft_put_n_chars(48, l);
		write(1, "2147483648", 10);
	}
}

int		ft_put_si_ba(long num, int k, int l)
{
	ft_put_n_chars(32, k);
	write(1, "-", 1);
	ft_put_n_chars(48, l);
	ft_put_long(num);
	return (1);
}

void	ft_put_else(long num, int k, int l, t_s *sp)
{
	ft_put_n_chars(32, k);
	if (sp->sign)
		write(1, "-", 1);
	ft_put_n_chars(48, l);
	if (!(sp->point && num == 0))
		ft_put_long(num);
}

int		ft_put_npl_nsi_ba(long num, int k, int l, t_s *sp)
{
	if (k < 1)
		write(1, " ", 1);
	else
		ft_put_n_chars(32, k);
	ft_put_n_chars(48, l);
	if (!(sp->point && num == 0))
		ft_put_long(num);
	return (1);
}

int		ft_put_npl_nsi_ze_ba(long num, int k, int l, t_s *sp)
{
	write(1, " ", 1);
	if (k > 0)
		k--;
	if (sp->point)
	{
		ft_put_n_chars(32, k);
		ft_put_n_chars(48, l);
	}
	else
		ft_put_n_chars(48, k);
	if (!(sp->point && num == 0))
		ft_put_long(num);
	return (1);
}
