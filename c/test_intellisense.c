#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Hello, World!\n");
    char* str = malloc(100);
    strcpy(str, "Test");
    free(str);
    return 0;
} 