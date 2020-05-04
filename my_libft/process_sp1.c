/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_sp1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:52:04 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 18:52:06 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clear_spec(t_s *sp)
{
	sp->s = '\0';
	sp->s1 = '\0';
	sp->s2 = '\0';
	sp->zero = 0;
	sp->point = 0;
	sp->numb = 0;
	sp->decim = -1;
	sp->plus = 0;
	sp->minus = 0;
	sp->backsp = 0;
	sp->sign = 0;
	sp->hash = 0;
	return ;
}

void	handle_lhl(char *p, t_s *sp)
{
	sp->s = *p;
	if (*p == 'l')
	{
		sp->s1 = *(p + 1);
		if (sp->s1 == 'l')
			sp->s2 = *(p + 2);
	}
	else if (*p == 'h')
	{
		sp->s1 = *(p + 1);
		if (sp->s1 == 'h')
			sp->s2 = *(p + 2);
	}
	else if (*p == 'L')
		sp->s1 = *(p + 1);
}

char	*find_spec(char *p, t_s *sp)
{
	char	*lett;

	if (!(lett = ft_strdup("diuolhxXfFLeEgGaAcspnVW%")))
		return (NULL);
	while (*p)
	{
		if (*p == ' ' || *p == '\t' || *p == '.' || (*p >= '0' && *p <= '9')
			|| *p == '+' || *p == '-' || *p == '#')
			p++;
		else if (ft_strchr(lett, *p))
		{
			handle_lhl(p, sp);
			free(lett);
			return (p);
		}
		else
		{
			free(lett);
			return (NULL);
		}
	}
	free(lett);
	return (NULL);
}

void	set_zero(char *p, char *s, t_s *sp)
{
	while (*p && p < s)
	{
		if (*p == ' ' || *p == '\t' || *p == '+' || *p == '-' || *p == '#')
			p++;
		else if (*p == '0')
		{
			sp->zero = *p;
			return ;
		}
		else
			return ;
	}
	return ;
}
