// 2. Escreva um programa que contenha duas varia ́veis
// inteiras. Compare seus enderec ̧os e exiba o maior enderec ̧o.

#include <stdio.h>

int main() {
    int variavel1;
    int variavel2;

    printf("Enderecos:\n");
    printf("%d\n", &variavel1);
    printf("%d\n", &variavel2);
    printf("O maior endereco eh o: ");

    if(&variavel1 > &variavel2) {
        printf("1(%d)", &variavel1);
    } else if(&variavel1 < &variavel2) {
        printf("2(%d)", &variavel2);
    }
}
