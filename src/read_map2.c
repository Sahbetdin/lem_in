/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 20:13:36 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/05/26 17:27:56 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** for lines that start with # we check that it is command, i.e. starts with ##
** to assign start and end. We might implement other commands, as well.
** in the *line = assign_start_end_to_hashmap(..., *line, ...)
** the next (!) line from stdin is returned. In case it's not assigned,
** NULL is returned.
** There is no possibility to have another ##start or ##end in following lines.
** If this is the case return false
** after ft_strcmp(*line, "##start") or ft_strcmp(*line, "##end")
** the next line is returned
** during the last else if we deal only with comment
*/

t_bool	is_command(t_map *f, char **line)
{
	if (ft_strcmp(*line, "##start") == 0 && f->flag_start == false)
	{
		if ((*line = assign_start_end_to_hashmap(f, *line, begin)) == NULL)
			return (false);
		f->flag_start = true;
	}
	else if (ft_strcmp(*line, "##end") == 0 && f->flag_end == false)
	{
		if ((*line = assign_start_end_to_hashmap(f, *line, end)) == NULL)
			return (false);
		f->flag_end = true;
	}
	else if ((ft_strcmp(*line, "##start") == 0 && f->flag_start == true) ||
		(ft_strcmp(*line, "##end") == 0 && f->flag_end == true))
	{
		free(line);
		return (false);
	}
	return (true);
}

/*
** we check the line if it connects two rooms
** (1) there is '-' and no 'L'.
** the room if made up of alnum or '_'
*/

t_bool	is_edge(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '-')
	{
		if (!ft_isalnum(line[i]) && line[i] != '_')
			return (false);
		i++;
	}
	if (line[i++] != '-')
		return (false);
	while (line[i] != '\0')
	{
		if (!ft_isalnum(line[i]) && line[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

/*
** this function checks if the str is room.
** the str[i] should be letter or number or '_'
** in that case it returns true, else false
*/

t_bool	is_room(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((ft_isalnum(str[i]) && str[i] != 'L') ||
		str[i] == '_' || str[i] == ' ')
			i++;
		else
			return (false);
	}
	if (i == 0)
		return (false);
	return (true);
}
