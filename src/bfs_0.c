
#include "../lem_in.h"
t_linked	*del_list_element(t_linked *lst);


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
		if (f->status[i] == begin)
		{
			i++;
			continue;
		}
		tmp = f->g[i];
		while (tmp)
		{
			if (f->bfs_order[tmp->data] < f->bfs_order[i])
				f->in[i]++;
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
		if (f->status[i] == end)
		{
			i++;
			continue;
		}
		tmp = f->g[i];
		while (tmp)
		{
			if (f->bfs_order[tmp->data] > f->bfs_order[i])
				f->out[i]++;
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
		if (f->status[i] == begin)
		{
			i++;
			continue;
		}
		tmp = f->g[i];
		while (tmp)
		{
			if (f->bfs_order[i] == f->bfs_order[tmp->data])
				f->neutral[i]++;
			tmp = tmp->next;
		}
		i++;
	}
}

// void	nullify_in_out_neutrals(t_map f)
// {
// 	int i;

// 	i = 0;
// 	while (i < f->max_order)
// 	{
// 		f->in[i] = 0;
// 		f->out[i] = 0;
// 		f->neutral[i] = 0;
// 		i++;
// 	}
// }

t_linked	*find_node(t_linked *lst, int value)
{
	while (lst)
	{
		if (lst->data == value)
			break;
		lst = lst->next;
	}
	return (lst);
}

/*
** we have the node which is to be deleted.
** we look all its neighbours (n1)
** we go to each n1 and find there the deleted node
** in each n1 we delete that node 
*/
void	del_dead_end_from_other_vertice(t_map *f, int del_node_order)
{
	t_linked *tmp;
	t_linked *lst;
	t_linked *prev;
	
	tmp = f->g[del_node_order]; //pointer to deleted node
	while (tmp)
	{
		lst = f->g[tmp->data]; //we go to each neighbour of deleted node
		if (lst->data == del_node_order)
		{ // if the very first one is our node then delete it
			ft_printf("%d: DURING DEL-FIRST: out = %d \n",lst->data, f->out[tmp->data]);
			f->g[tmp->data] = lst->next;
			lst = del_list_element(lst);
		}
		else
		{ //else search for our node and then delete it 
			lst = find_node(lst, del_node_order);
			ft_printf("%d: DURING DEL-NOT FIRST: out = %d \n",lst->data, f->out[lst->data]);
			prev = lst;
			prev->next = lst->next;
			lst = del_list_element(lst);
		}
		tmp = tmp->next;
	}
}

t_bool		delete_dead_ends(t_map *f)
{
	int i;
	t_bool flag;

	i = 0;
	flag = false;
	while (i < f->max_order)
	{
		if (f->in[i] > 0 && f->out[i] == 0)
		{
			ft_printf("i = %d\n", i);
			flag = true;
			del_dead_end_from_other_vertice(f, i); //delete dead ends from other vertice
			del_linked_list(f->g + i); //delete neighbours of dead ends

			f->in[i] = 0;
			f->out[i] = 0;
			f->neutral[i] = 0;
		}


		// if (f->in[i] > 0 && f->out[i] == 0 && 
		// ((f->bfs_order[i] > f->bfs_order[f->end_vertex])  ||
		// (f->bfs_order[i] <= f->bfs_order[f->end_vertex] && f->neutral[i] == 0)))
		// {
		// 	flag = true;
		// 	del_dead_end_from_other_vertice(f->g, i); //delete dead ends from other vertice
		// 	del_linked_list(f->g + i); //delete neighbours of dead ends
		// 	f->in[i] = 0;
		// 	f->out[i] = 0;
		// 	f->neutral[i] = 0;
		// }
		i++;
	}
	return (flag);
}


/*
visited[i] will show the step at which i-th was visited
q is a queue for holding vertices which were visited
tmp is current list element address to skip the neighbours of a given vertice
curr_addr is address of current place in array. During the work BSF looks
neighbours of curr_addr in graph
*/

void	bfs1(t_map *f, int start)
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



	set_outs(f);
	set_ins(f);
	set_neutrals(f);
	print_in_out_neutral(f);

	flag_dead = true;
	// flag_dead = delete_dead_ends(f);
	// ft_printf("~~~~~~~~~\n");
	// print_in_out_neutral(f);
	// while (flag_dead)
	// {
	// 	ft_printf("HERE");
		flag_dead = delete_dead_ends(f);
	// }
	print_in_out_neutral(f);
	
	
	queue_delete(&q);
	//delete queue elements!!!!
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


	queue_delete(&q);
	//delete queue elements!!!!
}
