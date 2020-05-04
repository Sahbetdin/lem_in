/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:05:35 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 20:05:38 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_long_arithm(t_long *lng)
{
	free(lng->whole);
	free(lng->decimal);
	free(lng);
}

int		put_double_new(double x, t_s *sp)
{
	int			count;
	t_long		*lng;

	count = 0;
	if (!(lng = create_long(x, sp->decim)))
		return (0);
	normalize(lng->whole, lng->decimal, sp->decim);
	count += print_double_whole_part(lng->whole);
	if (!sp->hash && sp->decim == 0 && sp->point)
	{
		free_long_arithm(lng);
		return (count);
	}
	write(1, ".", 1);
	count++;
	print_double_decimal_part(lng->decimal, sp->decim);
	free_long_arithm(lng);
	return (count);
}

int		ft_put_f_double(double a, t_s *sp)
{
	if (sp->s == 'f' || sp->s == 'F' || (sp->s == 'l' && sp->s1 == 'f'))
		return (put_double_new(a, sp));
	else if (sp->s == 'L' && sp->s1 == 'f')
		return (ft_put_long_double(a, sp));
	else
		return (0);
}

int		ft_memory_float(double a)
{
	t_double	num;

	num.dbl = a;
	write(1, "sign:     ", 10);
	print_binary_t_uint(num.parts.sign, 0);
	write(1, "exponent: ", 10);
	print_binary_t_uint(num.parts.exponent, 10);
	write(1, "mantissa: ", 10);
	print_binary_t_ulong(num.parts.mantissa, 51);
	return (94);
}

int		ft_memory_ldbl(long double a)
{
	t_long_dbl	num;

	num.l_dbl = a;
	write(1, "sign:     ", 10);
	print_binary_t_uint(num.parts.sign, 0);
	write(1, "exponent: ", 10);
	print_binary_t_uint(num.parts.exponent, 14);
	write(1, "mantissa: ", 10);
	print_binary_t_ulong(num.parts.mantissa, 63);
	return (0);
}
