/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:16:14 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/05/31 13:04:43 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** if anything except digit or '+' or ' ' then return false
** otherwise line is ok and ready for ft_atoi, return true
** I know that we check the empty line in previous line, but
** for some reason we check it one more time here
** if false, we free(line) in the read function,
** possibly in main.
** if (*i_addr == 0) //if the line is zero length return false
*/

t_bool	check_for_digits_in_line(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!(ft_isdigit(line[i]) || line[i] == '+' || line[i] == ' '))
			return (false);
		i++;
	}
	if (i == 0)
		return (false);
	return (true);
}

/*
** in first line we check: (1) it's not empty, (2) it contains
** only digits, possibly + sign, or backspace, (3) then we atoi
** the line. (4) if ants number is 0 we return false,
** (5) if there is a number and it's int32 then we
** set flag_ants to true and return true
** if OK, we FREE the line
*/

t_bool	check_ant_line(t_map *f, char **line)
{
	if (get_next_line(0, line) < 0)
		return (false);
	if (check_for_digits_in_line(*line) == false)
		return (false);
	f->ants = ft_atoi(*line);
	free(*line);
	*line = NULL;
	if (f->ants <= 0)
		return (false);
	f->flag_ants = true;
	return (true);
}

/*
** in 'assign_line_to_hashmap' room names are parsed
*/

t_bool	assign_room(t_map *f, char *line)
{
	if (assign_line_to_hashmap(f, middle, line) == false)
		return (false);
	else if (f->flag_rooms == true)
	{
		ft_printf("ERROR  or more rooms come after links\n");
		return (false);
	}
	return (true);
}

/*
** There was || res_gnl == 0 in gnl.
** means that there is one empty line
*/

t_bool	check_flags_assigned_free_last_line(t_map *f, char *line)
{
	ft_strdel(&line);
	if (f->flag_start == false || f->flag_end == false
	|| f->flag_links == false)
		return (false);
	return (true);
}

/*
** if during gnl we encounter false, we free it in main function
** that's why we need line link from main function
** otherwise we free the line here
** if (!check_ant_line(f, line)) //if ok, then f->flag_ants = true
** if (is_command(f, &line) == false) //if the line with # wasn't
** 		parsed then bad. Убрал || f->flag_rooms == true)
*/

t_bool	read_map(t_map *f, char **line)
{
	int		res_gnl;
	char	*dash;

	if (!check_ant_line(f, line))
		return (false);
	while ((res_gnl = get_next_line(0, line)) > 0)
	{
		if ((*line)[0] == '#')
		{
			if (is_command(f, line) == false)
				return (false);
		}
		else if (is_room(*line))
		{
			if (assign_room(f, *line) == false)
				return (false);
		}
		else if ((dash = ft_strchr(*line, '-')) &&
		parse_links(f, *line, dash) == false)
			return (false);
		ft_strdel(line);
	}
	if (check_flags_assigned_free_last_line(f, *line) == false)
		return (false);
	return (true);
}
