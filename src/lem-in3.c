#include "../lem_in.h"

//from all neighbors of node deletes it.
//then deletes all neighbors of node. 
void	delete_node(t_map *f, int node)
{
	t_linked *tmp; //this is node
	t_linked *lst;

	tmp = f->g[node];
	while (tmp)
	{
		if ((lst = delete_arc(f, tmp->data, node)))		
			free(lst);
		// ft_printf("neighbor of node is %d\n", tmp->data);
		tmp = tmp->next;
	}
	del_linked_list(f->g + node);
}


/*
** used for reversing paths since, the elements start from end_vertex. 
** the path consists of nodes and then -1's
** reverses arr without taking into account -1's;
** b is temporary value
*/

void    reverse_array(int *arr, int n)
{
	int i;
	int i_2;
	int j;
	int b;

	i = -1;
	while (i < n && arr[++i] != -1)
		;
	i_2 = i / 2;
	j = 0;
	while (j < i_2)
	{
		b = arr[j];
		arr[j] = arr[i - 1 - j];
		arr[i - 1 - j] = b;
		j++;
	}
}

/*
** if f->shortest_path is totally present in f->paths[i], i.e. each vertex is present
** then return 2
** else if f->shortest_path is partially present in f->paths[i], i.e.
** at least one, then return 1
** else if f->shortest_path doesn't have any common vertice with f->paths[i] then return 0
*/

char	find_shortest_path_vertice_in_current_path(t_map *f)
{
	int i;
	int j;
	int count;
	int	n_elem;

	i = 0;
	count = 0;
	n_elem = 0;
	while (i < f->max_order && f->shortest_path[i] != -1)
	{
		j = 0;
		while (j < f->max_order && f->paths[f->current_path][j] != -1)
		{
			if (f->shortest_path[i] == f->paths[f->current_path][j])
			{
				count++;
				break ;
			}
			j++;
		}
		n_elem++;
		i++;
	}
	if (n_elem == count)
		return (2);
	else if (count > 0)
		return (1);
	else
		return (0);
}

/*
** delete all nodes from one of the paths which is arr here
** we walk through arr until encounter -1
*/

void	delete_trace(t_map *f, int *arr)
{
	int i;

	i = 0;
	while (i < f->max_order && arr[i] != -1)
	{
		// ft_printf("now delete nodes: %d\n", arr[i]);
		delete_node(f, arr[i]);
		i++;
	}
}

/*
** copy src_path to dest_path max n elements.
** if encounter -1 then stop
** the result is that all src_path should be in dest_path.
** even -1 elements
*/

void	copy_paths(int *dest_path, int *src_path, int n)
{
	int i;

	i = 0;
	while (i < n && (src_path[i] != -1 || dest_path[i] != -1))
	{
		dest_path[i] = src_path[i];
		i++;
	}
}

void	put_back_removed_arcs(t_map *f)
{
	f->arc2->next = f->g[f->arc1->data]; //bring back deleted edge
	f->g[f->arc1->data] = f->arc2;	//to each vertex
	f->arc1->next = f->g[f->arc2->data];
	f->g[f->arc2->data] = f->arc1;
}

