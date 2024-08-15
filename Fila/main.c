#include <stdio.h>
#include "fila.c"

int main() {
    Fila fila;
    inicializaFila(&fila);

    // Teste: Verificando se a fila está vazia
    printf("Teste 1: Verificar se a fila esta vazia.\n");
    if (vazia(&fila)) {
        printf("A fila esta vazia.\n");
    } else {
        printf("A fila nao esta vazia.\n");
    }

    // Teste: Inserir elementos na fila
    printf("\nTeste 2: Inserir elementos na fila.\n");
    insere(&fila, 10);
    insere(&fila, 20);
    insere(&fila, 30);
    insere(&fila, 40);
    imprimeFila(&fila);

    // Teste: Consultar o primeiro elemento
    printf("\nTeste 3: Consultar o primeiro elemento.\n");
    printf("Primeiro elemento: %d\n", primeiro(&fila));

    // Teste: Remover elemento da fila
    printf("\nTeste 4: Remover o primeiro elemento da fila.\n");
    removeElemento(&fila);
    imprimeFila(&fila);

    // Teste: Inserir mais elementos e encher a fila
    printf("\nTeste 5: Inserir mais elementos ate a fila estar cheia.\n");
    insere(&fila, 50);
    insere(&fila, 60);
    imprimeFila(&fila);

    // Teste: Verificar se a fila está cheia
    printf("\nTeste 6: Verificar se a fila esta cheia.\n");
    if (cheia(&fila)) {
        printf("A fila esta cheia.\n");
    } else {
        printf("A fila nao esta cheia.\n");
    }

    // Teste: Verificar se a fila está vazia
    printf("\nTeste 7: Verificar se a fila esta vazia novamente.\n");
    if (vazia(&fila)) {
        printf("A fila esta vazia.\n");
    } else {
        printf("A fila nao esta vazia.\n");
    }

    return 0;
}
