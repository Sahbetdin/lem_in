/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_sp2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:54:56 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 18:54:58 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_plus(char *p, char *s, t_s *sp)
{
	while (*p && p < s)
	{
		if (*p == ' ' || *p == '\t' || *p == '#' || *p == '0' || *p == '-')
			p++;
		else if (*p == '+')
		{
			sp->plus = 1;
			return ;
		}
		else
			return ;
	}
}

void	set_minus(char *p, char *s, t_s *sp)
{
	while (*p && p < s)
	{
		if (*p == ' ' || *p == '\t' || *p == '#' || *p == '0' || *p == '+')
			p++;
		else if (*p == '-')
		{
			sp->minus = 1;
			return ;
		}
		else
			return ;
	}
	return ;
}

void	set_backsp(char *p, char *s, t_s *sp)
{
	while (*p && p < s)
	{
		if (*p == ' ')
		{
			sp->backsp = 1;
			return ;
		}
		else
			p++;
	}
	return ;
}

char	*set_point(char *p, char *s, t_s *sp)
{
	while (*p && p < s)
	{
		if (*p == ' ' || *p == '\t' || (*p >= '0' && *p <= '9')
		|| *p == '+' || *p == '-' || *p == '#')
			p++;
		else if (*p == '.')
		{
			sp->point = 1;
			return (p);
		}
		else
			return (NULL);
	}
	return (NULL);
}

void	set_numb(char *p, char *s, t_s *sp)
{
	while (*p && p < s && (*p == ' ' || *p == '\t'
		|| *p == '+' || *p == '-' || *p == '#' || *p == '0'))
		p++;
	sp->numb = ft_atoi(p);
}
