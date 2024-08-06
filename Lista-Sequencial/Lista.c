#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

// Criação da lista vazia
void createList(List *list) {
    list->size = 0;
}

// Verificar se a lista está vazia
int isEmpty(List *list) {
    return list->size == 0;
}

// Verificar se a lista está cheia
int isFull(List *list) {
    return list->size == MAX_SIZE;
}

// Obter o tamanho da lista
int getSize(List *list) {
    return list->size;
}

// Obter o valor do elemento de uma determinada posição na lista
int getElement(List *list, int position) {
    if (position < 1 || position > list->size) {
        printf("Posição inválida!\n");
        return -1; // Retorna -1 para indicar posição inválida
    }
    return list->data[position - 1]; // Ajustando para índice do vetor
}

// Modificar o valor do elemento de uma determinada posição na lista
void setElement(List *list, int position, int value) {
    if (position < 1 || position > list->size) {
        printf("Posição inválida!\n");
    } else {
        list->data[position - 1] = value; // Ajustando para índice do vetor
    }
}

// Inserir um elemento em uma determinada posição
void insertElement(List *list, int position, int value) {
    if (isFull(list)) {
        printf("Lista cheia!\n");
        return;
    }
    if (position < 1 || position > list->size + 1) {
        printf("Posição inválida!\n");
        return;
    }
    for (int i = list->size; i >= position; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[position - 1] = value; // Ajustando para índice do vetor
    list->size++;
}

// Retirar um elemento de uma determinada posição
void removeElement(List *list, int position) {
    if (position < 1 || position > list->size) {
        printf("Posição inválida!\n");
        return;
    }
    for (int i = position - 1; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}

// Função para exibir todos os elementos da lista
void displayList(List *list) {
    for (int i = 0; i < list->size; i++) {
        printf("Elemento na posição %d: %d\n", i + 1, list->data[i]);
    }
}
