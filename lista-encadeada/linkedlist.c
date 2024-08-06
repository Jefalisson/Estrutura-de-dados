#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void createList(LinkedList* list) {
    list->head = NULL; // Inicializa o ponteiro cabeça como NULL, indicando lista vazia
}

int isEmpty(LinkedList* list) {
    return list->head == NULL; // Retorna 1 (verdadeiro) se a lista estiver vazia, 0 caso contrário
}

// Obter o tamanho da lista
int getSize(LinkedList* list) {
    int size = 0;
    Node* current = list->head;
    while (current != NULL) { // Percorre a lista contando os nós
        size++;
        current = current->next;
    }
    return size;
}

// Obter o valor de um elemento em uma posição específica
int getElement(LinkedList* list, int position) {
    if (position < 1) {
        printf("Posicao inválida!\n");
        return -1; // Retorna -1 para posição inválida
    }
    Node* current = list->head;
    int index = 1;
    while (current != NULL && index < position) {
        current = current->next;
        index++;
    }
    if (current == NULL) {
        printf("Posição invalida!\n");
        return -1;
    }
    return current->data; // Retorna o valor encontrado na posição
}

// Modificar o valor de um elemento em uma posição específica
void setElement(LinkedList* list, int position, int value) {
    if (position < 1) {
        printf("Posicao invalida!\n");
        return;
    }
    Node* current = list->head;
    int index = 1;
    while (current != NULL && index < position) {
        current = current->next;
        index++;
    }
    if (current == NULL) {
        printf("Posicao invalida!\n");
        return;
    }
    current->data = value; // Define o novo valor na posição
}

// Inserir um elemento em uma posição específica
void insertElement(LinkedList* list, int position, int value) {
    if (position < 1) {
        printf("Posicao invalida!\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node)); // Aloca memória para um novo nó
    newNode->data = value;
    if (position == 1) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }
    Node* current = list->head;
    int index = 1;
    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }
    if (current == NULL) {
        printf("Posicao invalida!\n");
        free(newNode); // Libera a memória
        return;
    }
    newNode->next = current->next; // Insere o novo nó na posição correta
    current->next = newNode;
}

// Remover um elemento de uma posição específica
void removeElement(LinkedList* list, int position) {
    if (position < 1) {
        printf("Posicao invalida!\n");
        return;
    }
    Node* current = list->head;
    if (position == 1) { // Remoção do primeiro nó
        list->head = current->next;
        free(current);
        return;
    }
    Node* previous = NULL;
    int index = 1;
    while (current != NULL && index < position) {
        previous = current;
        current = current->next;
        index++;
    }
    if (current == NULL) {
        printf("Posicao invalida!\n");
        return;
    }
    previous->next = current->next; // Remove o nó da posição correta
    free(current);
}

// Função para o printf dos elementos
void printList(LinkedList* list) {
    Node* current = list->head;
    int index = 1;
    while (current != NULL) {
        printf("Elemento na posicao %d: %d\n", index, current->data);
        current = current->next;
        index++;
    }
}
