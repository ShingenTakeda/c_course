#include <stdio.h>

int main()
{
	/*Declaração de variavel com initialização*/
	//  /lvalue		/rvaues
	int minha_int_numerica = 5;
	int minha_int_bin = 0b10000;//Da um valor por notação binaria
	int minha_int_hex = 0xff0a05;//Da um valor por notação hexadecimal
	int exemplo_de_inicializacao_zero = {0};//Inicializa a variavel com o equivalente a zero ao tipo
	int var_nao_inicializada;//Variavel não inicializada e sem valor, cuidado qua
	
	/*Operadores e seus usos*/
	int i = 5;
	int e = i++;	// e = 5 | i = 6
	printf("e = %i | i = %i\n", e, i);
	e = i--;	// e = 6 | i = 5
	printf("e = %i | i = %i\n", e, i);
	e = ++i;	// e = 6 | i = 6
	printf("e = %i | i = %i\n", e, i);
	e = --i;	// e = 5 | i = 5
	printf("e = %i | i = %i\n", e, i);
	
	//Operadores bitwise
	
	//complemento
	unsigned char c = 0xff;
	unsigned int ui = ~c;//Ja que a char acima eh ff, ou seja 000000FF, o valor do complemento vai ser FFFFFF00
	printf("i = %02X\n", ui);

	//Shifting
	ui = ui >> 8;//shifting by a byte to the right, now it is 00FFFFFF, ja que cada zero é 4 bits
	printf("i = %02X | complement : %02X\n", ui, ~ui);

	//AND logico
	

	return 0;
}
