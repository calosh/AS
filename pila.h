#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_MAX 100

typedef struct nodo_s {
    char dato[STACK_MAX];
    struct nodo_s *siguiente;
} nodo_t;

typedef nodo_t *ptrNodo;
typedef nodo_t *ptrPila;
void push(ptrPila *pila, char x[]);
void pop(ptrPila *pila);
void presentar_pila(ptrNodo nodo);


/*
    Agrega un nodo al inicio de la lista ligada
 *pila es el apuntador que apunta al primer nodo de la lista ligada (la cima de la pila)
 */
void push(ptrPila *pila, char x[]) {
    // Crea un nuevo nodo
    ptrNodo nodo;
    nodo = (ptrNodo) malloc(sizeof (nodo_t));
    if (nodo != NULL) {
        int i = 0;
        for (i = 0; i < STACK_MAX; i++) {
            nodo->dato[i] = x[i];
        }

        // El apuntador nodo->siguiente va a apuntar al primer nodo de la lista ligada
        nodo->siguiente = *pila;
        // pila va a apuntar al nuevo nodo, con esto hacemos que el nuevo nodo sea ahora el primer nodo de la lista ligada
        *pila = nodo;
    }
}

/*
    Elimina el primer nodo de la lista ligada
 *pila es el apuntador que apunta al primer nodo de la lista ligada (la cima de la pila)
 */
void pop(ptrPila *pila) {
    // Crea un nuevo nodo
    ptrNodo nodo;
    // El nuevo nodo va a apuntar al primer nodo de la lista ligada
    nodo = *pila;
    // x = (*pila)->dato[0];
    // Ahora el segundo nodo de la lista ligada va a ser el primero
    *pila = (*pila)->siguiente;
    // Borra el primer nodo de la lista ligada
    free(nodo);
}

/*
   Muestra los datos de los nodos
 */
void presentar_pila(ptrNodo Pila) {
    ptrNodo nodo = NULL;
    nodo = Pila;

    if (nodo == NULL)
        printf("La pila está vacia\n");
    else {
        printf("\n Estados de pila actual\n");
        while (nodo != NULL) {
            printf("%s\n", nodo->dato);
            nodo = nodo->siguiente;
        }
        printf("\n");
    }
}
