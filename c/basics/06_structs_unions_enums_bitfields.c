
#include <stdio.h>
#include <string.h>
typedef struct
{
	int a;
	int b;
}simple_struct;

union
{
	float f;
	unsigned int i;
}simple_union;

typedef struct
{
	unsigned int significante: 23;
	unsigned int expoente: 8;
	unsigned int sinal: 1;
}bitfield_float;

typedef struct
{
	int a;
	char b;
	int c;
}exemplo_de_tamanho_de_struct;

int main()
{
	//Inicializando para zero
	simple_struct s_s = {0};
	printf("Tamanho do struct: %lu | membros do struct: {a: %i, b: %i}\n", sizeof(s_s), s_s.a, s_s.b);

	//Modificando os valores do struct
	s_s.a = 23;
	printf("Tamanho do struct: %lu | membros do struct: {a: %i, b: %i}\n", sizeof(s_s), s_s.a, s_s.b);

	//Em unions, os valores contidos nela ocupam o mesmo espaço de memoria
	simple_union.i = 4294967295;
	printf("Valor da float da union: %f\n", simple_union.f);
	printf("Valor da int da union: %iu\n", simple_union.i);
	//struct podem ser declarados em quase qualquer lugar
	struct exemplo
	{
		char code;
		char protocolo[100];
	}ex, *ex_ptr;//declaração de variaveis de sruct sem typedef

	ex.code = 0xff;
	strcpy(ex.protocolo, "UART");
	
	//Ponteiro de struct
	ex_ptr = &ex;

	printf("Codigo em hex: %X | Protocolo %s\n", ex_ptr->code, ex_ptr->protocolo);

	//Struct podem ser contruidos errados, a ordem dos elementos importa
	exemplo_de_tamanho_de_struct err = {0};
	printf("Tamanho do struct: %lu\n", sizeof(err));
	//Pela a soma dos elementos 1 byte(char) + 8 bytes(duas ints) era para dar 9 bytes, mas como ele esta estruturado
	//a char esta ocupando o espaço de uma int

	return 0;
}
