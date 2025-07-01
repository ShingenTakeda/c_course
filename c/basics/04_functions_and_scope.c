#include <stdio.h>

//funções precisam de um tipo basico ou composto de retorno
char a_char_correta()
{
	return 'a';
}

//com void não é necessario retornar nada
void func_sem_retorno()
{
	printf("retorna nada!\n");
}

void testando_static()
{
	static int x = 0;
	x++;//o valor de x aumenta apesar de estar dentro do escopo da função
	printf("x dentro de testando_static: %i\n", x);
}

//função com argumentos
int soma(int a, int b)
{
	return a + b;
}


void func_que_faz_quase_nada(int a)
{
	a *= 2;
	printf("valor de int dada a func: %i\n", a);
}

int main()
{
	char c = 'a';
	char b = 'b';

	//Podemos usar o valor de retorno de uma função para comparação
	if(c == a_char_correta())
	{
		b = a_char_correta();
	}

	printf("valor de b: %c\n", b);

	func_sem_retorno();

	//Testando como a static funciona
	for (int i = 0; i < 10; i++)
	{
		testando_static();
	}

	//o escopo também pode ser limitado com chaves
	{
		int impossivel_de_pegar = 20;
	}
	
	int a = 20;
	int d = 32;

	//usando uma função com argumentos
	a = soma(a, d);
	printf("valor de c: %i\n", a);
	
	func_que_faz_quase_nada(a);
	//note que aqui o valor de a "volta" a ser 52, isso é porque passamos a variavel por copia
	printf("valor de c: %i\n", a);

	//descomente a baixo e tente compilar para ver os niveis de escopo
	//int x = impossivel_de_pegar;

	return 0;
}
