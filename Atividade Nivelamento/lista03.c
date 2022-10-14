#include <stdio.h>

main () {
    int value1, value2, op, final;

    printf("Digite 2 valores\n");
    printf("Valor 1: ");
    scanf("%d", &value1);
    printf("Valor 2: ");
    scanf("%d", &value2);
    printf("\nDigite a operacao desejada:\n");
    printf("Adicao (opcao 1)\nSubtracao (opcao 2)\nMultiplicacao (opcao 3)\nDivisao (opcao 4)\nSaida (opcao 5)\n\n");
    scanf("%d", &op);

    switch (op) {
        case 1:
            final = value1 + value2;
            printf("A soma dos valores resulta em: %d", final);
            return 0;
        case 2:
            final = value1 - value2;
            printf("A subtracao dos valores resulta em: %d", final);
            return 0;    
        case 3:
            final = value1 * value2;
            printf("A multiplicacao dos valores resulta em: %d", final);
            return 0;
        
        case 4:
            final = value1 / value2;
            printf("A divisao dos valores resulta em: %d", final);
            return 0;
        case 5:
            break;
        
        default:
            printf("Valor inválido");
    }
}