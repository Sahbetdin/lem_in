/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:24:49 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/26 20:27:59 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_signum extracts the sign of a number.
** it returns 1 if the argument is > 0, -1 if argument is < 0
** and 0 in case of 0.
*/

int	ft_signum(int num)
{
	if (num > 0)
		return (1);
	else if (num < 0)
		return (-1);
	else
		return (0);
}
