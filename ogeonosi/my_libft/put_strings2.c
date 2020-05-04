/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_strings2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 21:38:55 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 21:38:56 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_string(char *str, t_s *sp)
{
	int		k;
	int		n;
	int		l;
	char	*nil;

	nil = ft_strdup("(null)");
	if (!str)
	{
		n = 6;
		str = nil;
	}
	else
		n = ft_strlen(str);
	l = ft_get_l_strings(sp, n);
	k = ft_get_k_strings(sp, l, n);
	ft_put_str_k_l(sp, str, k, l);
	free(nil);
	return (l + k);
}
