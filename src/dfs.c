#include "../lem_in.h"

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
		is_visited[i] = false;

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
