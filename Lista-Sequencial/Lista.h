#ifndef LISTA_H
#define LISTA_H

#define MAX_SIZE 100 // Definindo um tamanho máximo para a lista

typedef struct {
    int data[MAX_SIZE];
    int size;
} List;

void createList(List *list);
int isEmpty(List *list);
int isFull(List *list);
int getSize(List *list);
int getElement(List *list, int position);
void setElement(List *list, int position, int value);
void insertElement(List *list, int position, int value);
void removeElement(List *list, int position);
void displayList(List *list);

#endif
