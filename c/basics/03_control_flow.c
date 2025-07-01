#include <stdio.h>

int main()
{
	//Estruturas de comparação
	if(30 > 20)
	{
		printf("Chegou no if\n");
	}
	else if ('x' == 'a') 
	{
		printf("Chegou no else if\n");
	}
	else
	{
		printf("Chegou no else\n");
	}

	//Estruturas de repetição
	//while
	int _i = 1;
	while (_i)// Avalia pra maior de zero
	{

		printf("_i = %i\n", _i);
		_i++;
		if(_i == 10)
		{
			break;
		}
	}


	//for
	for(int i = 10; i == 0; i--)
	{

	}

	//do while
	do {
		printf("_i = %i\n", _i);
		_i--;
	}while (_i);

	return 0;
}
