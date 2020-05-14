#include "../lem_in.h"

t_bool 	is_ants(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
		if (!ft_isdigit(line[i++]))
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
	ft_strdel(line);
}

t_bool is_edge(char *line)
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

t_bool is_node(char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'L')
		return (false);
	while (line[i] != '\0' && line[i] != ' ')
	{
		if (!ft_isalnum(line[i]) && line[i] != '_')
			return (false);
		i++;
	}
	if (line[i++] != ' ')
		return (false);
	while (line[i] != '\0' && line[i] != ' ')
		if (!ft_isdigit(line[i++]))
			return (false);
	if (line[i++] != ' ')
		return (false);
	while (line[i] != '\0')
		if (!ft_isdigit(line[i++]))
			return (false);
	return (true);
}

t_bool ants_init(t_map *f, char **line)
{
	while(get_next_line(f->fd, &(*line)))
	{
		if (is_ants(*line))
		{
			if (f->ants != 0 || ft_atoi(*line) < 0)
				return (false);
			f->ants = ft_atoi(*line);
			if (f->ants == 0)
				return (false);
			ft_strdel(&(*line));
			break;
		}
	}
	return (true);
}

t_bool		rest_init(t_map *f, char **line, int *res_gnl)
{
	while ((*res_gnl = get_next_line(f->fd, &(*line))) > 0)
	{
		if (is_ants(*line))
			return (false);
		if (*line[0] == '#')
			is_command(f, &(*line));
		else if (is_node(*line))
		{
			if (assign_line_to_hashmap(f, middle, *line, f->max_order) == false)
				return (false);
		}
		else if (is_edge(*line))
		{
			if (parse_links(f, *line, ft_strchr(*line, '-')) == false)
				return(false);
		}
		ft_strdel(&(*line));
	}
	return(true);
}

t_bool	read_map(t_map *f)
{
	int		res_gnl;
	char	*line;

	if (ants_init(f, &line) == false)
		return (false);
	if (rest_init(f, &line, &res_gnl) == false)
		return (false);
	if (f->flag_start == false || f->flag_end == false
	|| f->flag_links == false || res_gnl == -1)
		return (false);
	ft_strdel(&line);
	return (true);
}
