#include "../lem_in.h"

void	queue_init(t_queue *Q, int size)
{
	int i;

	Q->n = size;
	Q->front = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		Q->front[i] = 0;
		i++;
	}
	Q->rear = Q->front; 
}

int		queue_is_empty(t_queue *Q)
{
	if (Q->front == Q->rear)
		return (1);
	else
		return (0);
}

int		queue_is_full(t_queue *Q)
{
	if (Q->rear - Q->front == Q->n)
		return (1);
	else
		return (0);
}

//if successfully inserted, then return 1
//else return 0
int		queue_insert(t_queue *Q, int x)
{
	if (queue_is_full(Q))
	{
		printf("queue is full\n");
		return (0);
	}
	else
	{
		Q->rear[0] = x;
		Q->rear++;
	}
	return (1);
}

void	queue_print(t_queue *Q)
{
	int i;

	if (queue_is_empty(Q))
	{
		printf("empty\n");
		return ;
	}
	i = 0;
	while (Q->front + i < Q->rear)
	{
		printf("%d ", Q->front[i]);
		i++;
	}
	printf("\n");
}

//if could deleted first, then 
// return that element
//else return -1
int		queue_out_first(t_queue *Q)
{
	int elem;
	int i;
	int maxi;

	if (queue_is_empty(Q) == 0)
	{
		maxi = Q->rear - Q->front;
		elem = Q->front[0];
		i = 0;
		while (i < maxi - 1)
		{
			Q->front[i] = Q->front[i + 1];
			i++;
		}
		Q->rear--;
		return (elem);
	}
	else
		return (-1);
}

//returns first element if the queue is not empty
//else returns -1. 
//Could be resolved?
int		queue_shine_first(t_queue *Q)
{
	if (queue_is_empty(Q) == 0)
	{
		return (Q->front[0]);
	}
	else
		return (-1);
}

void	queue_delete(t_queue *Q)
{
	free(Q->front);
}

/*
if queue is not empty returns pops first element 
and shifts all other elements
else returns -1
*/
int		queue_pop(t_queue *Q)
{
	int tmp;
	int i;

	if (queue_is_empty(Q))
		return (-1);
	tmp = Q->front[0];
	i = 0;
	while (i < Q->n - 1)
	{
		Q->front[i] = Q->front[i + 1];
		i++;
	}
	(Q->rear)--;
	(Q->n)--;
	return (tmp);
}
//////////////////////////////////////
