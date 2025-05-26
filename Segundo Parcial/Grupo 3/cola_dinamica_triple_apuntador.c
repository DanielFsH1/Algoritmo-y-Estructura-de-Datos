// Cola Dinámica de enteros sin nodo de cabecera (triple apuntador), con enlace simple entre nodos.

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* frente;
    Nodo* fondo;
} Cola;

void inicializarCola(Cola* cola) {
    cola->frente = NULL;
    cola->fondo = NULL;
}

int estaVacia(Cola* cola) {
    return cola->frente == NULL;
}

void encolar(Cola* cola, int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;

    if (estaVacia(cola)) {
        cola->frente = nuevoNodo;
    } else {
        cola->fondo->siguiente = nuevoNodo;
    }

    cola->fondo = nuevoNodo;
}

int desencolar(Cola* cola) {
    if (estaVacia(cola)) {
        printf("La cola esta vacia\n");
        return -1;
    }

    Nodo* nodoAEliminar = cola->frente;
    int dato = nodoAEliminar->dato;
    cola->frente = cola->frente->siguiente;

    if (cola->frente == NULL) {
        cola->fondo = NULL;
    }

    free(nodoAEliminar);
    return dato;
}

void liberarCola(Cola* cola) {
    while (!estaVacia(cola)) {
        desencolar(cola);
    }
}

int main() {
    Cola cola;
    inicializarCola(&cola);

    encolar(&cola, 10);
    encolar(&cola, 20);
    encolar(&cola, 30);

    printf("Desencolando: %d\n", desencolar(&cola));
    printf("Desencolando: %d\n", desencolar(&cola));
    printf("Desencolando: %d\n", desencolar(&cola));
    printf("Desencolando: %d\n", desencolar(&cola)); // Intento de desencolar en cola vacía

    liberarCola(&cola);
    return 0;
}