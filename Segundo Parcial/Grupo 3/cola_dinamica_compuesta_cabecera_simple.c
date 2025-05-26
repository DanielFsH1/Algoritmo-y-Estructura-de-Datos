// Cola Dinámica de dato compuesto con nodo de cabecera (apuntador simple), con enlace simple entre nodos.
//
// Estructura de Datos - 2023
// Universidad de la República Oriental del Uruguay
//
// Implementación de una cola dinámica para almacenar datos compuestos. La cola
// se implementa utilizando una lista enlazada simple, donde cada nodo de la lista
// contiene un dato y un puntero al siguiente nodo. La cola tiene un nodo de
// cabecera que actúa como un marcador para el inicio de la cola.
//
// Operaciones soportadas:
// - Inicializar la cola.
// - Verificar si la cola está vacía.
// - Insertar un elemento en la cola.
// - Eliminar un elemento de la cola.
// - Obtener el elemento en el frente de la cola sin eliminarlo.
// - Liberar la memoria utilizada por la cola.
//
// Definición de la estructura de un nodo de la lista:
typedef struct Nodo {
    void* dato;                // Puntero genérico al dato almacenado en el nodo.
    struct Nodo* siguiente;    // Puntero al siguiente nodo en la lista.
} Nodo;

// Definición de la estructura de la cola:
typedef struct {
    Nodo* cabeza;             // Puntero al nodo cabeza de la lista.
    Nodo* fin;                // Puntero al último nodo de la lista.
} Cola;

// Funciones de la cola:
// Cola* crearCola();
// int esColaVacia(Cola* cola);
// void encolar(Cola* cola, void* dato);
// void* desencolar(Cola* cola);
// void* frenteCola(Cola* cola);
// void liberarCola(Cola* cola);