
#include "lem_in.h"

int main()
{
	int n = 5;
	int i;
	int *addr;
	t_queue q;


	queue_init(&q, n);
	queue_insert(&q, 10);

	// printf("front:%p\n", q.front);
	// printf(" rear:%p\n", q.rear);

	addr = q.front;

	i = 20;
	while (addr < q.rear)
	{
		queue_insert(&q, i);
		i += 50;
		addr++;
		printf("%d\n", *addr);
	}
	
	// queue_insert(&q, 40);
	// queue_insert(&q, -20);
	// queue_insert(&q, -2890);
	// queue_insert(&q, 390);
	queue_print(&q);

	// queue_print(&q);


	return (0);
}