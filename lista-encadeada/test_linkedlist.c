#include <stdio.h>
#include "linkedlist.h"

int main() {
    LinkedList list;

    createList(&list);

    // Teste: Inserir elementos na lista
    insertElement(&list, 1, 10); // Insere 10 na posição 1
    insertElement(&list, 2, 20); // Insere 20 na posição 2
    insertElement(&list, 2, 15); // Insere 15 na posição 2
    printf("Lista apos insercoes:\n");
    printList(&list);

    // Teste: Modificar elemento na lista
    setElement(&list, 2, 25); // Modifica o valor na posição 2 para 25
    printf("Lista apos modificacao:\n");
    printList(&list);

    // Teste: Remover elemento da lista
    removeElement(&list, 2); // Remove o elemento na posição 2
    printf("Lista apos remocao:\n");
    printList(&list);

    // Teste: Verificar se a lista está vazia
    printf("A lista esta vazia? %s\n", isEmpty(&list) ? "Sim" : "Nao");

    // Teste: Obter o tamanho da lista
    printf("Tamanho da lista: %d\n", getSize(&list));

    return 0;
}
