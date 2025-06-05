#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "fila.h"
#include "pilha.h"

int eh_palindromo(char* palavra) {
    Fila f;
    Pilha p;
    inicializa_fila(&f);
    inicializa_pilha(&p);

    for (int i = 0; palavra[i]; i++) {
        char c = tolower(palavra[i]);
        if (isalpha(c)) {
            enqueue(&f, (void*)(long)c);
            push(&p, (void*)(long)c);
        }
    }

    while (!fila_vazia(&f)) {
        char c1 = (char)(long)dequeue(&f);
        char c2 = (char)(long)pop(&p);
        if (c1 != c2) return 0;
    }
    return 1;
}

int main() {
    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    if (eh_palindromo(palavra))
        printf("E palindromo!\n");
    else
        printf("Nao e palindromo.\n");

    return 0;
}
