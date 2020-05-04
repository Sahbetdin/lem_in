/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_sp4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:55:07 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 18:55:09 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		process_specifier_double(t_s *sp)
{
	if (sp->s == 'f' || sp->s == 'F' || sp->s == 'e' || sp->s == 'E' ||
	(sp->s == 'l' && sp->s1 == 'f'))
		return (1);
	else
		return (0);
}

int		process_specifier(t_s *sp, va_list ap)
{
	if (process_x_o(sp))
		return (ft_put_x_o(va_arg(ap, t_ulong), sp));
	else if (process_integers(sp))
		return (ft_put_d(va_arg(ap, long long), sp));
	else if (process_specifier_double(sp))
		return (ft_put_whole_double(va_arg(ap, double), sp));
	else if ((sp->s == 'L') && (sp->s1 == 'f' || sp->s1 == 'F' ||
			sp->s1 == 'e' || sp->s1 == 'E'))
		return (ft_put_long_double(va_arg(ap, long double), sp));
	else if (sp->s == 'c')
		return (ft_putchar_c(va_arg(ap, int), sp));
	else if (sp->s == 'p')
		return (ft_put_p(va_arg(ap, long), sp));
	else if (sp->s == 's')
		return (ft_put_string(va_arg(ap, char *), sp));
	else if (sp->s == '%')
		return (ft_put_percentage(sp));
	else if (sp->s == 'V')
		return (ft_memory_float(va_arg(ap, double)));
	else if (sp->s == 'W')
		return (ft_memory_ldbl(va_arg(ap, long double)));
	return (0);
}

char	*process_specifier_s1_s2(char *s, char sp2)
{
	if (sp2)
		return (s + 3);
	else
		return (s + 2);
}

int		process_specifier_main(t_s *sp, char *p, va_list ap)
{
	char	*s;
	int		ret;

	ret = 0;
	while (*p)
	{
		if (*p == '%')
		{
			if ((s = parse_sier(p + 1, sp)))
			{
				ret += process_specifier(sp, ap);
				if (sp->s1)
					p = process_specifier_s1_s2(s, sp->s2);
				else
					p = s + 1;
				continue;
			}
			else
				return (0);
		}
		else
			ret += ft_putchar(*p);
		p++;
	}
	return (ret);
}
