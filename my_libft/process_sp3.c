/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_sp3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:55:01 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 18:55:03 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_decimal(char *p, t_s *sp)
{
	sp->decim = ft_atoi(p);
}

void	set_hash(char *p, char *s, t_s *sp)
{
	while (*p && p < s)
	{
		if (*p == '#')
		{
			sp->hash = 1;
			return ;
		}
		else
			p++;
	}
	return ;
}

char	*parse_sier(char *p, t_s *sp)
{
	char *ptr_lett;
	char *ptr_point;

	clear_spec(sp);
	if ((ptr_lett = find_spec(p, sp)))
	{
		set_zero(p, ptr_lett, sp);
		set_plus(p, ptr_lett, sp);
		set_minus(p, ptr_lett, sp);
		set_numb(p, ptr_lett, sp);
		set_backsp(p, ptr_lett, sp);
		set_hash(p, ptr_lett, sp);
		ptr_point = set_point(p, ptr_lett, sp);
		if (ptr_point)
			set_decimal(ptr_point + 1, sp);
		else if (sp->s == 'f' || sp->s == 'e' || sp->s == 'F' || sp->s == 'E'
			|| ((sp->s == 'L' || sp->s == 'l') && sp->s1 == 'f'))
			sp->decim = 6;
	}
	else
		ptr_lett = NULL;
	return (ptr_lett);
}

int		process_x_o(t_s *sp)
{
	if (sp->s == 'u' || sp->s == 'x'
	|| sp->s == 'X' || sp->s == 'o' ||
	(sp->s == 'l' && sp->s1 == 'u') ||
	(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'u') ||
	(sp->s == 'l' && (sp->s1 == 'x' || sp->s1 == 'X')) ||
	(sp->s == 'l' && sp->s1 == 'l' && (sp->s2 == 'x' || sp->s2 == 'X')) ||
	(sp->s == 'l' && sp->s1 == 'o') ||
	(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'o') ||
	(sp->s == 'h' && (sp->s1 == 'x' || sp->s1 == 'X')) ||
	(sp->s == 'h' && sp->s1 == 'o') ||
	(sp->s == 'h' && sp->s1 == 'h' && (sp->s2 == 'x' || sp->s2 == 'X'
	|| sp->s2 == 'o' || sp->s2 == 'u')) ||
	(sp->s == 'h' && sp->s1 == 'u'))
		return (1);
	else
		return (0);
}

int		process_integers(t_s *sp)
{
	if (sp->s == 'd' || sp->s == 'i' ||
		(sp->s == 'h' && (sp->s1 == 'd' || sp->s1 == 'i')) ||
		(sp->s == 'h' && sp->s1 == 'h' && (sp->s2 == 'd' || sp->s2 == 'i')) ||
		(sp->s == 'l' && (sp->s1 == 'd' || sp->s1 == 'i')) ||
		(sp->s == 'l' && sp->s1 == 'l' && (sp->s2 == 'd' || sp->s2 == 'i')))
		return (1);
	else
		return (0);
}
