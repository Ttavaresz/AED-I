/*
Nome: Lucas Dutra Tavares || Turma: M1

Construir uma árvore binária que adicione valores enquato o usuário for digitando,
quando o usuário quiser para ele avisa e logo após o código avisa se a árvore criada
é ou não AVL.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Arvore {
    int numero;
    struct Arvore *pEsq, *pDir;
} No;
 
// Função para criar novo no na arvore a cada insere chamado
No* novoNo(int data){
    No* temp = malloc(sizeof(No));
    temp->pEsq = NULL;
    temp->pDir = NULL;
    temp->numero = data;
    return temp;
}

//Insere servirá para inserir os valores na árvore binária
No *Insere(No *ppRaiz, int x) {
    if (ppRaiz == NULL) {
        return novoNo(x);
    }
    
    if (x < ppRaiz->numero) {
        ppRaiz->pEsq = Insere(ppRaiz->pEsq, x);
    } else if (x > ppRaiz->numero) {
        ppRaiz->pDir = Insere(ppRaiz->pDir, x);
    }

    return ppRaiz;
}

// Função para verificar qual é o maior valor
int maior(int a, int b)
{
    return (a >= b) ? a : b; 
}

//Fator de Balanceamento e Altura vão servir para consultar se a árvore é AVL ou não.
int FB (No *pRaiz) {
    if(pRaiz == NULL) {
        return 0;
    }

    return 1 + maior(FB(pRaiz->pEsq), FB(pRaiz->pDir));
}

int Altura(No *pRaiz) {
    int iEsq, iDir;

    if (pRaiz == NULL) {
        return 1;
    }

    iEsq = FB(pRaiz->pEsq);
    iDir = FB(pRaiz->pDir);

    if (abs(iEsq - iDir) <= 1 && Altura(pRaiz->pEsq) && Altura(pRaiz->pDir)) {
        return 1;
    }

    return 0;
}

int main() {
    int num, op = 0;
    No *ppRaiz = NULL;

    while(op != 2) {
        printf("\n\t1. Inserir novo valor\n");
        printf("\t2. Sair do programa\n");
        printf("Digite uma opcao: ");
        scanf("%d", &op);
        switch (op) {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &num);
            ppRaiz = Insere(ppRaiz, num);
            break;
        case 2:
            if(Altura(ppRaiz) == 1) {
                printf("Arvore AVL");
            } else {
                printf("Arvore nao AVL");
            }
            break;
        default:
            printf("Valor invalido, digite novamente:\n");
            break;
        }
    }    
    return 0;
}