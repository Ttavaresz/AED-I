// 10. Crie um programa que contenha um array de inteiros contendo
// 5 elementos. Utilizando apenas aritme ́tica de ponteiros, leia 
// esse array do teclado e imprima o dobro de cada valor lido.

#include <stdio.h>

int main()
{
    int array[5];
    int *p = array;
    
    for (int i = 0; i < 5; i++)
    {
        printf("Valor %d: ", i+1);
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\nValor %d: %d", i+1, p[i]*2);
    }
    
    return 0;
}
