/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_strings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 21:34:05 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 21:34:07 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_percentage(t_s *sp)
{
	if (sp->minus)
	{
		ft_putchar('%');
		ft_put_n_chars(32, sp->numb - 1);
		return (sp->numb);
	}
	else if (sp->numb)
	{
		if (sp->zero)
			ft_put_n_chars(48, sp->numb - 1);
		else
			ft_put_n_chars(32, sp->numb - 1);
		ft_putchar('%');
		return (sp->numb);
	}
	else
		ft_putchar('%');
	return (1);
}

int		ft_put_null(t_s *sp)
{
	int k;

	if (sp->point)
		k = sp->numb - sp->decim;
	else
		k = sp->numb - 6;
	if (sp->minus)
	{
		if (sp->point)
			write(1, "(null)", sp->decim);
		else
			write(1, "(null)", 6);
		ft_put_n_chars(32, k);
	}
	else
	{
		ft_put_n_chars(32, k);
		if (sp->point)
			write(1, "(null)", sp->decim);
		else
			write(1, "(null)", 6);
	}
	return (0);
}

int		ft_get_l_strings(t_s *sp, int n)
{
	int l;

	if (sp->point)
		l = (sp->decim > n) ? n : sp->decim;
	else
		l = n;
	return (l);
}

int		ft_get_k_strings(t_s *sp, int l, int n)
{
	int k;

	if (sp->point)
		k = sp->numb - l;
	else
		k = sp->numb - n;
	if (k < 0)
		k = 0;
	return (k);
}

void	ft_put_str_k_l(t_s *sp, char *str, int k, int l)
{
	if (sp->minus)
	{
		write(1, str, l);
		ft_put_n_chars(32, k);
	}
	else
	{
		ft_put_n_chars(32, k);
		write(1, str, l);
	}
}
