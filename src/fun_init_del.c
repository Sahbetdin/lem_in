#include "../lem_in.h"


//initialize farm variables 
void	farm_init(t_map *f)
{
	f->ants = 0;
	f->start_vertex = 0;
	f->end_vertex = 0;
	f->hash_size = 100;
	f->ants = 0;
	f->flag_ants = false;
	f->flag_start = false;
	f->flag_end = false;
	f->flag_rooms = false;
	f->flag_links = false;
	f->found_shortest_path = false;
	f->max_order = 0;
	f->fd = 0;
	f->first_raw = hashmap_init(f->first_raw, f->hash_size);
	f->bfs_order = NULL;
	f->g = NULL;
	f->shortest_path = NULL;
	f->status = NULL;
	f->current_path = 0;
	f->max_paths = 0;
	f->arc1 = NULL;
	f->arc2 = NULL;
}

void	farm_delete(t_map *f)
{
	//очистить весь farm, который содержит hash, который
	//содержит vertex
}

/*
** allocate memory for hash table and initialize it with NULLs
*/
t_hash	**hashmap_init(t_hash **h, int hash_size)
{
	int i;

	h = (t_hash **)malloc(sizeof(t_hash *) * hash_size);
	i = -1;
	while (++i < hash_size)
		h[i] = NULL;
	return (h);
}

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


/*
** allocate memory of length n
** and initialize it with value
*/

int		*arr_init(int n, int value)
{
	int i;
	int *arr;

	arr = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
		arr[i++] = value;
	return (arr);
}

void	arr_clear_with_value(int *arr, int n, int value)
{
	int i;

	i = 0;
	while (i < n)
		arr[i++] = value;
}

t_linked	*del_list_element(t_linked *lst)
{
	lst->next = NULL;
	free(lst);
	return (NULL);
}


void	path_assign(t_map *f, int *arr)
{
	int node;
	int i;
	t_linked *tmp;

	// f->shortest_path = arr_init(f->max_order, -1); //initialize with -1
	node = f->end_vertex; //we go frontwards starting from end_vertex to next neighbour which has bfs_order 1 less than the node's
	i = 0;
	while (f->bfs_order[node] != 1)
	{
		tmp = f->g[node];
		while (tmp)
		{
			if (f->bfs_order[tmp->data] == f->bfs_order[node] - 1)
				break ;
			tmp = tmp->next;
		}
		arr[i] = tmp->data;
		i++;
		node = tmp->data;
	}
	reverse_array(arr, f->max_order); //reverse array of paths
}