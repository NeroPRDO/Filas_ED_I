#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

typedef struct {
    char dado[50];
    int prioridade; // 1 = alta, 2 = média, 3 = baixa
} ItemPrioridade;

typedef struct {
    ItemPrioridade dados[MAX];
    int tamanho;
} FilaPrioridade;

void inicializa_fila_prioridade(FilaPrioridade* f) {
    f->tamanho = 0;
}

int fila_enqueue_prioridade(FilaPrioridade* f, ItemPrioridade item) {
    if (f->tamanho >= MAX) return 0;
    int i = f->tamanho - 1;
    while (i >= 0 && item.prioridade < f->dados[i].prioridade) {
        f->dados[i + 1] = f->dados[i];
        i--;
    }
    f->dados[i + 1] = item;
    f->tamanho++;
    return 1;
}

ItemPrioridade fila_dequeue_prioridade(FilaPrioridade* f) {
    return f->dados[--f->tamanho];
}

void adicionar_tarefa_manual(FilaPrioridade* fila) {
    ItemPrioridade item;
    printf("Descricao da tarefa: ");
    scanf(" %[^\n]", item.dado);
    printf("Prioridade (1 = alta, 2 = media, 3 = baixa): ");
    scanf("%d", &item.prioridade);
    if (fila_enqueue_prioridade(fila, item))
        printf("Tarefa adicionada com sucesso.\n");
    else
        printf("Fila cheia.\n");
}

void adicionar_tarefa_auto(FilaPrioridade* fila, const char* desc, int prioridade) {
    ItemPrioridade item;
    strcpy(item.dado, desc);
    item.prioridade = prioridade;
    fila_enqueue_prioridade(fila, item);
}

void atender_tarefa(FilaPrioridade* fila) {
    if (fila->tamanho == 0) {
        printf("Nenhuma tarefa na fila.\n");
        return;
    }
    ItemPrioridade item = fila_dequeue_prioridade(fila);
    printf("Atendendo: %s (prioridade %d)\n", item.dado, item.prioridade);
}

void executar_teste_automatico(FilaPrioridade* fila) {
    adicionar_tarefa_auto(fila, "Tarefa urgente", 1);
    adicionar_tarefa_auto(fila, "Tarefa comum", 2);
    adicionar_tarefa_auto(fila, "Tarefa de lazer", 3);
    printf("Tarefas adicionadas automaticamente.\n");

    while (fila->tamanho > 0) {
        atender_tarefa(fila);
    }
}

int main() {
    FilaPrioridade fila;
    inicializa_fila_prioridade(&fila);
    int opcao;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Adicionar tarefa manualmente.\n");
        printf("2. Atender proxima tarefa.\n");
        printf("9. Executar teste automatico.\n");
        printf("0. Sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_tarefa_manual(&fila);
                break;
            case 2:
                atender_tarefa(&fila);
                break;
            case 9:
                executar_teste_automatico(&fila);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