//n is number of paths
//m is number of elements in a path (-1s inclusive)
void	print_all_paths(int **arr, int n, int m)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		ft_printf("\033[0;33m"); //yellow
		ft_printf("path[%d]:", i);		
		ft_printf("\033[0m"); //white
		j = 0;
		while (j < m && arr[i][j] != -1)
		{
			ft_printf(" %d ", arr[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	work_with_bfs(t_map *f)
{
	int			i;
	t_linked	*tmp;
	int			x; //current bfs_oreder
	int			node; //current node number
	t_linked	*t1;
	t_linked	*t2;
	char		b;

	bfs(f, f->start_vertex);
	//в первый раз не забыть проверить, чтоб start, end были в одной компоненте связности
	// if (f->bfs_order[f->end_vertex] == -1)
	// {
	// 	ft_printf("END ROOM is in the other component"); //не забыть освободить память
	// 	exit (0);
	// }
	if (f->found_shortest_path == false)
	{
		path_assign(f, f->shortest_path); //we find the shortest path from bfs 
		print_path(f->shortest_path, f->max_order);
		f->arc1 = delete_arc(f, f->start_vertex, f->shortest_path[0]); //these are the arcs from 
		f->arc2 = delete_arc(f, f->shortest_path[0], f->start_vertex); //start_vertex to 1st nearest node 
		// print_graph(f->g, f->max_order);
		f->found_shortest_path = true;
	}
	else
	{
		path_assign(f, f->paths[f->current_path]);
		put_back_removed_arcs(f);

		if ((b = find_shortest_path_vertice_in_current_path(f)) == 2)
		{
			// ft_printf("need to return deleted edge\n");
			copy_paths(f->paths[0], f->shortest_path, f->max_order);
			delete_trace(f, f->paths[f->current_path]);
			while (f->current_path < f->max_paths)
			{
				bfs(f, f->start_vertex);
				// ft_printf("bfs_order for end_vertex: %d\n", f->bfs_order[f->end_vertex]);
				if (f->bfs_order[f->end_vertex] == -1) //this case means that the graph is disconnected
					break ;
				f->current_path++;
				path_assign(f, f->paths[f->current_path]);
				// print_path(f->paths[f->current_path], f->max_order);
				delete_trace(f, f->paths[f->current_path]);
			}
			ft_printf("Found %d paths\n", f->current_path + 1);
		}

		else if (b == 1)
		{
			ft_printf("YEAH, b is indeed %d\n", b);
			// ft_printf("    curr_path is %d\n", f->current_path);
			// ft_printf("    max_path is %d\n", f->max_paths);
			// print_all_paths(f->paths, f->max_paths, f->max_order);
			// print_graph(f->g, f->max_order);

			while (f->current_path < f->max_paths)
			{
				delete_trace(f, f->paths[f->current_path]);
				bfs(f, f->start_vertex);
			// // 	// ft_printf("bfs_order for end_vertex: %d\n", f->bfs_order[f->end_vertex]);
			// // 	print_graph(f->g, f->max_order);
				
				if (f->bfs_order[f->end_vertex] == -1) //this case means that the graph is disconnected
					break ;				
				
			// // 	ft_printf("YES\n");
				f->current_path++;
				path_assign(f, f->paths[f->current_path]);
			// 	print_path(f->paths[f->current_path], f->max_order);
			// 	ft_printf("curr_path is %d\n", f->current_path);
			// 	// print_path(f->paths[f->current_path], f->max_order);
			}

		// print_path(f->paths[f->current_path], f->max_order);
			// print_all_paths(f->paths, f->max_paths, f->max_order);
			ft_printf("curr_path is %d\n", f->current_path);
			// delete_trace(f, f->paths[f->current_path]);



		}
		else if (b == 0)
		{
			ft_printf("BUT b is %d\n", b);
			// ft_printf("curr_path: %d\n", f->current_path);
			copy_paths(f->paths[1], f->paths[0], f->max_order);
			copy_paths(f->paths[0], f->shortest_path, f->max_order);
			delete_trace(f, f->paths[0]);
			delete_trace(f, f->paths[1]);
			f->current_path = 1; //the next one is the 2nd
			while (f->current_path < f->max_paths)
			{
				bfs(f, f->start_vertex);
				// ft_printf("bfs_order for end_vertex: %d\n", f->bfs_order[f->end_vertex]);
				if (f->bfs_order[f->end_vertex] == -1) //this case means that the graph is disconnected
					break ;
				f->current_path++;
				path_assign(f, f->paths[f->current_path]);
		//		print_path(f->paths[f->current_path], f->max_order);
				delete_trace(f, f->paths[f->current_path]);
			}
		}
		// print_graph(f->g, f->max_order);
	}
}

int main(int argc, char **argv)
{
	t_map farm;
	int res;
	int order; //counts number of vertice
	int k, j, n;
	char *line;

	if (argc != 1)
		return (0);
	farm_init(&farm);
	// farm_delete(&farm);
	if (read_map(&farm) == false)
	{
		ft_printf("in reading\n");
		ft_printf("ERROR in map");
		exit(0);
	}
	// print_hash(farm.first_raw,farm.hash_size);
	// ft_printf("max_order = %d\n", farm.max_order);
	graph_fill_in(&farm);

	// print_graph(farm.g, farm.max_order);
	work_with_bfs(&farm);
	// print_path(farm.shortest_path, farm.max_order);
	// exit(1);
	work_with_bfs(&farm);
	// print_graph(farm.g, farm.max_order);
	print_all_paths(farm.paths, farm.max_paths, farm.max_order);


	// dfs(&farm);

	return (0);
}