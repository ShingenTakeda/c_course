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
