#pragma once
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <memory.h>

//TODO: Make a function that adds without triggering a reallocation at the mid point
typedef struct Vector_t Vector_t;

//Constantes
#define GROWTH_RATE 2
#define VECTOR_DEFAULT_SIZE 4

typedef void (*vector_insert)(Vector_t *, void *);
typedef void (*data_free)(Vector_t *);

struct Vector_t
{
	uint8_t *dados;
	vector_insert func_inserir;
	data_free func_free;
	size_t tamanho_elemento;
	size_t tamanho;
	size_t capacidade;
};


Vector_t *vector_init(size_t tam_dado, vector_insert func_inserir, data_free func_free);
void vector_inserir(Vector_t *vector, void *dado);
//TODO: this function
void vector_fill(Vector_t *vector, void *dado);
void *vector_indice(Vector_t *vector, size_t indice);
void vector_free(Vector_t *vector); 
