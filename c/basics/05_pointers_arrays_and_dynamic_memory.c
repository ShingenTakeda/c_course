#include <stdio.h>
#include <stdlib.h>

void func_muda_valor_var(int *a)
{
	*a += 2;
}

//Arrays decaem e viram ponteiros
//Aqui estamos usando um ponteiro duplo para modificar os valores dentro do array
void func_arr_como_arg(int *a, int tam_arr)//tam_arr é passado como copia, que se aloca em heap ou em data dependendo do compilador
{
	//utilizando acesso de array em um ponteiro
	for(int i = 0; i < tam_arr; i++)
	{
		a[i] += 5;
	}
}

void func_str_como_arg(char *a)//uma string
{
	printf("%s\n", a);
}

int main()
{
	//Arrays
	int a[4] = {1, 2, 3, 4};//como inicializar arrays

	//como acessar as variaveis dentro do array
	for(int i = 0; i < 4; i++)
	{
		printf("a[%i] = %i\n", i, a[i]);
	}

	//Note que não podemos pegar o tamanho do do array

	//Desomente o loop abaixo e veja o que acontece com a execução do programa
	//for(int i = 0; i < 5; i++)
	//{
	//	printf("a[%i] = %i\n", i, a[i]);
	//}
	
	//C não tem um tipo string, uma string padrão em c é apenas um array de chars
	char str_estatica[12] = "Hello world!";//Uma string é denotada com aspas duplas("") ao inves de aspas simples('')
	printf("str_estatica: %s\n", str_estatica);
	
	char outra_str[] = "World hello!";//Podemos tambem deixar o tamanho vazio e apenas colocar valores como inicialização de um array, isso se chama arrays de tamanho variavel
	printf("str_estatica: %s\n", outra_str);

	//Note que estes arrays são estaticos

	//Ponteiros
	int minha_int = 5;
	int *int_ptr = &minha_int;//Fazendo referencia ao local da minha_int
	printf("endereco da minha_int em memoria: %X | valor da minha_int por dereferenciacao: %i\n", int_ptr, *int_ptr);//derefenciação é melhor escrita da seguinte forma: *(ptr_var)
	
	//aqui esta demonstrando como percorrer um array como se fosse um ponteiro
	for(int i = 0; i < 4; i++)
	{
		printf("a[%i] = %i\n", i, *(a + i));
	}

	func_muda_valor_var(&minha_int);

	func_arr_como_arg(a, 4);
	printf("valor da minha_int depois de ser passada na func: %i\n", minha_int);
	for(int i = 0; i < 4; i++)
	{
		printf("a[%i] = %i\n", i, a[i]);
	}

	
	func_str_como_arg("apenas uma string");//uma string
	
	//podemos criar uma string de uma forma mais facil
	char *str_simples = "isto eh uma string!\n";
	printf(str_simples);

	//Alocação de memoria
	int *b = (int *)malloc(sizeof(int) * 10);//alocando um tamanho x dado em bytes em heap, aqui como exemplo, 320 bytes(10 * tamanho de uma int)
	
	//o ponteiro b esta apontado para memoria alocada, mas não inicializada
	for(int i = 0; i < 10; i++)
	{
		b[i] = i;
	}
	
	for(int i = 0; i < 10; i++)
	{
		printf("b[%i] = %i\n", i, b[i]);
	}

	//podemos realocar mais memoria para o ponteiro 
	b = (int *)realloc(b, sizeof(int) * 20);

	for(int i = 0; i < 20; i++)
	{
		b[i] = i + 2;
	}

	for(int i = 0; i < 20; i++)
	{
		printf("b[%i] = %i\n", i, b[i]);
	}

	//calloc initializes memory to zero
	int *c = (int *)calloc(10 ,sizeof(int));
	
	for(int i = 0; i < 10; i++)
	{
		printf("c[%i] = %i\n", i, c[i]);
	}

	//Frees memory in heap, be careful to not double free
	free(b);
	free(c);

	return 0;//if you are executing the code in an modern os, it usually frees the memory when exiting a program
}
