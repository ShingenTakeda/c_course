#include <memory.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Constantes
#define VECTOR_GROWTH_RATE 1.5
#define VECTOR_DEFAULT_SIZE 4

typedef struct
{
	uint8_t *dados;
	size_t tamanho_elemento;
	size_t tamanho;
	size_t capacidade;
}Vector_t;

Vector_t *vector_init(size_t tam_dado)
{
	Vector_t *vec = (Vector_t*)malloc(sizeof(Vector_t));

	if(vec != NULL)
	{
		vec->tamanho_elemento = tam_dado;
		vec->dados = malloc(sizeof(Vector_t) * VECTOR_DEFAULT_SIZE);
		vec->tamanho = 0;
		vec->capacidade = tam_dado * VECTOR_DEFAULT_SIZE;
	}

	return vec;
}

//Inserir generico, não cobre todos os casos
void vector_inserir(Vector_t *vector, void *dado)
{
	if(vector->tamanho >= (vector->capacidade / vector->tamanho_elemento) * .75)
	{
		vector->dados = realloc(vector->dados, vector->tamanho_elemento * (vector->tamanho * VECTOR_GROWTH_RATE));
		vector->capacidade = vector->tamanho_elemento * (vector->tamanho * VECTOR_GROWTH_RATE);
	}
	memcpy(&vector->dados[vector->tamanho_elemento * vector->tamanho], dado, vector->tamanho_elemento);
	vector->tamanho++;
}

void *vector_indice(Vector_t *vector, size_t indice)
{
	if(indice < vector->tamanho)
	{
		return (void*)&vector->dados[(vector->tamanho_elemento * indice)];
	}

	return NULL;
}

//Limpeza generica, não cobre todos os casos
void vector_free(Vector_t *vector)
{
	free(vector->dados);
	free(vector);
}


struct Nodo
{
	uint8_t *val;
	struct Nodo *prox;
};

typedef struct Nodo Nodo_t;

typedef struct
{
	Nodo_t *cabeca;
	Nodo_t *cauda;
	size_t tamanho_do_dado;
	size_t tamanho;
}Lista_Encadeada_t;

Lista_Encadeada_t *le_init(size_t tamanho_do_dado)
{
	Lista_Encadeada_t *ptr = (Lista_Encadeada_t *)malloc(sizeof(Lista_Encadeada_t));

	if(ptr != NULL)
	{
		ptr->cabeca = NULL;
		ptr->cauda = NULL;
		ptr->tamanho = -1;
		ptr->tamanho_do_dado = tamanho_do_dado;
	}

	return ptr;
}

Nodo_t *le_inserir(Lista_Encadeada_t *lista, void* val)
{
	Nodo_t *n_ptr = (Nodo_t*)malloc(sizeof(Nodo_t));
	n_ptr->val = malloc(lista->tamanho_do_dado);
	memcpy(n_ptr->val, val, lista->tamanho_do_dado);
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

Nodo_t *le_inserir_em_indice(Lista_Encadeada_t *lista, int indice, void *val)
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
		
		memcpy(n_ptr->val, val, lista->tamanho_do_dado);
		n_ptr->val = malloc(lista->tamanho_do_dado);
		if(n_ptr->val != NULL)
		{
			Nodo_t *temp_ptr = lista->cabeca;
			for(int i = -1; i < indice; i++)
			{
				temp_ptr = temp_ptr->prox;
			}

			n_ptr->prox = temp_ptr->prox;
			temp_ptr->prox = n_ptr;
		}
	}

	return n_ptr;
}

void *le_get(Lista_Encadeada_t *lista, unsigned int indice)
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
		free(temp_ptr_1->val);
		free(temp_ptr_1);
		lista->tamanho--;
		return;
	}

	if(indice == lista->tamanho - 1)
	{
		temp_ptr_1 = lista->cauda;
		lista->cauda = le_nodo_get(lista, indice - 1);
		free(temp_ptr_1->val);
		free(temp_ptr_1);
		lista->tamanho--;
		return;
	}

	temp_ptr_1 = le_nodo_get(lista, indice);
	temp_ptr_2 = le_nodo_get(lista, indice - 1);

	temp_ptr_2->prox = temp_ptr_1->prox;
	free(temp_ptr_1->val);
	free(temp_ptr_1);
	lista->tamanho--;
}
