// 1. Escreva um programa que declare um inteiro, um real e um char, e ponteiros para
// inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os
// valores de cada varia ́vel usando os ponteiros. Imprima os valores das varia ́veis
// antes e apos a modificacao.

#include <stdio.h>

int main(void) {
    int i = 10;
    double r = 19.90;
    char c = 'a';

    int *pi = &i;
    double *pr = &r;
    char *pc = &c;

    printf("Inteiro: %i\nReal: %.2f\nChar: %c\n\n", *pi, *pr, *pc);

    *pi = 20;
    *pr = 29.50;
    *pc = 'b';

    printf("Inteiro: %i\nReal: %.2f\nChar: %c\n\n", i, r, c);

    return 0;
}