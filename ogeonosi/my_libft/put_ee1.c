/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ee1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:15:58 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 19:15:59 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_sign(t_s *sp)
{
	if (sp->sign)
		write(1, "-", 1);
	else if (sp->plus)
		write(1, "+", 1);
}

void	ft_put_exp(t_s *sp, int dig)
{
	if (sp->s == 'e' || sp->s1 == 'e')
		write(1, "e", 1);
	else if (sp->s == 'E' || sp->s1 == 'E')
		write(1, "E", 1);
	if (dig < 0)
		write(1, "-", 1);
	else
		write(1, "+", 1);
}

int		ft_put_exp_value(int exp_)
{
	if (exp_ < 0)
		exp_ = -exp_;
	else
		exp_ -= 1;
	if (exp_ < 10)
	{
		write(1, "0", 1);
		ft_putchar(exp_ + '0');
	}
	else
		ft_putnbr_positive(exp_);
	if (exp_ < 100)
		return (2);
	else if (exp_ < 1000)
		return (3);
	else if (exp_ < 10000)
		return (4);
	else
		return (5);
}

void	normalize_sci(t_uint *s, int d)
{
	int		i;

	i = d;
	if (s[i + 1] > 4)
	{
		s[i]++;
		while (s[i] > 9 && i > 1)
		{
			s[i] -= 10;
			s[i - 1]++;
			i--;
		}
	}
}

t_uint	*create_one_array_e(t_long *lng)
{
	t_uint	*arr;
	t_uint	i;

	if (!(arr = (t_uint *)malloc(sizeof(t_uint) * (lng->whole[0] +
	lng->decimal[0] + 1))))
		return (NULL);
	arr[0] = lng->whole[0] + lng->decimal[0];
	i = 0;
	while (++i < arr[0])
		arr[i] = 0;
	return (arr);
}
