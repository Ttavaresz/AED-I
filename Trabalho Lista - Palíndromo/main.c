/*
#============================================================#
# Nome: Lucas Dutra Tavares - Turma: M1                      #
# PALINDROMO                                                 #
#============================================================#                                                                                                                               
Fazer um programa que testa se uma sequencia de caracteres fornecida
pelo usuário é um palíndromo, ou seja, é um palavra cuja metade é simétrica
à segunda metade. Veja os exemplos:
aabccbaa - sim
addfdda - sim
abffbb - não
O usuário digita uma letra e tecla ENTER até que ele digite x e enter, para
terminar a sequencia.
Incremente a função POP e PUSH de pilha e resolva o problema com elas. No video
demonstre pelo menos 4 casos de sim e 4 casos de não.                                                                                                                                            
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct palavra{
    char caracter;
    struct palavra *prev; // ADICIONAR ANTERIOR PARA CONSEGUIR O REVERSO DA PALAVRA
    struct palavra *next;
} Palavra;

void *pPosition;

void *pFirst;
void *pLast;

int *size;
char *letra;
char *letraFinal;

Palavra *reset(void);
void push(char *letra, Palavra *p);
void pop(Palavra *p);
bool isPalindrome(Palavra *p);

int main()
{
    Palavra *pBuffer;
    pBuffer = reset();

    size = (int *)malloc(sizeof(int));
    letra = (char *)malloc(sizeof(char));
    letraFinal = (char *)malloc(sizeof(char));
    memcpy(letraFinal, "x", sizeof(char));

    printf("Para parar o programa digite 'x' e ENTER\n");
    while (true) {
        printf("Digite uma letra: ");
        scanf("%c", (char *)letra);
        if (*letra == *letraFinal)
        {
            // if (isPalindrome()) {
            //     printf("A palavra e palindroma!");
            // }   else {
            //     printf("A palavra nao e palindroma!");
            // }
            free(letra);
            // freeList(); // CRIAR
            break;
        }
        push(letra, pBuffer);
        free(letra);
        (*size)++;
    }  
    return 0;
}

Palavra *reset(void) { // Inicia o head da lista encadeada
    Palavra *start;

    start = (Palavra *)malloc(sizeof(Palavra));
    start->prev = NULL;
    start->next = NULL;
    return start;
}

void push(char *letra, Palavra *p) {
    Palavra *palavra; // Aloca a Palavra

    palavra = (Palavra *)malloc(sizeof(Palavra));
    palavra->caracter = *(char *)letra;
    // memcpy(palavra->caracter, *letra, sizeof(char));

    if (*size == 0) {
    pFirst = palavra;
    palavra->prev = NULL;
    pLast = palavra;
    } else {
        palavra->prev = pLast;
        pLast = palavra;
    }

    palavra->next = p->next; // palavra aponta para o ponteiro do pBuffer = NULL
    p->next = palavra; // depois o pbuffer vai apontar para a palavra nova que vir
}

void pop(Palavra *p) {
    Palavra *delete;
    delete = p->next;
    p->next = delete->next;
    free(delete);
}

// char normal() {
//     Palavra *current = 
// }

// char reverse() {

// }

// bool isPalindrome(Palavra *p) {
//     char *pNormal = malloc(*size * sizeof(char));
//     char *pReverse = malloc(*size * sizeof(char));
//     Palavra *pNormal = normal();
//     Palavra *pReverse = reverse();
//     int *pCounter = malloc(sizeof(int));

//     memcmp(pNormal, pReverse, *size);
// }