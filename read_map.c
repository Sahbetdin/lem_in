#include "lem_in.h"

t_bool	read_map(t_map *f)
{
	int res;
	char *line;
	char *dash;

	while ((res = get_next_line(f->fd, &line)))
	{
		// ft_printf("LINE: %s\n", line);
		// ft_printf("%s . res = %d\n", line, res);
		if (f->flag_ants == false)
		{
			f->ants = ft_atoi(line);
			if (f->ants <= 0)
			{
				free(line);
				ft_printf("ERROR: in ants amount\n");
				exit(0);
			}
			f->flag_ants = true;
		}
		else if (ft_strcmp(line, "##start") == 0 && f->flag_start == false)
		{
			line = assign_start_end_to_hashmap(f, line, begin); //the other line is returned
			f->flag_start = true;
		}
		else if (ft_strcmp(line, "##end") == 0 && f->flag_end == false)
		{
			line = assign_start_end_to_hashmap(f, line, end); //the other line is returned
			f->flag_end = true;
		}
		else if (line[0] == '#')
		{
			free(line);
			continue ;
		}
		else if (ft_strlen(line) == 0)
		{
			free(line);
			ft_printf("ERROR: empty line\n");
			exit(0);
		}
		else if ((dash = ft_strchr(line, '-')))
		{ // we didn't combine else_if - if such that it doesn't enter other if's
			if (parse_links(f, line, dash) == false)
				return (false);
		}
		else if (f->flag_rooms == false)
		{
			if (assign_line_to_hashmap(f, middle, line, f->max_order) == false)
				return (false);
		}
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
	// print_hash(f->first_raw, f->hash_size);
	return (true);
}