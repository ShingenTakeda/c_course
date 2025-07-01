#include <stdio.h>

//Ponto de entrada do programa
int main()
{
	/*Tipos aritmeticos basicos*/
	int my_int = 5;			//Numeros inteiros
	float my_float = 3.3;		//Numeros reais
	double my_double = 3.666666	//Numeros reais, maior precisão do que floats
	char my_char = 'a';		//Caracteres
	
	//Apenas disponivel com C23, mas existe no header stdbool.h
	//bool my_bool = true;

	printf("valor da variavel: %i | tamanho em bytes: %lu\n", my_int, sizeof(my_int));
	printf("valor da variavel: %c | tamanho em bytes: %lu\n", my_char, sizeof(my_char));
	printf("valor da variavel: %f | tamanho em bytes: %lu\n", my_float, sizeof(my_float));
	printf("valor da variavel: %lf | tamanho em bytes: %lu\n", my_float, sizeof(my_float));
	//printf("valor da variavel: %b | tamanho em bytes: %lu\n", my_bool, sizeof(my_bool));

	/*Palavras de modificação*/
	//Palavras que vem antes do tipo de variavel

	//Palavras que modificam o tamanho variaveis de tipo inteiro
	short int my_short = 255;//short: divide o tamanho por dois
	long int my_long = 100000000000000000;//multiplica o tamanho por dois

	printf("valor da variavel: %i | tamanho em bytes: %lu\n", my_short, sizeof(my_short));
	printf("valor da variavel: %li | tamanho em bytes: %lu\n", my_long, sizeof(my_long));

	//OBS:
	//Depedendo do sistema e implementação, podemos modificar ainda mais
	//short short int shortest_int = 256;//overflow de inteira
	//long long int longest_int = 1234567890987654321;
	
	//printf("valor da variavel: %i | tamanho em bytes: %lu\n", shortest_int, sizeof(shortest_int));
	//printf("valor da variavel: %li | tamanho em bytes: %lu\n", longest_int, sizeof(longest_int));

	//Palavras de assinalação de inteiros
	unsigned int my_uint = -1;//undeflow de variavel, apenas numeros inteiros positivos
	unsigned char my_uchar = 257;//overflow de variavel, char tecnicamente é uma inteira
	
	printf("valor da variavel: %u | tamanho em bytes: %lu\n", my_uint, sizeof(my_uint));
	printf("valor da variavel: %u | tamanho em bytes: %lu\n", my_uchar, sizeof(my_uchar));

	//Palavras de qualificação
	
	const int const_int = 2;//valor não pode ser modificado a não ser por referencia(dependendo do compilador)
	volatile int volatile_int = 3;//a variavel não vai ser otimizada pelo o compilador

	/*Sinal para o sistema operacional*/
	//Caso tenha um valor diferente de zero, gera um sinal para o sistema operacional
	//que o programa não terminou de forma correta
	return 0;
}
