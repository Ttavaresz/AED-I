/*
Faça um programa que solicita do usuário uma série de números, cada número pode ser um
int, float ou double. Antes de solicitar o número pergunte qual tipo de dado o usuário vai entrar.
Todos os números entrados devem ser armazenados num buffer único. Esse buffer deve ter tamanho
dinâmico e não deve desperdiçar memória, por exemplo, alocar sempre espaço para um double
quando o usuário inserir um int ou float.
Você não deve solicitar para o usuário quantos números ele deseja entrar, na escolha do tipo
de dados coloque uma opção para parar a entrada da série de números. Após isso você deve imprimir
todos os números do buffer, primeiro toda a série em sequência depois novamente, mas primeiro os
ints seguido dos floats e doubles.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () 
{
    void *buffer;
    char *bufferTipo;

    int *bufferInt = (int *)buffer;
    float *bufferFloat = (float *)buffer;
    double *bufferDouble = (double *)buffer;

    int qtdInt = 0;
    int qtdFloat = 0;
    int qtdDouble = 0;
    int qtdNumeros = 0;

    int i = 0, f = 0, d = 0;

    int escolha, loop;

    while (loop == 0)
    {
        printf("\nQual tipo de dado sera armazenado?\n");
        printf("1 - int\n");
        printf("2 - float\n");
        printf("3 - double\n");
        printf("4 - sair\n");
        printf("Escolha a opcao desejada: ");
        scanf("%i", &escolha);

        switch (escolha)
        {
        // case 1 buffer = sizeof(int);
        // case 2 buffer = malloc(sizeof(numInt) + 1);
        // case 3 buffer = malloc(sizeof(numInt) + sizeof(numFloat) + 1);
        case 1:
            printf("Voce escolheu int\nDigite o valor a ser armazenado: ");
            scanf("%i", (int *)bufferInt);
            qtdInt ++;
            strcat(buffer, bufferInt[qtdInt - 1]);
            qtdNumeros ++;
            strcpy(bufferTipo, "i");
            break;

        case 2:
            printf("Voce escolheu float\nDigite o valor a ser armazenado: ");
            scanf("%f", (float *) bufferFloat);
            qtdFloat ++;
            strcat(buffer, bufferFloat[qtdFloat - 1]);
            qtdNumeros ++;
            strcpy(bufferTipo, "f");
            break;

        case 3:
            printf("Voce escolheu double\nDigite o valor a ser armazenado: ");
            scanf("%d", (double *) buffer);
            qtdDouble ++;
            strcat(buffer, bufferDouble[qtdDouble - 1]);
            qtdNumeros ++;
            strcpy(bufferTipo, "d");
            break;

        case 4:
            printf("\n============================");
            printf("\nOs numeros escritos foram:\n");
            for (int j = 0; j < qtdNumeros; j++) {
                if (bufferTipo[i] == "i") {
                    printf("%i", bufferInt[i]); // Descobrir como imprimir 1 valor por vez
                    i++;
                } else if (bufferTipo[i] == "f") {
                    printf("%f", bufferFloat[f]);
                    f++;
                } else if (bufferTipo[i] == "d") {
                    printf("%d", bufferDouble[d]);
                    d++;
                }
                if (j < qtdNumeros - 1)
                {
                    printf(" - ");
                }
            }
            printf("\n============================");
            printf("\nOs números inteiros foram:\n");
            printf("\n----------------------------");
            printf("\nOs números floats foram:\n");
            printf("\n----------------------------");
            printf("\nOs números doubles foram:\n");

            printf("\n============================");


            printf("\n\nSaindo...");
            loop = 1;
            break;

        default:
            printf("Opçao invalida.");
            break;
        }
    }
}