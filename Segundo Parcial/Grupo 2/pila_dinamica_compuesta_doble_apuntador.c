// Pila Dinámica de dato compuesto sin nodo de cabecera (apuntador doble), con enlace simple entre nodos.
//
// Este archivo contiene la implementación de una pila dinámica que almacena datos compuestos
// sin necesidad de un nodo de cabecera. La pila utiliza un apuntador doble para enlazar los nodos,
// pero el enlace entre nodos es simple, es decir, cada nodo apunta solo a su siguiente nodo en la pila.
//
// Estructura del nodo:
// - dato: el dato compuesto que almacena el nodo.
// - siguiente: un puntero al siguiente nodo en la pila.
//
// Operaciones soportadas:
// - inicializar_pila: inicializa una nueva pila vacía.
// - apilar: agrega un nuevo nodo con el dato compuesto dado a la cima de la pila.
// - desapilar: elimina el nodo en la cima de la pila y devuelve su dato compuesto.
// - pila_vacia: verifica si la pila está vacía.
// - destruir_pila: libera la memoria ocupada por la pila.
//
// Nota: Se debe tener cuidado con la gestión de memoria para evitar fugas de memoria.
//       Asegúrese de destruir la pila una vez que ya no se necesite.

#ifndef PILA_DINAMICA_H
#define PILA_DINAMICA_H

typedef struct Nodo {
    void* dato;
    struct Nodo* siguiente;
} Nodo;

typedef struct Pila {
    Nodo* cima;
} Pila;

// Inicializa una nueva pila vacía.
void inicializar_pila(Pila* pila);

// Agrega un nuevo nodo con el dato compuesto dado a la cima de la pila.
void apilar(Pila* pila, void* dato);

// Elimina el nodo en la cima de la pila y devuelve su dato compuesto.
void* desapilar(Pila* pila);

// Verifica si la pila está vacía.
int pila_vacia(Pila* pila);

// Libera la memoria ocupada por la pila.
void destruir_pila(Pila* pila);

#endif // PILA_DINAMICA_H