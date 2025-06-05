#include <stdio.h>
#ifndef PILHA_H
#define PILHA_H

#define MAX 100

typedef struct {
    void* dados[MAX];
    int topo;
} Pilha;

void inicializa_pilha(Pilha* p);
int push(Pilha* p, void* item);
void* pop(Pilha* p);
int pilha_vazia(Pilha* p);

#endif
