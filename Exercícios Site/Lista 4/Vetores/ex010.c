// 10. Faça um programa para ler a nota da prova de 15 alunos
// e armazene num vetor, calcule e imprima a media geral.

#include <stdio.h>

int main() {
    float notas[15], total;
    
    printf("Digite a nota de 15 alunos: ");
    for (int i = 0; i < 15; i++)
    {
        scanf("%f", &notas[i]);
    }

    for (int i = 0; i < 15; i++)
    {
        total += notas[i];
    }

    total = total / 15;
    printf("%.2f", total);
}