// Lista Dinámica Circular de dato compuesto sin nodos de cabecera con 2 apuntadores de referencia (doble apuntador), con enlace doble entre nodos.
//
// Estructura de un nodo
// Cada nodo contendrá un dato de tipo compuesto y tendrá dos punteros:
// 1. Un puntero al nodo siguiente en la lista.
// 2. Un puntero al nodo anterior en la lista.
//
// Definición de la estructura del nodo
typedef struct Nodo {
    TipoCompuesto dato;          // El dato de tipo compuesto
    struct Nodo* siguiente;      // Puntero al siguiente nodo
    struct Nodo* anterior;       // Puntero al nodo anterior
} Nodo;
//
// Definición de la lista
typedef struct {
    Nodo* primero;              // Puntero al primer nodo de la lista
    Nodo* ultimo;               // Puntero al último nodo de la lista
} Lista;
//
// Funciones de la lista
//
// 1. Inicializar la lista
// 2. Insertar un elemento
// 3. Eliminar un elemento
// 4. Buscar un elemento
// 5. Mostrar la lista
// 6. Liberar memoria de la lista
//
// Prototipos de funciones
void inicializarLista(Lista* lista);
void insertarElemento(Lista* lista, TipoCompuesto dato);
void eliminarElemento(Lista* lista, TipoCompuesto dato);
Nodo* buscarElemento(Lista* lista, TipoCompuesto dato);
void mostrarLista(Lista* lista);
void liberarLista(Lista* lista);