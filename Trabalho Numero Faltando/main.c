/*
Nome: Lucas Tavares || Turma: M1

Dado um vetor nums contendo n número inteiros positivos e únicos encontre o número
faltante na sequência. Assuma que somente um número está faltando para completar a
sequência numérica.
*/

#include <stdio.h>

int main() {
    int n, soma = 0, final = 0, data;
    // Digitar o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    // Digitar os valores do array
    int nums[n];
    printf("Digite valores aleatorios no intervalo [0,%d]\n", n);
    for (int i = 0; i < n; i++) {
        printf("Digite um valor: ");
        scanf("%d", &nums[i]);
        soma += nums[i];
    }

    printf("\n============================\n");

    // Mostrar os valores do array
    printf("Entrada: ");
    for (int j = 0; j < n; j++) {
        printf("%d ", nums[j]);
    }

    // Somar o valor que o array deveria ter com o valor que falta
    for (int j = 0; j < n+1; j++) {
        final += j;
    }

    // Subtrair e descobrir o valor ausente no intervalo
    final -= soma;
    printf("\nResultado: %d\n", final);

    return 0;
}
