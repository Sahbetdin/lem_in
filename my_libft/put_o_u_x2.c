/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_o_u_x2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:13:56 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/22 21:13:58 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_x_o_num(t_ulong num, t_s *sp, int k, int dig)
{
	int n;

	if (sp->minus && dig)
		n = ft_put_integer_u(num, sp);
	else if (dig)
		n = ft_put_integer_u(num, sp);
	else
		n = 0;
	if (sp->minus)
		ft_put_n_chars(32, k);
	return (n);
}

t_ulong	ft_cast_num_t_ulong(t_ulong num, t_s *sp)
{
	if (sp->s == 'u' || sp->s == 'o' ||
		sp->s == 'x' || sp->s == 'X')
		num = (t_uint)num;
	else if (sp->s == 'h' && (sp->s1 == 'x' || sp->s1 == 'X'))
		num = (unsigned short)num;
	else if (sp->s == 'h' && sp->s1 == 'h' && (sp->s2 == 'x' ||
	sp->s2 == 'X' || sp->s2 == 'o' || sp->s2 == 'u'))
		num = (unsigned char)num;
	else if (sp->s == 'h' && (sp->s1 == 'o' || sp->s1 == 'u'))
		num = (unsigned short)num;
	return (num);
}

void	ft_put_x_o_process_dig(t_ulong num, t_s *sp, int *addr_dig)
{
	if (sp->hash == 2 && num == 0)
		sp->hash = 0;
	if (sp->hash == 1 && num == 0 && (sp->decim == 0 || sp->decim == -1))
	{
		*addr_dig = 0;
		sp->decim = 1;
		sp->hash = 0;
	}
	if (sp->point && sp->decim == 0 && num == 0)
		*addr_dig = 0;
}

int		ft_put_x_o(t_ulong num, t_s *sp)
{
	int n;
	int dig;
	int l;
	int k;

	num = ft_cast_num_t_ulong(num, sp);
	dig = ft_dig_x_o(num, sp);
	ft_put_x_o_process_dig(num, sp, &dig);
	l = (sp->decim > dig) ? sp->decim - dig : 0;
	if (l > 0 && sp->hash == 1)
		sp->hash = 0;
	k = sp->numb - dig - l - sp->hash;
	if (k < 0)
		k = 0;
	if (sp->zero && !sp->point && !sp->minus)
	{
		l += k;
		k = 0;
	}
	ft_put_x_o_l_k(sp, l, k);
	n = ft_put_x_o_num(num, sp, k, dig);
	return (l + k + n + sp->hash);
}
