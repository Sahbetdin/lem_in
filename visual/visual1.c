#include <stdio.h>
#include <unistd.h>
#include "../lem_in.h"

void	remove_coma(FILE *file)
{
	int		position;

	fseeko(file, -2, SEEK_END);
	position = ftello(file);
	ftruncate(fileno(file), position);
}

void		visual(t_map *f)
{
	FILE	*file;
	char	*a = "{ \"data\": { \"id\": \"";
	char	*b = "\"}},\n";
	char    *start = f->rooms_ordered[f->start_vertex];
	char    *end = f->rooms_ordered[f->end_vertex];
	size_t	nodes = f->max_order;
	size_t	s = 0;
	int  i;
	int	 j;
	t_linked *tmp_lst;

	file = fopen("./visual/data.json", "w");
	fprintf(file, "{\n\"nodes\": \n[");

	fprintf(file, "%s%s\", \"type\": \"start%s", a, start, b);
	fprintf(file, "%s%s\", \"type\": \"end%s", a, end, b);
	while (s < nodes)
	{
		if (f->rooms_ordered[s] == start || f->rooms_ordered[s] == end)
			s++;
		else
		{
			fprintf(file, "%s%s", a, f->rooms_ordered[s]);
			fprintf(file, "%s", b);
			s++;
		}
	}
	fseeko(file, -2, SEEK_END);
	ftruncate(fileno(file), ftello(file));
	i = 0;
	fprintf(file, "],\n\"edges\":\n[");
	j = 0;
	while (i < f->max_order)
	{
		tmp_lst = f->g[i];
		while (tmp_lst)
		{
			fprintf(file, "%se%d\",\"source\":\"%s\",\"target\":\"%s\"}},\n", a, j, f->rooms_ordered[i], f->rooms_ordered[tmp_lst->data]);
			tmp_lst = tmp_lst->next;
			j++;
		}
		i++;
	}
	remove_coma(file);
	fprintf(file, "],\n\"paths\":\n[");
}
