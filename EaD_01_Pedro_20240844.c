#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

typedef struct {
    int numero;
    char nome[50];
    int tempo_atendimento;
} Cliente;

void adicionar_cliente(Fila* fila) {
    Cliente* c = (Cliente*) malloc(sizeof(Cliente));
    printf("Digite o numero do cliente: ");
    scanf("%d", &c->numero);
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", c->nome);
    printf("Digite o tempo de atendimento (minutos): ");
    scanf("%d", &c->tempo_atendimento);
    enqueue(fila, c);
    printf("Cliente adicionado com sucesso.\n");
}

void atender_cliente(Fila* fila, int* total_tempo, int* clientes_atendidos) {
    Cliente* c = (Cliente*) dequeue(fila);
    if (c) {
        printf("Atendendo cliente: %s (%d min)\n", c->nome, c->tempo_atendimento);
        *total_tempo += c->tempo_atendimento;
        (*clientes_atendidos)++;
        free(c);
    } else {
        printf("Nenhum cliente na fila.\n");
    }
}

int main() {
    Fila fila;
    inicializa_fila(&fila);
    int total_tempo = 0, clientes_atendidos = 0;
    int opcao;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Adicionar cliente\n");
        printf("2. Atender proximo cliente\n");
        printf("3. Mostrar tempo medio de atendimento\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_cliente(&fila);
                break;
            case 2:
                atender_cliente(&fila, &total_tempo, &clientes_atendidos);
                break;
            case 3:
                if (clientes_atendidos > 0)
                    printf("Tempo medio: %.2f minutos\n", (float)total_tempo / clientes_atendidos);
                else
                    printf("Nenhum cliente atendido ainda.\n");
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
