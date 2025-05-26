// Lista Dinámica Circular de enteros sin nodos de cabecera con 2 apuntadores de referencia (triple apuntador), con enlace doble entre nodos.
//
// Este archivo contiene la definición y las funciones básicas para manejar una lista
// dinámica circular de enteros. La lista no tiene nodos de cabecera y utiliza un sistema
// de triple apuntador para facilitar las operaciones de inserción y eliminación.
//
// Estructura del nodo:
// - int dato: El dato entero almacenado en el nodo.
// - Nodo* siguiente: Un puntero al siguiente nodo en la lista.
// - Nodo* anterior: Un puntero al nodo anterior en la lista.
//
// Estructura de la lista:
// - Nodo* cabeza: Un puntero al primer nodo de la lista.
// - Nodo* cola: Un puntero al último nodo de la lista.
// - int tamaño: El número de nodos en la lista.
//
// Funciones principales:
// - inicializar_lista: Inicializa una lista vacía.
// - insertar_inicio: Inserta un nuevo nodo al inicio de la lista.
// - insertar_fin: Inserta un nuevo nodo al final de la lista.
// - eliminar_inicio: Elimina el nodo al inicio de la lista.
// - eliminar_fin: Elimina el nodo al final de la lista.
// - es_vacia: Verifica si la lista está vacía.
// - obtener_tamaño: Retorna el tamaño actual de la lista.
//
// Definición de la estructura del nodo
typedef struct nodo {
    int dato;
    struct nodo* siguiente;
    struct nodo* anterior;
} Nodo;

// Definición de la estructura de la lista
typedef struct {
    Nodo* cabeza;
    Nodo* cola;
    int tamaño;
} Lista;

// Prototipos de las funciones
void inicializar_lista(Lista* lista);
void insertar_inicio(Lista* lista, int dato);
void insertar_fin(Lista* lista, int dato);
void eliminar_inicio(Lista* lista);
void eliminar_fin(Lista* lista);
int es_vacia(Lista* lista);
int obtener_tamaño(Lista* lista);