#include "../lem_in.h"

void	add_elem(t_linked **head, int value)
{
	t_linked *tmp;

	tmp = (t_linked *)malloc(sizeof(t_linked));
	tmp->next = (*head);
	tmp->data = value;
	*head = tmp;
}

void	print_list(t_linked **head)
{
	t_linked *tmp;

	tmp = *head;
	while (tmp)
	{
		ft_printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("NULL\n");
}

t_linked *del_elem(t_linked **head, int value)
{
	t_linked *curr;
	t_linked *prev;

	if ((*head)->data == value)
	{
		curr = *head;
		*head = (*head)->next;
		curr->next = NULL;
		return (curr);
	}
	curr = *head;
	while (curr)
	{
		if (curr->data == value)
			break ;
		prev = curr;
		curr = curr->next;
	}
	if (curr == NULL)
		return (NULL);
	prev->next = curr->next;
	curr->next = NULL;
	return (curr);
}

void	put_elem_to_list(t_linked **head, t_linked *lst)
{
	lst->next = *head;
	*head = lst;
}

int main()
{
	t_linked *tmp;
	t_linked *lst;

	tmp = NULL;
	add_elem(&tmp, 10);
	add_elem(&tmp, 20);
	add_elem(&tmp, 30);
	add_elem(&tmp, 40);
	print_list(&tmp);
	lst = del_elem(&tmp, 10);
	print_list(&tmp);
	print_list(&lst);
	// put_elem_to_list(&tmp, lst);
	// print_list(&tmp);


	return (0);
}