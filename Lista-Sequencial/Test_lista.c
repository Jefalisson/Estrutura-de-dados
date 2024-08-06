#include "lista.h"
#include <stdio.h>

// Casos de teste
void testList() {
    List list;
    createList(&list);

    // Inserir elementos
    insertElement(&list, 1, 10); // Inserindo 10 na posição 1
    insertElement(&list, 2, 20); // Inserindo 20 na posição 2
    insertElement(&list, 2, 15); // Inserindo 15 na posição 2

    printf("Tamanho da lista: %d\n", getSize(&list)); // Exibe tamanho da lista
    displayList(&list);

    // Modificar um elemento
    setElement(&list, 2, 25); // Modifica o valor na posição 2 para 25
    printf("\nApós modificação:\n");
    displayList(&list);

    // Remover um elemento
    removeElement(&list, 2); // Remove elemento na posição 2
    printf("\nApós remoção:\n");
    displayList(&list);
}

int main() {
    testList(); // Executa os casos de teste
    return 0;
}
