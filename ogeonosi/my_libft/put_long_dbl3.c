/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_long_dbl3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:10:02 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 22:10:04 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_long_double(long double x, t_s *sp)
{
	int			dig;
	int			k;
	int			count;
	t_long_dbl	num;

	if (x < 0)
	{
		sp->sign = 1;
		x = -x;
	}
	num.l_dbl = x;
	if ((k = check_dlng_inf(&num, sp)))
		return (k);
	if (sp->s1 == 'e' || sp->s1 == 'E')
		return (ft_put_whole_sci_ldbl(x, sp));
	dig = ft_dig_ldbl(x);
	count = dig + ft_get_k_for_ldbl(sp, dig) + (sp->plus || sp->sign);
	if (sp->decim > 0)
		count += sp->decim + 1;
	ft_put_from_specif_ldbl(&num, sp, k);
	return (count);
}
