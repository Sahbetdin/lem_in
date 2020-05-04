/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:29:49 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/26 20:30:56 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_pgcd returns greatest common divisor of two integers.
*/

int	ft_pgcd(int a, int b)
{
	if (a == 0)
		return (b);
	if (b == 0)
		return (a);
	return (ft_pgcd(b, (a % b)));
}
