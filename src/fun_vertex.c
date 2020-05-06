#include "../lem_in.h"

/*
** initialize vertex.
** all it's fields are zeros except
** name which is ft_strdup(line)
*/

t_vertex *vertex_init(char *name, int len, t_status st, int order)
{
	t_vertex *v_tmp;

	if (!(v_tmp = (t_vertex *)malloc(sizeof(t_vertex))))
		exit(0);
	v_tmp->name = ft_strndup(name, len);
	v_tmp->len = len;
	v_tmp->neighbour = NULL;
	v_tmp->status = st;
	v_tmp->order = order;
	return (v_tmp);
}


//in hashmap searches the string *start_search of length n
//and returns vertex which name coincides with *start_search
// of length n
t_vertex	*find_vertex(t_map *f, char *start_search, int n)
{
	int i;
	t_vertex *v1;
	t_bool flag_found; //for searching links
	t_hash *tmp_h;
	int place;
	
	i = 0;
	flag_found = false;
	v1 = NULL;
	place = hash_calculate(start_search, n, f->hash_size);
	tmp_h = f->first_raw[place];
	while (tmp_h && flag_found == false)
	{
		if (!ft_strncmp(start_search, tmp_h->v->name, n) && n == tmp_h->v->len)
		{
			flag_found = true;
			v1 = tmp_h->v;
		}
		else
			tmp_h = tmp_h->next;
	}
	return (v1);
}