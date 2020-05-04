/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ee2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:16:04 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 19:16:05 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_exp(t_long *lng)
{
	t_uint	i;
	int		j;

	i = lng->whole[0];
	while (i > 0 && lng->whole[i] == 0)
		i--;
	j = i;
	if (j <= 0)
	{
		i = 1;
		while (i < lng->decimal[0] && lng->decimal[i] == 0)
			i++;
		j = -i;
	}
	return (j);
}

void	ft_fill_in_one_arr_e(t_uint *arr, t_long *lng, int j)
{
	t_uint		i;

	if (j > 0)
	{
		i = j + 1;
		while (--i > 0)
			arr[j - i + 1] = lng->whole[i];
		i = 1;
		while (i < lng->decimal[0])
		{
			arr[j + i] = lng->decimal[i];
			i++;
		}
	}
	else
	{
		i = 1;
		while (i <= lng->decimal[0] + j)
		{
			arr[i] = lng->decimal[i - j - 1];
			i++;
		}
	}
}

int		ft_put_value_in_e(t_uint *arr, t_s *sp, int j)
{
	int		dig;
	int		i;

	dig = sp->decim + 1;
	normalize_sci(arr, dig);
	if (arr[1] > 9)
	{
		ft_putchar('1');
		if (dig > 1)
			write(1, ".", 1);
		ft_put_n_chars(48, dig - 1);
		j++;
	}
	else
	{
		ft_putchar(arr[1] + '0');
		if (dig > 1)
			write(1, ".", 1);
		i = 1;
		while (++i <= dig)
			ft_putchar(arr[i] + '0');
	}
	free(arr);
	ft_put_exp(sp, j);
	return (j);
}

int		ft_put_e_zero(t_s *sp)
{
	write(1, "0", 1);
	if (sp->decim > 0)
	{
		write(1, ".", 1);
		ft_put_n_chars(48, sp->decim);
	}
	if (sp->s == 'e')
		write(1, "e+00", 4);
	else if (sp->s == 'E')
		write(1, "E+00", 4);
	return (sp->point + sp->decim + 5);
}

int		ft_put_sci(double x, t_s *sp)
{
	int		j;
	t_long	*lng;
	t_uint	*arr;
	int		count;

	if (x == 0)
		return (ft_put_e_zero(sp));
	if (!(lng = create_long(x, sp->decim)))
		return (0);
	if (!(arr = create_one_array_e(lng)))
		return (0);
	j = ft_find_exp(lng);
	ft_fill_in_one_arr_e(arr, lng, j);
	j = ft_put_value_in_e(arr, sp, j);
	count = 3 + (sp->plus || sp->sign);
	if (sp->decim > 0)
		count += sp->decim + 1;
	return (count + ft_put_exp_value(j));
}
