#include "../lem_in.h"


//4th may
/*
visited[i] will show the step at which i-th was visited
q is a queue for holding vertices which were visited
tmp is current list element address to skip the neighbours of a given vertice
curr_addr is address of current place in array. During the work BSF looks
neighbours of curr_addr in graph
*/
void	bfs(t_map *f, int start)
{
	t_queue q;
	t_linked *tmp;
	int *curr_addr; //for walking through queue
	int i;

	f->bfs_order = visited_init(f->bfs_order, f->max_order);
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
	queue_delete(&q);
	//delete queue elements!!!!
}
