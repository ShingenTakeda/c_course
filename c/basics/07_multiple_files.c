#include <stdio.h>//caminho absoluto
#include "header_use_example.h"//caminho relativo
#include "unity_build_example.c"

int main()
{
    printf("pegando soma simples do arquivo c: %i\n", soma_simples(23, 32));
    printf("soma de gauss do header: %i\n", gauss_prog(1,100));
    return 0;
}
