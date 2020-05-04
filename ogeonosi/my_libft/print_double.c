/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:49:18 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 18:49:21 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_memory(t_uint *s)
{
	t_uint	i;
	char	u;

	ft_putnbr_positive(s[0]);
	write(1, " ", 1);
	i = 1;
	while (i <= s[0])
	{
		u = (char)(s[i] + 48);
		write(1, &u, 1);
		i++;
		if (i % 4 == 1)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

int		print_double_whole_part(t_uint *s)
{
	int		i;
	int		count;
	char	u;

	i = s[0];
	count = 0;
	while (i && s[i] == 0)
		i--;
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (i > 0)
	{
		u = (char)s[i] + '0';
		write(1, &u, 1);
		count++;
		i--;
	}
	return (count);
}

int		print_double_decimal_part(t_uint *s, int n)
{
	t_uchar	u;
	int		i;

	i = 1;
	while (i <= n)
	{
		u = (unsigned char)s[i] + '0';
		write(1, &u, 1);
		i++;
	}
	return (n);
}

void	print_binary_t_uint(t_uint num, int dig)
{
	t_uint	flag;

	if (dig > 31 || dig < 0)
		return ;
	flag = 1 << dig;
	while (flag)
	{
		if (flag & num)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		flag = flag >> 1;
	}
	write(1, "\n", 1);
}

void	print_binary_t_ulong(t_ulong num, int dig)
{
	t_ulong	flag;

	if (dig > 63 || dig < 0)
		return ;
	flag = 1LU << dig;
	while (flag)
	{
		if (flag & num)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		flag = flag >> 1;
	}
	write(1, "\n", 1);
}
