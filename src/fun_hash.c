#include "../lem_in.h"


//function that calculates hashes for 
//string *str of length len
int		hash_calculate(char *str, int len, int hash_size)
{
	int value;
	int i;

	value = 0;
	i = 0;
	while (i < len)
	{
		value = value * 37 + str[i];
		if (value >= hash_size)
			value = value % hash_size; //because % operation is costy
		i++;
	}
	// ft_printf("%s : %d\n", str, value);
	return (value);
}

void	print_hash(t_hash **h, int hash_size)
{
	t_hash *tmp;
	t_linked *head;
	int i;

	i = 0;
	while (i < hash_size)
	{
		tmp = h[i];
		ft_printf("%d: ", i);
		while (tmp)
		{
			ft_printf("\033[0;35m%s\033[0m; st: %d; \033[0;32mord: %d\033[0m\033[0;31m->\033[0m", tmp->v->name, tmp->v->status, tmp->v->order);
			head = tmp->v->neighbour;
			while (head)
			{
				ft_printf("%d->", head->data);
				head = head->next;
			}
			ft_printf("nil \n");
			tmp = tmp->next;
		}

		ft_printf("NULL\n");
	i++;
	}
}


//function creates v vertex and assigns st status (start,middle,end)
//name of vertex *line [without coordinates!], and order in graph
//then increases f->max_order by 1.
//Obviosely, when finished max_order will keep total number of vertice
t_bool	assign_line_to_hashmap(t_map *f, t_status st, char *line, int order)
{
	int		place;
	t_hash	*tmp_h;
	char	*backsp;

	if (!(tmp_h = (t_hash *)malloc(sizeof(t_hash))))
		return (false);
	tmp_h->next = NULL;
	if ((backsp = ft_strchr(line, ' ')) == NULL)
		return (false);
	tmp_h->v = vertex_init(line, backsp - line, st, f->max_order);
	if (st == begin)
		f->start_vertex = f->max_order;
	else if (st == end)
		f->end_vertex = f->max_order;
	place = hash_calculate(line, backsp - line, f->hash_size);
	if (f->first_raw[place] == NULL)
		f->first_raw[place] = tmp_h;
	else
	{
		tmp_h->next = f->first_raw[place];
		f->first_raw[place] = tmp_h;
	}
	f->max_order++;
	return (true);
}


char	*assign_start_end_to_hashmap(t_map *f, char *line, t_status st)
{
	int res;


	free(line); //the next line should be not 0 length, doesn't contain '-' and not comment
	if (!((res = get_next_line(f->fd, &line)) != 0 && 
	!ft_strchr(line, '-') && line[0] != '#'))
	{
		ft_printf("ERROR: in assigning start/end vertex\n");
		exit(0);
	}
	if (assign_line_to_hashmap(f, st, line, f->max_order) == false)
		return (NULL);
	return (line);
}