// 54. Faça um programa que receba um numero inteiro maior do que
// 1, e verifique se o numero fornecido e primo ou nao.

#include <stdio.h>

int main(){
    int value, div = 0;
    printf("Digite um numero inteiro maior que 1: ");
    scanf("%d", &value);

    for (int i = 1; i <= value; i++) {
        if (value % i == 0) { 
            div++;
        }
    }
    
    if (div == 2) {
        printf("O número %d é primo!", value);
    } else {
        printf("O número %d não é primo!", value);
    }
}