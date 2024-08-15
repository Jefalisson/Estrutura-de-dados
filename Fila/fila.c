#include <stdio.h>
#include <stdbool.h>

#define TAM_MAX 5 // Tamanho máximo da fila

typedef struct {
    int inicio;
    int fim;
    int nElementos;
    int dados[TAM_MAX];
} Fila;

// Inicializa a fila
void inicializaFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->nElementos = 0;
}

// Verifica se a fila está vazia
bool vazia(Fila *fila) {
    return fila->nElementos == 0;
}

// Verifica se a fila está cheia
bool cheia(Fila *fila) {
    return fila->nElementos == TAM_MAX;
}

// Obtém o primeiro elemento da fila
int primeiro(Fila *fila) {
    if (vazia(fila)) {
        return -1; // Fila vazia
    }
    return fila->dados[fila->inicio];
}

// Insere um elemento no fim da fila
bool insere(Fila *fila, int valor) {
    if (cheia(fila)) {
        printf("Erro: A fila esta cheia!\n");
        return false;
    }
    fila->fim = (fila->fim + 1) % TAM_MAX; // Circularidade
    fila->dados[fila->fim] = valor;
    fila->nElementos++;
    return true;
}

// Remove um elemento do início da fila
int removeElemento(Fila *fila) {
    if (vazia(fila)) {
        printf("Erro: A fila esta vazia!\n");
        return -1; // Fila vazia
    }
    int valorRemovido = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % TAM_MAX; // Circularidade
    fila->nElementos--;
    return valorRemovido;
}

// Imprime o estado da fila
void imprimeFila(Fila *fila) {
    if (vazia(fila)) {
        printf("A fila esta vazia.\n");
        return;
    }
    printf("Fila: ");
    for (int i = 0; i < fila->nElementos; i++) {
        int indice = (fila->inicio + i) % TAM_MAX;
        printf("%d ", fila->dados[indice]);
    }
    printf("\n");
}
