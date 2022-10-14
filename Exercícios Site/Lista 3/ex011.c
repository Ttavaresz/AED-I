// 11. Faça um programa que leia um numero inteiro positivo N e imprima
// todos os numeros naturais de 0 ate N em ordem crescente.

#include <stdio.h>

int main() {
    int n;
    printf("Digite um numero inteiro positivo: ");
    scanf("%i", &n);

    if (n >= 0) {
        for(int i = 0; i <= n; n--) {
        printf("%i\n", n);
        }
    }
}