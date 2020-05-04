/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:20:08 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/16 13:12:57 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	char *str;

	if (!s)
		return ;
	str = s;
	while (*str)
	{
		*str = '\0';
		str++;
	}
}
