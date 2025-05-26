// Lista Dinámica Circular de dato compuesto con 2 nodos de cabecera (2 apuntadores de referencia), con enlace doble entre nodos.
//
// Este archivo contiene la definición y las funciones básicas para manejar una lista
// dinámica circular que utiliza dos nodos de cabecera. Cada nodo en la lista contiene
// un enlace doble que permite la navegación en ambas direcciones.
//
// Estructura del nodo:
// - anterior: un puntero al nodo anterior en la lista.
// - siguiente: un puntero al siguiente nodo en la lista.
// - dato: el dato compuesto que almacena el nodo.
//
// Operaciones soportadas:
// - Inicialización de la lista.
// - Inserción de nodos.
// - Eliminación de nodos.
// - Búsqueda de nodos.
// - Liberación de memoria utilizada por la lista.
//
// Notas:
// - La lista se considera vacía si el nodo cabecera siguiente apunta al nodo cabecera
//   anterior, es decir, si no contiene nodos adicionales.
// - Todas las operaciones que modifican la lista (inserción, eliminación) deben
//   actualizar los punteros de los nodos adyacentes para mantener la integridad
//   de la lista.
//
// Posibles mejoras futuras:
// - Implementar funciones adicionales para operaciones avanzadas en la lista.
// - Añadir manejo de errores y condiciones especiales (por ejemplo, lista vacía,
//   nodo no encontrado, etc.).

#ifndef LISTA_DINAMICA_CIRCULAR_H
#define LISTA_DINAMICA_CIRCULAR_H

typedef struct Nodo {
    struct Nodo* anterior;
    struct Nodo* siguiente;
    void* dato;
} Nodo;

typedef struct {
    Nodo* cabecera;
} Lista;

// Funciones de la lista
void inicializarLista(Lista* lista);
void insertarNodo(Lista* lista, void* dato);
void eliminarNodo(Lista* lista, void* dato);
Nodo* buscarNodo(Lista* lista, void* dato);
void liberarLista(Lista* lista);

#endif // LISTA_DINAMICA_CIRCULAR_H