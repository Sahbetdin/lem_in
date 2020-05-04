/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_sp5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 21:48:28 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 21:48:31 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(char *fmt, ...)
{
	va_list	ap;
	char	*p;
	int		ret;
	t_s		*sp;

	sp = (t_s *)malloc(sizeof(t_s));
	va_start(ap, fmt);
	p = fmt;
	ret = process_specifier_main(sp, p, ap);
	free(sp);
	va_end(ap);
	return (ret);
}
