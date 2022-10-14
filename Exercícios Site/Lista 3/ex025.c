// 25. Faça um programa que some todos os numeros naturais 
// abaixo de 1000 que sao multiplos de 3 ou 5.

#include <stdio.h>

int main () {
    int total, m3 = 0, m5 = 0;
    for (int i = 0; i <= 10; i++)
    {
        if(i % 3 == 0) {
            m3 += i;
        } else if(i % 5 == 0) {
            m5 += i;
        }
    }

    total = m3 + m5;
    printf("%d", total);
}