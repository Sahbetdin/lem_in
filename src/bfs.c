
#include "../lem_in.h"


//delete edge: from g[haystack] extract and return needle(t_linked element) of haystack
// E.g. g[haystack] : .., .., needle, .. ..
//we are sure that g[haystack] != NULL and it has at least one element.
t_linked	*delete_arc(t_map *f, int haystack, int needle)
{
	t_linked *curr;
	t_linked *prev;

	curr = f->g[haystack];
	if (curr->data == needle)
	{
		f->g[haystack] = curr->next;
		curr->next = NULL;
		return (curr);
	}
	while (curr)
	{
		if (curr->data == needle)
			break ;
		prev = curr;
		curr = curr->next;
	}
	if (curr == NULL) //if didn't find anything
		return (NULL);
	prev->next = curr->next;
	curr->next = NULL;
	return (curr);
}


void	bfs(t_map *f, int start)
{
	t_queue q;
	t_linked *tmp;
	int *curr_addr; //for walking through queue
	t_bool flag_dead;

	queue_init(&q, f->max_order);
	queue_insert(&q, start);
	curr_addr = q.front;

	arr_clear_with_value(f->bfs_order, f->max_order, -1);//clear bfs_order
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

	// queue_print(&q);
	queue_delete(&q);
	//delete queue elements!!!!
}
