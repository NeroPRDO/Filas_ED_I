#include <stdio.h>
#include "pilha.h"

void inicializa_pilha(Pilha* p) {
    p->topo = -1;
}

int push(Pilha* p, void* item) {
    if (p->topo >= MAX - 1) return 0;
    p->dados[++p->topo] = item;
    return 1;
}

void* pop(Pilha* p) {
    if (p->topo < 0) return NULL;
    return p->dados[p->topo--];
}

int pilha_vazia(Pilha* p) {
    return p->topo == -1;
}
