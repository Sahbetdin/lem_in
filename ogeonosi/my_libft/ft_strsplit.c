/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:51:06 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/25 18:57:14 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words_num(char const *s, char c)
{
	size_t	i;
	int		cntr;

	i = 0;
	cntr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cntr++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cntr);
}

static char		*check_allocation(char **tab, int k)
{
	if (!tab[k])
	{
		k--;
		while (--k >= 0)
			free(tab[k]);
		return (NULL);
	}
	return (tab[k]);
}

static char		**set_tab(char **tab, char const *s, char c)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			tab[k] = ft_strndup(s + j, i - j);
			if (!check_allocation(tab, k))
				return (NULL);
			k++;
		}
		tab[k] = NULL;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (!s || c == 0)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * \
					(words_num(s, c) + 1))) || !s || c == 0)
		return (NULL);
	tab = set_tab(tab, s, c);
	return (tab);
}
