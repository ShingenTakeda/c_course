#include "vector.h"
#include <string.h>

Vector_t *vector_init(size_t tam_dado, vector_insert func_inserir, data_free func_free)
{
  	Vector_t *vec = (Vector_t *)malloc(sizeof(Vector_t));

  	if (vec != NULL) 
	{
    		vec->tamanho_elemento = tam_dado;
    		vec->dados = malloc(sizeof(Vector_t) * VECTOR_DEFAULT_SIZE);
    		vec->tamanho = 0;
    		vec->capacidade = tam_dado * VECTOR_DEFAULT_SIZE;

		if(func_inserir != NULL)
		{
			vec->func_inserir = func_inserir;
		}
		else 
		{
			vec->func_inserir = NULL;
		}

		if(func_free != NULL)
		{
			vec->func_free = func_free;
		}
		else 
		{
			vec->func_free = NULL;
		}
  	}

  	return vec;
}

void vector_inserir(Vector_t *vector, void *dado) 
{
	if (vector->tamanho++ >= (vector->capacidade / vector->tamanho_elemento) / 2)
	{
		vector->dados = realloc(vector->dados, vector->tamanho_elemento * (vector->tamanho * GROWTH_RATE));
   		vector->capacidade =vector->tamanho_elemento * (vector->tamanho * GROWTH_RATE);
  	}

	memcpy(&vector->dados[vector->tamanho_elemento * vector->tamanho], dado, vector->tamanho_elemento);

	if(vector->func_inserir != NULL)
	{
		vector->func_inserir(vector, dado);
	}
}

void *vector_indice(Vector_t *vector, size_t indice)
{
	if (indice < vector->tamanho) 
	{
    		return (void *)&vector->dados[(vector->tamanho_elemento * indice)];
	}

  return NULL;
}

void vector_free(Vector_t *vector) 
{
	if(vector->func_free != NULL)
	{
		vector->func_free(vector);
	}
  	free(vector->dados);
  	free(vector);
}
