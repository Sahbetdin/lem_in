
#include "my_libft/libft.h"

/*
int main()
{
	int fd;
	int res;
	char *line;

	fd = open("v.txt", O_RDONLY);
	while ((res = get_next_line(fd, &line)))
	{
		ft_printf("yes\n");
		free(line);
	}
	ft_printf("res = %d\n", res);


	close (fd);
	return (0);
}
*/

/*
//check ft_atoi_pointer what it points to
int main()
{
	char *str;
	int n;
	char *new;

	str = ft_strdup("54545");
	new = ft_atoi_pointer(str, &n);
	if (*new == '\0')
		ft_printf("HHH\n");
	else
		ft_printf("EEE\n");

		// ft_printf("~%s~\n", new);
	return (0);
}
*/

//check deleting linked list
#include "lem_in.h"
void	delete_simple_linked_list(t_linked **head)
{
	t_linked *prev;
	t_linked *curr;

	prev = *head;
	while (prev)
	{
		curr = prev->next;
		free(prev);
		prev = curr;
	} 
	*head = NULL;
}

//adds to front
void	add_to_linked_list(t_linked **head, int value)
{
	t_linked *lst;
	lst = (t_linked *)malloc(sizeof(t_linked));
	
	lst->next = NULL;
	lst->data = value;
	if (*head == NULL)
		*head = lst;
	else
	{
		lst->next = *head;
		*head = lst;
	}
}



int	main()
{
	t_linked *tmp;

	tmp = NULL;
	add_to_linked_list(&tmp, 10);
	add_to_linked_list(&tmp, 20);
	add_to_linked_list(&tmp, 30);
	print_linked_list(&tmp);
	delete_simple_linked_list(&tmp);
	print_linked_list(&tmp);


	return(0);
}