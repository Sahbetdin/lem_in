
#include "../lem_in.h"


/*
** sets number of in 'arrows' for each vertex, i.e.
** number of neighbours whos bfs_order is greater than the current one
*/

void	set_ins(t_map *f)
{
	int i;
	t_linked *tmp;

	i = 0;
	while (i < f->max_order)
	{
		if (f->g[i]->status == begin)
		{
			i++;
			continue;
		}
		tmp = f->g[i];
		while (tmp)
		{
			if (f->bfs_order[tmp->data] < f->bfs_order[i])
				f->g[i]->in++;
			tmp = tmp->next;
		}
		i++;
	}
}

/*
** sets number of out 'arrows' for each vertex, i.e.
** number of neighbours whos bfs_order is less than the current one
*/

void	set_outs(t_map *f)
{
	int i;
	t_linked *tmp;

	i = 0;
	while (i < f->max_order)
	{
		if (f->g[i]->status == end)
		{
			i++;
			continue;
		}
		tmp = f->g[i];
		while (tmp)
		{
			if (f->bfs_order[tmp->data] > f->bfs_order[i])
				f->g[i]->out++;
			tmp = tmp->next;
		}
		i++;
	}
}

/*
** sets number of neutrals for each vertex
** i.e. number of neighbours which have the same bfs_order as
** the given one
*/

void	set_neutrals(t_map *f)
{
	int i;
	t_linked *tmp;

	i = 0;
	while (i < f->max_order)
	{
		if (f->g[i]->status == begin)
		{
			i++;
			continue;
		}
		tmp = f->g[i];
		while (tmp)
		{
			// ft_printf("bfs_order[%d] = %d, neighb = %d, bfs_neigb = %d", i, f->bfs_order[i], tmp->data, f->bfs_order[tmp->data]);
			if (f->bfs_order[i] == f->bfs_order[tmp->data])
			{
				f->g[i]->neutral++;
				// ft_printf(" YES\n");
			}
			//  else
			// 	ft_printf("\n");

		// ft_printf("i =  %d,curr = %d, neighb = %d \n ", i, f->bfs_order[i], f->bfs_order[tmp->data]);

			// if (f->bfs_order[tmp->data] == f->bfs_order[i])
			// 	f->g[i]->neutral++;
			tmp = tmp->next;
		}
		// ft_printf("      i = %d, neighb = %d \n", i, f->g[i]->neutral);

		i++;
	}


	i = 0;
	while (i < f->max_order)
	{
		ft_printf("      i = %d, neighb = %d \n", i, f->g[i]->neutral);
		i++;
	}
}



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

	set_outs(f);
	set_ins(f);
	set_neutrals(f);
	i = 0;
	while (i < f->max_order)
	{
		ft_printf("i =  %d, status = %d, bfs_order = %d, ", i, f->g[i]->status, f->bfs_order[i]);
		ft_printf("in = %d, out = %d, neutral = %d\n", i, f->g[i]->in, f->g[i]->out, f->g[i]->neutral);
		i++;
	}





	// ft_printf("OUTS: \n");
	// i = 0;
	// while (i < f->max_order)
	// {
	// 	ft_printf("i =  %d, out = %d\n", i, f->g[i]->out);
	// 	i++;
	// }

	queue_delete(&q);
	//delete queue elements!!!!
}
