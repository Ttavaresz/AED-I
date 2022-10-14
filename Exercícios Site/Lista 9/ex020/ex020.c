// 20. Implemente uma funcao que receba como parametro um array de numeros reais de
// tamanho N e retorne quantos numeros negativos ha nesse array. Essa funcao deve
// obedecer ao prototipo:
// int negativos(float *vet, int N);

#include <stdio.h>
#include <stdlib.h>

float *vet, temp;
int N = 0, *data;

int negativos(float *vet, int N);

int main() {
    int loop = 0, escolha, qtdNegativos;
    

    if((vet = (float *)malloc(sizeof(float))) == NULL) { // Alocando memoria para o vetor
        printf("Nao foi possivel alocar memoria\n");
        exit(1);
    }
    system("cls");
    while (loop == 0)
    {
        printf("\nQual a opcao desejada?\n");
        printf("\t1 - Inserir numeros\n");
        printf("\t2 - Listar numeros\n");
        printf("\t3 - Listar quantidade de numeros negativos\n");
        printf("\t4 - Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%i", &escolha);
        switch (escolha)
        {
        case 1:
            inserirNum();
            break;
        
        case 2:
            listarNum();
            break;
        
        case 3:
            system("cls");
            qtdNegativos = negativos(vet, N);
            printf("=============================================\n"); 
            printf("Quantidade de numeros negativos inseridos: %d\n", qtdNegativos);
            printf("=============================================\n");    
            break;
        

        case 4:
            printf("\n\n\tSAINDO...\n\n\n");
            loop = 1;
            break;
        
        default:
            break;
        }
    }   
}

int inserirNum() {
    N++;
    vet = (float *)realloc(vet, N * sizeof(float));
    data = vet;
    printf("\nDigite o valor real: ");
    scanf("%f", &temp);
    vet[N - 1] = temp;
    system("cls");
}

int listarNum() {
    system("cls");
    printf("=============================================\n"); 
    printf("Lista de numeros inseridos:\n");
    for (int i = 0; i < N; i++, vet++)
    {
        printf("Numero %d = %.2f\n", i + 1, *vet);
    }
    printf("=============================================\n");
    vet = data;
}

int negativos(float *vet, int N) {
    int qtdNegativos = 0;
    for (int i = 0; i < N; i++) {
        if (vet[i] < 0) {
            qtdNegativos++;
        }   
    }
    return qtdNegativos;
}