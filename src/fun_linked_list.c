#include "../lem_in.h"

void	del_linked_list(t_linked **head)
{
	t_linked *curr;
	t_linked *n;

	curr = *head;
	while (curr)
	{
		n = curr->next;
		curr->next = NULL;
		free(curr);
		curr = n;
	}
	*head = NULL;
}
