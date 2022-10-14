/*
#============================================================#
# Nome: Lucas Dutra Tavares - Turma: M1                      #
# AGENDA/Semana 2                                            #
#============================================================#                                                                                                                               
1-Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar,                                                 
porém, toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.                                               
                                                                                                                                                
2-Não pergunte para o usuário quantas pessoas ele vai incluir. Não pode alocar espaço para mais pessoas do que o necessário.                   
                                                                                                                                                
3-Cada pessoa tem nome[10], idade e telefone.                                                                                                  
                                                                                                                                                
4-Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer. 
Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.                                                           
                                                                                                                                                
5-Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro).                                                              
                                                                                                                                                
6-Não pode usar struct em todo o programa.                                                                                                     
                                                                                                                                                
7-Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.                        
                                                                                                                                                
8-Implementar a base de dados da agenda usando lista duplamente ligada                                                                         
                                                                                                                                                
9-Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.                                 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *pBuffer;          // Aponta para o endereço inicial do buffer
void *pPositionBuffer;  // Aponta para o endereço vazio do buffer
void **tracker;         // Percorre pela lista

// void *pHead;            // Aponta para o endereço do pFirst e pLast;
void **pFirst;           // Aponta o endereço do primeiro pName
void **pLast;            // Aponta o endereço do último pName

char *pName;            // Armazena sempre 10 caracteres para adicionar no buffer
int *pAge;              // Armazena sempre 1 float para adicionar no buffer
int *pPhone;            // Armazena sempre 1 double para adicionar no buffer
void **pPrev;            // Aponta para o endereço do pName anterior
void **pNext;            // Aponta para o endereço do próximo pName

int *amountPeople;      // Quantidade de pessoas
int *op;                // Opção desejada no menu

// Chamando as funções
void reset(pBuffer);
void head(pBuffer);
void menu();
void push();
void list();

int main() {
    pHead = malloc(2 * sizeof(void *));
    pFirst = malloc(sizeof(void *));
    pLast = malloc(sizeof(void *));

    amountPeople = (int *)malloc(sizeof(int));
    op = (int *)malloc(sizeof(int));

    reset();
    menu();

    return 0;
}

void reset(pBuffer) {   // Inicia a Lista
    (*amountPeople) = 0;
    *pFirst = pBuffer;
    *pLast = pBuffer;
    *pPrev = NULL;
    pPositionBuffer = *(void)pPrev;
    pPositionBuffer+= sizeof(void *);
    // *pNext = 
}

void head(pBuffer) {
    *pPrev = *pLast;
    pPositionBuffer = *(void)pPrev;
    pPositionBuffer+= sizeof(void *);
    // *pNext = 
    *pLast = pBuffer;
}

void push() {
    (*amountPeople)++;
    pBuffer = malloc(10 * sizeof(char) + 2 * sizeof(int) + 2 * sizeof(void **));
    pPositionBuffer = pBuffer;
    
    pName = (char *)malloc(10 * sizeof(char));
    pAge = (int *)malloc(sizeof(int));
    pPhone = (int *)malloc(sizeof(int));
    pPrev = malloc(sizeof(void *));
    pNext = malloc(sizeof(void *));

    printf("\n============= INSERIR =============\n");
    printf("PREENCHA OS CAMPOS ABAIXO\n");
    printf("Nome(ate 10 caracteres): ");
    scanf("%s", (char *)pName);
    memcpy(pPositionBuffer, pName, (10 * sizeof(char)));
    pPositionBuffer += 10 * sizeof(char);

    printf("Idade: ");
    scanf("%d", (int *)pAge);
    memcpy(pPositionBuffer, pAge, sizeof(int));
    pPositionBuffer += sizeof(int);
    
    printf("Telefone: ");
    scanf("%d", (int *)pPhone);
    memcpy(pPositionBuffer, pPhone, sizeof(int));
    pPositionBuffer += sizeof(int);

    void *savePosition;
    void *saveNext;
    
    if ((*amountPeople) == 1) {
        reset(pBuffer);
    } else if ((*amountPeople) > 1) {
        head(pBuffer);
    }
    
    savePosition = pBuffer;

    head(pBuffer);

    // Limpa a memória dos ponteiros
    free(pName);
    free(pAge);
    free(pPhone);
    free(pPrev);
    free(pNext);

    menu(); // Retorna ao Menu
}

void list() {
    pName = (char *)malloc(10 * sizeof(char));
    pAge = (int *)malloc(sizeof(int));
    pPhone = (int *)malloc(sizeof(int));

    int *pCounter = (int *)malloc(sizeof(int));

    pPositionBuffer = pBuffer;

    printf("\n============= LISTAR ==============\n");
    for (*(int *)pCounter = 0; *(int *)pCounter <= *(int *)amountPeople; (*pCounter)++) {
        printf("\n------------ PESSOA %d -------------\n", *(int *)pCounter + 1);
        memcpy(pName, pPositionBuffer, 10 * sizeof(char));
        printf("Nome: %c", *pName);
        pPositionBuffer += 10 * sizeof(char);

        memcpy(pAge, pPositionBuffer, sizeof(int));
        printf("\nIdade: %d | ", *(int *)pAge);
        pPositionBuffer += sizeof(int);

        memcpy(pPhone, pPositionBuffer, sizeof(int));
        printf("Telefone: %d\n", *(int *)pPhone);
        pPositionBuffer += sizeof(int);
    }

    // Limpa a memória dos ponteiros
    free(pName);
    free(pAge);
    free(pPhone);

    menu(); // Retorna ao Menu
}

void menu() {
    printf("\n============= AGENDA =============");
    printf("\nESCOLHA UMA OPCAO:\n");
    printf("\t1. Incluir nome na lista\n");
    printf("\t2. Apagar nome da lista\n");
    printf("\t3. Buscar nome na lista\n");
    printf("\t4. Listar nome da lista\n");
    printf("\t5. Sair\n");
    printf("\nOPCAO: ");
    scanf("%d", op);

    switch (*op) {
        case 1:
            push();
            break;
        
        case 2:
            // pop();
            break;

        case 3:
            // search();
            break;

        case 4:
            list();
            break;

        case 5:
            printf("Saindo...");
            break;

        default:
            menu();
    }
}