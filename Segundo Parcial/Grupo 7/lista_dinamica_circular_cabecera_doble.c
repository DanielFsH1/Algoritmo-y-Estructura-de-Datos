// Lista Dinámica Circular de enteros con 2 nodos de cabecera (2 apuntadores de referencia), con enlace doble entre nodos.

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
} Nodo;

typedef struct Lista {
    Nodo* cabeza1;
    Nodo* cabeza2;
} Lista;

// Función para inicializar la lista
Lista* inicializarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->cabeza1 = NULL;
    lista->cabeza2 = NULL;
    return lista;
}

// Función para crear un nuevo nodo
Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al final de la lista
void insertarNodo(Lista* lista, int dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    if (lista->cabeza1 == NULL) {
        // La lista está vacía, el nuevo nodo es la cabeza de ambos extremos
        lista->cabeza1 = nuevoNodo;
        lista->cabeza2 = nuevoNodo;
        nuevoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = nuevoNodo;
    } else {
        // La lista no está vacía, se agrega el nodo al final
        Nodo* ultimo = lista->cabeza2;
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;
        nuevoNodo->siguiente = lista->cabeza1;
        lista->cabeza1->anterior = nuevoNodo;
        lista->cabeza2 = nuevoNodo;
    }
}

// Función para imprimir la lista en orden
void imprimirLista(Lista* lista) {
    if (lista->cabeza1 == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    Nodo* actual = lista->cabeza1;
    do {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    } while (actual != lista->cabeza1);
    printf("\n");
}

// Función para liberar la memoria de la lista
void liberarLista(Lista* lista) {
    if (lista->cabeza1 == NULL) {
        free(lista);
        return;
    }

    Nodo* actual = lista->cabeza1;
    Nodo* siguienteNodo;
    do {
        siguienteNodo = actual->siguiente;
        free(actual);
        actual = siguienteNodo;
    } while (actual != lista->cabeza1);

    free(lista);
}

int main() {
    Lista* lista = inicializarLista();

    insertarNodo(lista, 1);
    insertarNodo(lista, 2);
    insertarNodo(lista, 3);

    printf("Elementos de la lista: ");
    imprimirLista(lista);

    liberarLista(lista);

    return 0;
}