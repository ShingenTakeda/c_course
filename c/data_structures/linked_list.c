#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
	int val;
	struct Nodo *prox;
};

typedef struct Nodo Nodo_t;

typedef struct
{
	Nodo_t *cabeca;
	Nodo_t *cauda;
	long int tamanho;
}Lista_Encadeada_t;

Lista_Encadeada_t *le_init()
{
	Lista_Encadeada_t *ptr = (Lista_Encadeada_t *)malloc(sizeof(Lista_Encadeada_t));

	if(ptr != NULL)
	{
		ptr->cabeca = NULL;
		ptr->cauda = NULL;
		ptr->tamanho = -1;
	}

	return ptr;
}

Nodo_t *le_inserir(Lista_Encadeada_t *lista, int val)
{
	Nodo_t *n_ptr = (Nodo_t*)malloc(sizeof(Nodo_t));
	n_ptr->val = val;
	n_ptr->prox = NULL;

	if(lista->tamanho < 0 && n_ptr != NULL)
	{
		lista->cabeca = n_ptr;
		lista->cauda = n_ptr;
		lista->tamanho++;
	}

	if(lista->tamanho >= 0 && n_ptr != NULL)
	{
		lista->cauda->prox = n_ptr;
		lista->cauda = n_ptr;
		lista->tamanho++;
	}

	return n_ptr;
}

Nodo_t *le_inserir_em_indice(Lista_Encadeada_t *lista, int indice, int val)
{
	if(indice >= lista->tamanho)
	{
		return NULL;
	}

	if(indice == lista->tamanho)
	{
		return	le_inserir(lista, val);
	}

	Nodo_t *n_ptr = (Nodo_t *)malloc(sizeof(Nodo_t));

	if(n_ptr != NULL)
	{
		n_ptr->val = val;
		Nodo_t *temp_ptr = lista->cabeca;
		for(int i = -1; i < indice; i++)
		{
			temp_ptr = temp_ptr->prox;
		}

		n_ptr->prox = temp_ptr->prox;
		temp_ptr->prox = n_ptr;
	}

	return n_ptr;
}

int le_get(Lista_Encadeada_t *lista, unsigned int indice)
{
	if(indice >= lista->tamanho)
	{
		return 0;
	}

	Nodo_t *temp_ptr = lista->cabeca;
	for(int i = 0; i < indice; i++)
	{
		temp_ptr = temp_ptr->prox;
	}
	return temp_ptr->val;
}

void le_print(Lista_Encadeada_t *lista)
{
	Nodo_t *temp_ptr = lista->cabeca;
	for(int i = 0; i < lista->tamanho; i++)
	{
		printf("lista[%i] = %i\n", i, temp_ptr->val);
		if(temp_ptr->prox == NULL)
		{
			return;
		}
		temp_ptr = temp_ptr->prox;
	}
}

Nodo_t *le_nodo_get(Lista_Encadeada_t *lista, unsigned long int indice)
{
	if(indice >= lista->tamanho)
	{
		return NULL;
	}

	Nodo_t *temp_ptr = lista->cabeca;
	for(int i = 0; i < indice; i++)
	{
		temp_ptr = temp_ptr->prox;
	}
	return temp_ptr;
}

void le_remover_elemento(Lista_Encadeada_t *lista, unsigned long int indice)
{
	if(indice >= lista->tamanho)
	{
		return;
	}

	Nodo_t *temp_ptr_1 = lista->cabeca;
	Nodo_t *temp_ptr_2 = NULL;

	if(indice == 0)
	{
		lista->cabeca = lista->cabeca->prox;
		free(temp_ptr_1);
		lista->tamanho--;
		return;
	}

	if(indice == lista->tamanho - 1)
	{
		temp_ptr_1 = lista->cauda;
		lista->cauda = le_nodo_get(lista, indice - 1);
		free(temp_ptr_1);
		lista->tamanho--;
		return;
	}

	temp_ptr_1 = le_nodo_get(lista, indice);
	temp_ptr_2 = le_nodo_get(lista, indice - 1);

	temp_ptr_2->prox = temp_ptr_1->prox;
	free(temp_ptr_1);
	lista->tamanho--;
}

int main()
{
	Lista_Encadeada_t *lista = le_init();
	
	for(int i = 1; i <= 1000; i++)
	{
		le_inserir(lista, i);
	}

	le_print(lista);
	printf("{tamanho: %li, cabeca->val: %i, cauda->val: %i}\n", lista->tamanho, lista->cabeca->val, lista->cauda->val);
	
	le_remover_elemento(lista, 0);
	le_print(lista);
	printf("{tamanho: %li, cabeca->val: %i, cauda->val: %i}\n", lista->tamanho, lista->cabeca->val, lista->cauda->val);

	le_remover_elemento(lista, lista->tamanho - 1);
	le_print(lista);
	printf("{tamanho: %li, cabeca->val: %i, cauda->val: %i}\n", lista->tamanho, lista->cabeca->val, lista->cauda->val);

	le_remover_elemento(lista, 1);
	printf("lista[1] = %i\n", le_get(lista, 1));

	return 0;
}
