#include <stdio.h>

int main()
{
    int value, av, parc, comav, comparc;
    printf("Digite o valor do produto: ");
    scanf("%i", &value);
    av = value * 0.9;
    parc = value / 3;
    comav = av * 0.05;
    comparc = value * 0.05;
    printf("\nO valor do produto a vista eh: %d.00", av);
    printf("\nO valor do produto no prazo eh: 3x %d.00", parc);
    printf("\nComissão do vendedor a vista eh: %d.00", comav);
    printf("\nComissão do vendedor a prazo eh: %d.00\n", comparc);
    return 0;
}