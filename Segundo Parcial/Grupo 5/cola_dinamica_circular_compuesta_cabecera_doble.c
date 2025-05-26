// Cola Dinámica Circular de dato compuesto con 2 nodos de cabecera (2 apuntadores de referencia), con enlace doble entre nodos.
//
// Este archivo contiene la definición y las funciones básicas para manejar una cola dinámica circular
// que utiliza una estructura de datos compuesta. La cola tiene dos nodos de cabecera que sirven como
// apuntadores de referencia, y los nodos de la cola están enlazados de forma doble.
//
// Estructura de un nodo de la cola:
// - Un campo de datos que almacena la información.
// - Un puntero al nodo siguiente en la cola.
// - Un puntero al nodo anterior en la cola.
//
// Operaciones básicas:
// - Inicialización de la cola.
// - Comprobación de si la cola está vacía.
// - Inserción de un nuevo elemento en la cola.
// - Eliminación de un elemento de la cola.
// - Liberación de la memoria ocupada por la cola.
//
// Esta implementación asume que el tamaño del dato es conocido y que se dispone de funciones para
// manejar la memoria dinámica (por ejemplo, malloc y free en C).

#ifndef COLA_DINAMICA_CIRCULAR_H
#define COLA_DINAMICA_CIRCULAR_H

// Definición de la estructura de un nodo de la cola.
typedef struct Nodo {
    struct Nodo* siguiente; // Puntero al siguiente nodo en la cola.
    struct Nodo* anterior; // Puntero al nodo anterior en la cola.
    // Aquí se pueden agregar más campos según sea necesario para el dato compuesto.
} Nodo;

// Definición de la estructura de la cola.
typedef struct {
    Nodo* cabeza1; // Primer nodo de cabecera.
    Nodo* cabeza2; // Segundo nodo de cabecera.
} Cola;

// Funciones para manejar la cola dinámica circular.
// void inicializarCola(Cola* cola);
// int estaVacia(Cola* cola);
// void insertar(Cola* cola, /* tipoDato dato */);
// void eliminar(Cola* cola);
// void liberarCola(Cola* cola);

#endif // COLA_DINAMICA_CIRCULAR_H