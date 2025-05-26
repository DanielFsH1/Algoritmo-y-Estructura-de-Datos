// Pila Dinámica de enteros programado solo en main.

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Definición de la estructura de la pila
struct Pila {
    struct Nodo* cima;
};

// Función para crear una pila vacía
struct Pila* crearPila() {
    struct Pila* nuevaPila = (struct Pila*)malloc(sizeof(struct Pila));
    nuevaPila->cima = NULL;
    return nuevaPila;
}

// Función para verificar si la pila está vacía
int esVacia(struct Pila* pila) {
    return pila->cima == NULL;
}

// Función para apilar un elemento
void apilar(struct Pila* pila, int elemento) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = elemento;
    nuevoNodo->siguiente = pila->cima;
    pila->cima = nuevoNodo;
    printf("Elemento %d apilado.\n", elemento);
}

// Función para desapilar un elemento
int desapilar(struct Pila* pila) {
    if (esVacia(pila)) {
        printf("La pila está vacía. No se puede desapilar.\n");
        return -1; // Indicador de error
    }
    int elemento = pila->cima->dato;
    struct Nodo* nodoAEliminar = pila->cima;
    pila->cima = pila->cima->siguiente;
    free(nodoAEliminar);
    printf("Elemento %d desapilado.\n", elemento);
    return elemento;
}

// Función para obtener el elemento en la cima de la pila sin desapilarlo
int cima(struct Pila* pila) {
    if (esVacia(pila)) {
        printf("La pila está vacía.\n");
        return -1; // Indicador de error
    }
    return pila->cima->dato;
}

// Función para liberar la memoria de la pila
void liberarPila(struct Pila* pila) {
    while (!esVacia(pila)) {
        desapilar(pila);
    }
    free(pila);
    printf("Pila liberada.\n");
}

// Función principal para probar la pila dinámica
int main() {
    struct Pila* miPila = crearPila();

    apilar(miPila, 10);
    apilar(miPila, 20);
    apilar(miPila, 30);

    printf("Elemento en la cima: %d\n", cima(miPila));

    desapilar(miPila);

    printf("Elemento en la cima después de desapilar: %d\n", cima(miPila));

    liberarPila(miPila);

    return 0;
}