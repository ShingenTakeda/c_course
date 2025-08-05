#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>

//Constantes
#define GROWTH_RATE 1.5
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
		vector->dados = realloc(vector->dados, vector->tamanho_elemento * (vector->tamanho * GROWTH_RATE));
		vector->capacidade = vector->tamanho_elemento * (vector->tamanho * GROWTH_RATE);
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

typedef struct
{
	unsigned char a;
	long int _1;
	int b;
	unsigned char c;
	long int d;
	int f;
}padding_ruim;


int main()
{
	Vector_t *vec_int = vector_init(sizeof(int));
	int i = 30;
	
	for(int i = 1; i < 50001; i++)
	{
		vector_inserir(vec_int, &i);
	}

	for(int i = 0; i < 50000; i++)
	{
		printf("int_vec[i] = %i\n", *(int*)vector_indice(vec_int, i));
	}

	printf("vec_int->tamanho: %lu\n", vec_int->tamanho);
	printf("vec_int->capacidade: %lu bytes\n", vec_int->capacidade);
	printf("vec_int->tamanho_elemento: %lu bytes\n", vec_int->tamanho_elemento);
	printf("capacidade de vec_int por razao de ints: %lu\n", vec_int->capacidade / vec_int->tamanho_elemento);

	padding_ruim p_a = {.a = 0x0, .b = 0, .c = 0x0};

	Vector_t *vec_bp = vector_init(sizeof(padding_ruim));

	for(int i = 0; i < 256; i++)
	{
		vector_inserir(vec_bp, &p_a);
		p_a.a++;
		p_a.b++;
		p_a.c++;
	}
	
	padding_ruim *temp_ptr = NULL;

	for(int i = 0; i < 256; i++)
	{
		temp_ptr = (padding_ruim*)vector_indice(vec_bp, i);
		printf("{a = %#2X, b = %i, int c = %#2X}\n", temp_ptr->a, temp_ptr->b, temp_ptr->c);
	}

	printf("vec_pb->tamanho: %lu\n", vec_bp->tamanho);
	printf("vec_pb->capacidade: %lu bytes\n", vec_bp->capacidade);
	printf("vec_pb->tamanho_elemento: %lu bytes\n", vec_bp->tamanho_elemento);
	printf("capacidade de vec_pb por razao de paddings_ruins: %lu\n", vec_bp->capacidade / vec_bp->tamanho_elemento);


	return 0;
}
