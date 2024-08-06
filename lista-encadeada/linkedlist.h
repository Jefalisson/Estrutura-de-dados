#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;           // Valor armazenado no nó
    struct Node* next;  // Ponteiro para o próximo nó
} Node;

typedef struct LinkedList {
    Node* head; // Ponteiro para o primeiro nó (cabeça) da lista
} LinkedList;

// Funções 
void createList(LinkedList* list);
int isEmpty(LinkedList* list);
int getSize(LinkedList* list);
int getElement(LinkedList* list, int position);
void setElement(LinkedList* list, int position, int value);
void insertElement(LinkedList* list, int position, int value);
void removeElement(LinkedList* list, int position);
void printList(LinkedList* list);

#endif 
