#include <stdio.h>
#ifndef FILA_H
#define FILA_H

#define MAX 100

typedef struct {
    int inicio, fim, tamanho;
    void* dados[MAX];
} Fila;

void inicializa_fila(Fila* f);
int fila_vazia(Fila* f);
int fila_cheia(Fila* f);
int enqueue(Fila* f, void* item);
void* dequeue(Fila* f);
void* frente(Fila* f);

#endif
