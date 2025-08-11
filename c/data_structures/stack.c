#include <stdio.h>
#include <stdbool.h>


typedef struct
{
	int indice;
	int arr[10];
}Stack_t;

Stack_t stack_init()
{
	Stack_t s = {.indice = -1};
	return s;
}

bool stack_vazio(Stack_t *stack)
{
	if(stack->indice == -1)
	{
		return true;
	}

	return false;
}

bool stack_cheio(Stack_t *stack)
{
	if(stack->indice == 10)
	{
		return true;
	}
	return false;
}

void stack_inserir(Stack_t *stack, int val)
{
	if(stack_cheio(stack))
	{
		return;
	}

	stack->indice++;
	stack->arr[stack->indice] = val;
	return;
}

int stack_pop(Stack_t *stack)
{
	if(stack_vazio(stack))
	{
		return -1;
	}

	int val = stack->arr[stack->indice];
	stack->indice--;
	return val;
}

int main()
{
	
}
