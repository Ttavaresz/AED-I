/*
40. O custo ao consumidor de um carro novo  ́e a soma do custo de f  ́abrica, da comiss  ̃ao
do distribuidor, e dos impostos. A comiss  ̃ao e os impostos s  ̃ao calculados sobre o custo
de f  ́abrica, de acordo com a tabela abaixo. Leia o custo de f  ́abrica e escreva o custo ao
consumidor.
*/
#include <stdio.h>

int main()
{
    int cf, comissao, imposto, final;
    printf("Digite o custo de fábrica de um veículo: ");
    scanf("%d", &cf);

    if (cf <= 12000) {
        comissao = cf * 0.05;
        final = cf + comissao;
    } else if (cf <= 25000) {
        comissao = cf * 0,1;
        imposto = cf * 0,15;
        final = cf + comissao + imposto;
    } else {
        comissao = cf * 0.15;
        imposto = cf * 0.2;
        final = cf + comissao + imposto;
    }

    printf("Valor final: %.2d", final);
    return 0;
}