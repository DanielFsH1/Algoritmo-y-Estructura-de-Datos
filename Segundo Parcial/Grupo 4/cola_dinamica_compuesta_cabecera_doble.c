// Cola Dinámica de dato compuesto con 2 nodos de cabecera (2 apuntadores de referencia), con enlace doble entre nodos.
//
// Este archivo contiene la definición y las funciones básicas para manejar una cola dinámica.
// La cola se implementa utilizando una lista doblemente enlazada, donde cada nodo de la lista contiene
// un dato y punteros hacia el nodo anterior y el siguiente. Además, la cola tiene dos nodos de cabecera
// que sirven como puntos de referencia para el inicio y el fin de la cola.
//
// Estructura del nodo:
// - dato: el dato almacenado en el nodo.
// - anterior: un puntero al nodo anterior en la cola.
// - siguiente: un puntero al siguiente nodo en la cola.
//
// Operaciones soportadas:
// - inicializar_cola: Inicializa la cola, creando los nodos de cabecera.
// - encolar: Agrega un nuevo dato a la cola.
// - desencolar: Elimina un dato de la cola.
// - cola_vacia: Verifica si la cola está vacía.
// - destruir_cola: Destruye la cola, liberando toda la memoria utilizada.
//
// Definición de la estructura del nodo
typedef struct Nodo {
    struct Nodo* anterior;
    struct Nodo* siguiente;
    void* dato;
} Nodo;

// Definición de la estructura de la cola
typedef struct Cola {
    Nodo* cabeza_inicio;
    Nodo* cabeza_fin;
} Cola;

// Función para inicializar la cola
void inicializar_cola(Cola* cola);

// Función para encolar un nuevo dato
void encolar(Cola* cola, void* dato);

// Función para desencolar un dato
void* desencolar(Cola* cola);

// Función para verificar si la cola está vacía
int cola_vacia(Cola* cola);

// Función para destruir la cola
void destruir_cola(Cola* cola);