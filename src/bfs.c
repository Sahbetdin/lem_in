
#include "../lem_in.h"

//delete edge (u, v)
//and (v, u), respectively from graph
void	delete_edge(t_map *f, int u, int v)
{

}


void	bfs(t_map *f, int start)
{
	t_queue q;
	t_linked *tmp;
	int *curr_addr; //for walking through queue
	int i;
	t_bool flag_dead;

	queue_init(&q, f->max_order);
	queue_insert(&q, start);
	curr_addr = q.front;
	f->bfs_order[start] = 0;
	while (curr_addr <= q.rear)
	{	
		tmp = f->g[*curr_addr];
		while (tmp != NULL)
		{
			if (f->bfs_order[tmp->data] == -1)
			{
				queue_insert(&q, tmp->data);
				f->bfs_order[tmp->data] = f->bfs_order[*curr_addr] + 1;
			}
			tmp = tmp->next;
		}
		curr_addr++;
	}
	queue_print(&q);
	
	i = 0;
	while (i < f->max_order)
	{
		ft_printf("i = %d, bfs_order = %d\n", i, f->bfs_order[i]);
		i++;
	}
	print_linked_visited(f->g[f->end_vertex], f->bfs_order);
	int *shortest_path;
	int x; //currnet bfs_oreder
	int node; //current node number

	shortest_path = (int *)malloc(sizeof(int) * f->max_order);
	i = 0;
	while (i < f->max_order)
		shortest_path[i++] = -1;
	node = f->end_vertex;
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
		shortest_path[i] = tmp->data;
		i++;
		node = tmp->data;
	}
	i = 0;
	while (i < f->max_order)
		ft_printf("%d ", shortest_path[i++]);


	queue_delete(&q);
	//delete queue elements!!!!
}
