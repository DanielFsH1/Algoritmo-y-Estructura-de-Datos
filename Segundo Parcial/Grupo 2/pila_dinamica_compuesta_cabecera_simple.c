// Pila Dinámica de dato compuesto con nodo de cabecera (apuntador simple), con enlace simple entre nodos.
//
// Este archivo contiene la implementación de una pila dinámica que utiliza un nodo de cabecera
// para facilitar las operaciones de apilar y desapilar. La pila se implementa mediante una lista
// enlazada simple, donde cada nodo contiene un dato y un puntero al siguiente nodo en la pila.
//
// Estructura del nodo:
// - dato: El dato almacenado en el nodo.
// - siguiente: Un puntero al siguiente nodo en la pila.
//
// Estructura de la pila:
// - cabeza: Un puntero al nodo de cabecera de la pila (inicialmente NULL si la pila está vacía).
//
// Operaciones:
// - crearPila: Crea una pila vacía.
// - apilar: Agrega un nuevo elemento a la cima de la pila.
// - desapilar: Elimina el elemento en la cima de la pila.
// - pilaVacia: Verifica si la pila está vacía.
// - destruirPila: Destruye la pila y libera la memoria utilizada.

#ifndef PILA_DINAMICA_H
#define PILA_DINAMICA_H

typedef struct Nodo {
    void* dato;
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* cabeza;
} Pila;

// Crea una pila vacía.
Pila* crearPila();

// Agrega un nuevo elemento a la cima de la pila.
void apilar(Pila* pila, void* dato);

// Elimina el elemento en la cima de la pila.
void* desapilar(Pila* pila);

// Verifica si la pila está vacía.
int pilaVacia(Pila* pila);

// Destruye la pila y libera la memoria utilizada.
void destruirPila(Pila* pila);

#endif // PILA_DINAMICA_H