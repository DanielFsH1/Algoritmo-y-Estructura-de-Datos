// Lista Dinámica de dato compuesto sin nodos de cabecera con 2 apuntadores de referencia (doble apuntador), con enlace doble entre nodos.
//
// Este archivo contiene la definición y las funciones básicas para manejar una lista
// dinámica enlazada de datos compuestos. La lista no tiene un nodo cabecera y cada nodo
// contiene un apuntador al siguiente y al anterior nodo en la lista.
//
// Estructura del nodo:
// - Un campo para el dato compuesto.
// - Un apuntador al siguiente nodo.
// - Un apuntador al nodo anterior.
//
// Operaciones soportadas:
// - Inicialización de la lista.
// - Inserción de nodos.
// - Eliminación de nodos.
// - Búsqueda de nodos.
// - Liberación de memoria utilizada por la lista.
//
// Definición de la estructura del nodo
typedef struct Nodo {
    struct Nodo* siguiente;
    struct Nodo* anterior;
    // Aquí se pueden agregar los campos del dato compuesto
} Nodo;

// Definición de la estructura de la lista
typedef struct {
    Nodo* cabeza;
    Nodo* cola;
} Lista;

// Funciones para manejar la lista
void inicializarLista(Lista* lista);
void insertarNodo(Lista* lista, /* parámetros para el dato compuesto */);
void eliminarNodo(Lista* lista, Nodo* nodo);
Nodo* buscarNodo(Lista* lista, /* criterios de búsqueda */);
void liberarLista(Lista* lista);