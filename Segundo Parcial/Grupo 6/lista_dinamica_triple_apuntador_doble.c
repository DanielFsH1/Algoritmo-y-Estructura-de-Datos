// Lista Dinámica de enteros sin nodos de cabecera con 1 apuntador de referencia (triple apuntador), con enlace doble entre nodos.

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
} Nodo;

// Definición de la lista
typedef struct {
    Nodo* cabeza;
    Nodo* cola;
    Nodo** referencia;
} Lista;

// Función para inicializar la lista
void inicializarLista(Lista* lista) {
    lista->cabeza = NULL;
    lista->cola = NULL;
    lista->referencia = &(lista->cabeza);
}

// Función para agregar un nodo al final de la lista
void agregarNodo(Lista* lista, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = lista->cola;

    if (lista->cabeza == NULL) {
        lista->cabeza = nuevoNodo;
    } else {
        lista->cola->siguiente = nuevoNodo;
    }

    lista->cola = nuevoNodo;
}

// Función para imprimir la lista en orden
void imprimirLista(Lista* lista) {
    Nodo* actual = lista->cabeza;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Función para liberar la memoria de la lista
void liberarLista(Lista* lista) {
    Nodo* actual = lista->cabeza;
    Nodo* siguienteNodo;

    while (actual != NULL) {
        siguienteNodo = actual->siguiente;
        free(actual);
        actual = siguienteNodo;
    }

    lista->cabeza = NULL;
    lista->cola = NULL;
}

// Ejemplo de uso
int main() {
    Lista lista;
    inicializarLista(&lista);

    agregarNodo(&lista, 1);
    agregarNodo(&lista, 2);
    agregarNodo(&lista, 3);

    printf("Elementos de la lista: ");
    imprimirLista(&lista);

    liberarLista(&lista);

    return 0;
}