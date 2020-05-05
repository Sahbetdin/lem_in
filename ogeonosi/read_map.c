#include "lem_in.h"

t_bool 	is_ants(char *line)
{
	int	i;

	if (line == NULL)
		return (false);
	i = 0;
	while (line[i] != '\0')
		if (line[0] == '0' || !ft_isdigit(line[i++]))
			return (false);
	return (true);
}

void	is_command(t_map *f, char **line)
{
	if  (ft_strcmp(*line, "##start") == 0 && f->flag_start == false) {
		*line = assign_start_end_to_hashmap(f, *line, begin); //the other line is returned
		f->flag_start = true;
	}
	else if (ft_strcmp(*line, "##end") == 0 && f->flag_end == false) {
		*line = assign_start_end_to_hashmap(f, *line, end); //the other line is returned
		f->flag_end = true;
	}
}

t_bool	read_map(t_map *f)
{
	int res;
	char *line;
	char *dash;

	while (get_next_line(f->fd, &line))
	{
		if (line == NULL)
			return (false);
		if (is_ants(line))
		{
			if (f->ants != 0 || ft_atoi(line) < 0)
				return (false);
			f->ants = ft_atoi(line);
			f->flag_ants = true; // можно убрать и ориентироваться на f->ants != 0
		}
		else if (line[0] == '#')
			is_command(f, &line);
		else if ((dash = ft_strchr(line, '-')))
		{
			if (parse_links(f, line, dash) == false)
				return (false);
		}
		else if (f->flag_rooms == false)
		{
			if (assign_line_to_hashmap(f, middle, line, f->max_order) == false)
				return (false);
		}
		else if (line[0] == 'L')
			return (false);
		else if (f->flag_rooms == true && dash == NULL)
		{
			ft_printf("ERROR: more vertice come after links\n");
			exit(0);
		}
		free(line);
	}
	if (f->flag_ants == false || f->flag_start == false ||
		f->flag_end == false || f->flag_links == false)
		return (false);
	ft_strdel(&line);
	return (true);
}
