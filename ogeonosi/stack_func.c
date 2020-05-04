#include "lem_in.h"

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
