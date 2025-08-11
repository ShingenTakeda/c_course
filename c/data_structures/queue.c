#include <stdio.h>
#include <stdbool.h>

typedef struct
{
	int traz;
	int frente;
	int tamanho;
	int arr[10];
}Queue_t;

Queue_t queue_init()
{
	Queue_t q;

	q.traz = 0;
	q.frente = -1;
	q.tamanho = -1;

	return q;
}

bool queue_cheio(Queue_t *queue)
{
	return (queue->traz + 1) % 10 == queue->frente;
}

bool queue_vazio(Queue_t *queue)
{
	return queue->frente == -1;
}

int queue_retirar(Queue_t *queue)
{
	if(queue_vazio(queue))
	{
		return -1;
	}

	int val = queue->arr[queue->frente];

	if(queue->frente == queue->traz)
	{
		queue->frente = queue->traz - 1;
	}
	else
	{
		queue->frente = (queue->frente + 1) % 10;
	}

	return val;
}

void queue_print(Queue_t *queue)
{
	if(queue_vazio(queue))
	{
		return;
	}

	int i = queue->frente;
	while(i != queue->traz)
	{
		printf("%i\n", queue->arr[i]);
		i = (i + 1) % 10;
	}
	printf("%i\n", queue->arr[queue->traz]);
}

void queue_inserir(Queue_t *queue,int valor)
{
	if(queue_cheio(queue))
	{
		return;
	}

	if(queue->frente == -1)
	{
		queue->frente = 0;
	}

	queue->traz = (queue->traz + 1) % 10;
	queue->arr[queue->traz] = valor;
}

int main()
{
	return 0;
}
