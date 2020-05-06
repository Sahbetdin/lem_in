#include "../lem_in.h"


//initialize farm variables 
void	farm_init(t_map *f)
{
	f->ants = 0;
	f->hash_size = 10;
	f->flag_ants = false;
	f->flag_start = false;
	f->flag_end = false;
	f->flag_rooms = false;
	f->flag_links = false;
	f->max_order = 0;
	f->fd = 0;
	f->first_raw = hashmap_init(f->first_raw, f->hash_size);
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

/*
** this function accepts two vertice
** it assigns u2 as neighbour to u1->neighbour linked list
** it assigns u2's order.
*/

t_bool link_neighbour(t_vertex *dest, t_vertex *src)
{
	t_linked *list_elem;

	if ((list_elem = (t_linked *)malloc(sizeof(t_linked))) == NULL)
		return (false);

	list_elem->next = NULL;
	list_elem->data = src->order;

	if (dest->neighbour == NULL)
		dest->neighbour = list_elem;
	else
	{
		list_elem->next = dest->neighbour;
		dest->neighbour = list_elem;
	}
	return (true);
}


//in the link v1-v2
//assigns v2 as neighbor of v1 and vice verses
//if error, returns false
t_bool	parse_links(t_map *f, char *line, char *dash)
{
	int n;
	int i;
	t_hash *tmp_h;
	t_vertex *v1;
	t_vertex *v2;

	if (f->flag_rooms == false) //first, we set that the rooms are finished
		f->flag_rooms = true;
	if ((v1 = find_vertex(f, line, dash - line)) == NULL)
		return (false);
	// ft_printf("v1->name = %s", v1->name);
	// зеркальность
	// name1-name1
	if ((v2 = find_vertex(f, dash + 1, ft_strlen(dash + 1))) == NULL)
		return (false);
	link_neighbour(v1, v2);
	link_neighbour(v2, v1);
	if (f->flag_links == false)
		f->flag_links = true;
	return (true);
}


t_bool	graph_fill_in(t_map *f)
{
	int i;
	t_hash *tmp_h;
	t_vertex *tmp_v;
	t_linked *tmp_lst;

	if (!(f->g = (t_linked **)malloc(sizeof(t_linked *) * f->max_order)))
		return (false);
	i = -1;
	while (++i < f->hash_size)
	{
		tmp_h = f->first_raw[i];
		while (tmp_h)
		{
			tmp_v = tmp_h->v;
			tmp_lst = tmp_v->neighbour;
			f->g[tmp_v->order] = tmp_v->neighbour;
			tmp_h = tmp_h->next;
		}
	}
	return (true);
}

void	print_graph(t_linked **g, int n)
{
	int i;
	t_linked *tmp_lst;

	ft_printf("\nPRINT GRAPH:\n");
	i = 0;
	while (i < n)
	{
		tmp_lst = g[i];
		ft_printf("G[%d]: ", i);
		while (tmp_lst)
		{
			ft_printf("%d -> ", tmp_lst->data);
			tmp_lst = tmp_lst->next;
		}
		ft_printf("nil\n");
		i++;
	}
}

//returns true, if stack was initialized
//otherwise (memory allocation problem) returns false
t_stack	*initiate_stack(int n)
{
	t_stack *tmp_stack;

	if ((tmp_stack = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	if ((tmp_stack->arr = (int *)malloc(sizeof(int) * n)) == NULL)
	{
		free(tmp_stack);
		return (NULL);
	}
	tmp_stack->len = n;
	tmp_stack->ptr = n;
	return (tmp_stack);
}

void	delete_stack(t_stack *stack)
{
	free(stack->arr);
	free(stack);
}

t_bool	is_empty_stack(t_stack *stack)
{
	if (stack->ptr == stack->len)
		return (true);
	return (false);	
}

t_bool	is_full_stack(t_stack *stack)
{
	if (stack->ptr == 0)
		return (true);
	return (false);	
}

t_bool	append_to_stack(t_stack *stack, int value)
{
	if (is_full_stack(stack) == false)
	{
		stack->ptr--;
		stack->arr[stack->ptr] = value;
		return (true);
	}
	return (false);
}

int		pop_from_stack(t_stack *stack)
{
	int tmp;

	if (is_empty_stack(stack) == false)
	{
		tmp = stack->arr[stack->len];
		stack->ptr++;
		return (tmp);
	}
	return (-1);
}

int	top_in_stack(t_stack *stack)
{
	if (is_empty_stack(stack))
		return (-1);
	return (stack->arr[stack->ptr]);
}

void	print_stack(t_stack *stack)
{
	int i;

	i = stack->ptr;
	ft_printf("stack: ");
	while (i < stack->len)
	{
		ft_printf("%d, ", stack->arr[i]);
		++i;
	}
}

void	print_linked_visited(t_linked *lst, t_bool *vis)
{
	while (lst)
	{
		ft_printf("(%d, %d)->", lst->data, vis[lst->data]);
		lst = lst->next;
	}
	ft_printf("nil\n");
}


//we use dfs for checking if start and end are in the same
//connectivity component
//we need stack and its methods
//return false if  dfs didn't work
void	dfs(t_map *f)
{
	t_stack		*stack;
	int			*parent;
	t_bool		*is_visited;
	t_linked	*lst;
	int			i;
	int			curr;
	t_bool		flag_f_vert;


	stack = initiate_stack(f->max_order);
	// curr = top_in_stack(stack);
	// return ;
	parent = (int *)malloc(sizeof(int) * f->max_order);
	is_visited = (t_bool *)malloc(sizeof(t_bool) * f->max_order);
	i = -1;
	while (++i < f->max_order)
		is_visited[i] = 0;

	print_graph(f->g, f->max_order);
	append_to_stack(stack, f->start_vertex);
	while (!is_empty_stack(stack))
	{
		curr = top_in_stack(stack);
		ft_printf(" %d \n", curr);
		is_visited[curr] = 1;
		lst = f->g[curr];
		while (!is_empty_stack(stack) && is_visited[lst->data])
		{
			lst = lst->next;
			if (lst == NULL)
			{
				// ft_printf("here\n");
				pop_from_stack(stack);
				lst = f->g[top_in_stack(stack)];
			}
		}
		// ft_printf("       here\n");

		if (!is_empty_stack(stack) && is_visited[lst->data] == false)
			append_to_stack(stack, lst->data);
	}


	free(parent);
	free(is_visited);
}


void	dfs1(t_map *f)
{
	
	t_stack	*stack;
	int		*parent;
	t_bool	*is_visited;
	t_linked *lst;
	int	curr; //current vertex order
	int i;
	t_bool flag_found_unvisited;
	
	stack =	initiate_stack(f->max_order); //PAY ATT: if bad return false!!!
	parent = (int *)malloc(sizeof(int) * f->max_order);
	is_visited = (t_bool *)malloc(sizeof(t_bool) * f->max_order);
	i = -1;
	while (++i < f->max_order)
		is_visited[i] = 0;	

	
	// ft_printf("in dfs\n");
	// ft_printf("is_full: %d\n", is_full_stack(stack) == false);
	// ft_printf("ending   at: %d\n", f->end_vertex);

	curr = f->start_vertex;
	// is_visited[curr] = 1;
	append_to_stack(stack, curr);
	
	// ft_printf("stack->len = %d\n", stack->len);

	// append_to_stack(stack, 100);
	// print_stack(stack);
//list all neighbours of vertex
//find the first one which was not visited
//go to one of them, thus add it to stack
//repeat it
//if can't find any neighbour which was not visited pop that vertex from stack

//Kcw1; st: 0; ord: 11->91->108->140->nil
	// lst = f->g[f->start_vertex];
	// while (lst)
	// {
	// 	ft_printf("%d->", lst->data);
	// 	lst = lst->next;
	// }


	print_graph(f->g, f->max_order);
	// return ;

	// print_linked_visited(f->g[11], is_visited);
	// return ;

	while (!is_empty_stack(stack))
	{

		ft_printf("%d ", curr);
		is_visited[curr] = 1;
		// print_linked_visited(f->g[curr], is_visited);

		//////////////
		lst = f->g[curr];
		flag_found_unvisited = false;
		while (!flag_found_unvisited)
		{
			if (!is_visited[lst->data])
			{
				curr = lst->data;
				flag_found_unvisited = true;
			}
			else 
			{
				lst = lst->next;
				if (lst == NULL)
				{
					curr = pop_from_stack(stack);
					lst = f->g[curr];
				}
			}
		}
		//////////////


		// while (lst) //search for unvisited vertex
		// {
		// 	if (is_visited[lst->data])
		// 		lst = lst->next;
		// 		if (lst == NULL)
		// 		{
		// 			curr = pop_from_stack(stack);
		// 			lst = f->g[curr];
		// 		}
		// 	else
		// 	{
		// 		curr = lst->data;
		// 		// flag_found_unvisited = true;
		// 		append_to_stack(stack, curr); //if found put it to stack and explore further
		// 		break;
		// 	}
		// }

		// if (lst == NULL)
		// getchar();	
	}
	
	free(parent);
	free(is_visited);
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
	if (read_map(&farm) == false)
	{
		ft_printf("ERROR in map");
		exit(0);
	}
	// ft_printf("max_order = %d\n", farm.max_order);
	graph_fill_in(&farm);
	// dfs(&farm);
	print_graph(farm.g, farm.max_order);

	return (0);
}