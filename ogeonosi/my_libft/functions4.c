/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:42:51 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 18:42:58 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_letters_s(char *letters, char *s)
{
	free(letters);
	free(s);
}

int		ft_itoa_base_unsigned(t_ulong u_value, int base, int lett_type)
{
	char	*s;
	int		n;
	int		i;
	char	*letters;

	if (u_value == 0)
		return (ft_putchar('0'));
	letters = NULL;
	if (lett_type)
		letters = ft_strdup("0123456789ABCDEF");
	else
		letters = ft_strdup("0123456789abcdef");
	n = digits_in_base_unsigned(u_value, base);
	s = (char *)malloc(sizeof(char) * (n + 1));
	s[n] = '\0';
	i = n - 1;
	while (u_value)
	{
		s[i] = letters[u_value % base];
		u_value /= base;
		i--;
	}
	ft_putstr(s);
	free_letters_s(letters, s);
	return (n);
}
