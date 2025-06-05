#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializa_fila(Fila* f) {
    f->inicio = f->fim = f->tamanho = 0;
}

int fila_vazia(Fila* f) {
    return f->tamanho == 0;
}

int fila_cheia(Fila* f) {
    return f->tamanho == MAX;
}

int enqueue(Fila* f, void* item) {
    if (fila_cheia(f)) return 0;
    f->dados[f->fim] = item;
    f->fim = (f->fim + 1) % MAX;
    f->tamanho++;
    return 1;
}

void* dequeue(Fila* f) {
    if (fila_vazia(f)) return NULL;
    void* item = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return item;
}

void* frente(Fila* f) {
    if (fila_vazia(f)) return NULL;
    return f->dados[f->inicio];
}
