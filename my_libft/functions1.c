/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:42:33 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 18:42:36 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_zeros_backsp(t_s *sp)
{
	if (sp->numb > 1)
	{
		if (sp->zero)
			ft_put_n_chars(48, sp->numb - 1);
		else
			ft_put_n_chars(32, sp->numb - 1);
	}
	else
		sp->numb = 1;
}

int		ft_putchar_c(char c, t_s *sp)
{
	if (sp->minus)
	{
		write(1, &c, 1);
		ft_put_zeros_backsp(sp);
	}
	else
	{
		ft_put_zeros_backsp(sp);
		write(1, &c, 1);
	}
	return (sp->numb);
}
