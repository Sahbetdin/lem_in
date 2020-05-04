/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_o_u_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:10:15 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/22 21:10:17 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_prelimenaries(t_s *sp)
{
	if (sp->hash)
	{
		if (sp->hash == 1)
			write(1, "0", 1);
		else if ((sp->s == 'x' ||
			(sp->s == 'h' && sp->s1 == 'x') ||
			(sp->s == 'l' && sp->s1 == 'x') ||
			(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'x') ||
			(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'x')) &&
			sp->hash == 2)
			write(1, "0x", 2);
		else if ((sp->s == 'X' ||
			(sp->s == 'h' && sp->s1 == 'X') ||
			(sp->s == 'l' && sp->s1 == 'X') ||
			(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'X') ||
			(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'X')) &&
			sp->hash == 2)
			write(1, "0X", 2);
	}
}

int		ft_put_o_x_if_u(t_s *sp)
{
	if (sp->s == 'u' || (sp->s == 'l' && sp->s1 == 'u') ||
	(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'u') ||
	(sp->s == 'h' && sp->s1 == 'u') ||
	(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'u'))
		return (1);
	else
		return (0);
}

int		ft_put_integer_u(t_ulong u_value, t_s *sp)
{
	int n;

	n = 0;
	if (ft_put_o_x_if_u(sp))
		n += ft_itoa_base_unsigned(u_value, 10, 0);
	else if (sp->s == 'o' ||
	(sp->s == 'h' && sp->s1 == 'o') || (sp->s == 'l' && sp->s1 == 'o') ||
	(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'o') ||
	(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'o'))
		n += ft_itoa_base_unsigned(u_value, 8, 0);
	else if (sp->s == 'x' ||
		(sp->s == 'l' && sp->s1 == 'x') || (sp->s == 'l' && sp->s1 == 'l' &&
		sp->s2 == 'x') || (sp->s == 'h' && sp->s1 == 'x') ||
		(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'x'))
		n += ft_itoa_base_unsigned(u_value, 16, 0);
	else if (sp->s == 'X' ||
		(sp->s == 'l' && sp->s1 == 'X') || (sp->s == 'l' && sp->s1 == 'l' &&
		sp->s2 == 'X') || (sp->s == 'h' && sp->s1 == 'X') ||
		(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'X'))
		n += ft_itoa_base_unsigned(u_value, 16, 1);
	return (n);
}

int		ft_dig_x_o(t_ulong num, t_s *sp)
{
	int dig;

	dig = 0;
	if (ft_put_o_x_if_u(sp))
		dig = digits_in_base_unsigned(num, 10);
	else if (sp->s == 'o' ||
		(sp->s == 'l' && sp->s1 == 'o') ||
		(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'o') ||
		(sp->s == 'h' && sp->s1 == 'o') ||
		(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'o'))
		dig = digits_in_base_unsigned(num, 8);
	else if (sp->s == 'x' || sp->s == 'X' ||
		((sp->s == 'l' && (sp->s1 == 'x' || sp->s1 == 'X'))) ||
		(sp->s == 'l' && sp->s1 == 'l' && (sp->s2 == 'x' || sp->s2 == 'X'))
		|| (sp->s == 'h' && (sp->s1 == 'x' || sp->s1 == 'X')) ||
		(sp->s == 'h' && sp->s1 == 'h' && (sp->s2 == 'x' || sp->s2 == 'X')))
		dig = digits_in_base_unsigned(num, 16);
	if (sp->hash && (sp->s == 'x' || sp->s == 'X' || (sp->s == 'h' &&
		(sp->s1 == 'x' || sp->s1 == 'X')) || (sp->s == 'l' && (sp->s1 == 'x'
		|| sp->s1 == 'X')) || (sp->s == 'l' && sp->s1 == 'l' && (sp->s2 == 'x'
		|| sp->s2 == 'X')) || (sp->s == 'h' && sp->s1 == 'h' && (sp->s2 == 'x'
		|| sp->s2 == 'X'))))
		sp->hash = 2;
	return (dig);
}

void	ft_put_x_o_l_k(t_s *sp, int l, int k)
{
	if (sp->minus)
	{
		ft_put_prelimenaries(sp);
		ft_put_n_chars(48, l);
	}
	else
	{
		ft_put_n_chars(32, k);
		ft_put_prelimenaries(sp);
		ft_put_n_chars(48, l);
	}
}
