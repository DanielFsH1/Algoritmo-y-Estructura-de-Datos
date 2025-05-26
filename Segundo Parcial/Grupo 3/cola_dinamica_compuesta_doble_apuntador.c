// Cola Dinámica de dato compuesto sin nodo de cabecera (apuntador doble), con enlace simple entre nodos.
//
// Este archivo contiene la implementación de una cola dinámica que almacena datos compuestos
// sin necesidad de un nodo de cabecera. Utiliza un apuntador doble para enlazar los nodos,
// pero el enlace entre nodos es simple.
//
// Estructura del nodo:
// - Un campo para almacenar el dato compuesto.
// - Un apuntador al siguiente nodo en la cola.
// - Un apuntador al nodo anterior en la cola (apuntador doble).
//
// Operaciones soportadas:
// - Inicialización de la cola.
// - Verificación de si la cola está vacía.
// - Inserción de un nuevo elemento al final de la cola.
// - Eliminación del elemento al frente de la cola.
// - Liberación de toda la memoria utilizada por la cola.
//
// Notas:
// - Se debe tener cuidado con la gestión de memoria para evitar fugas.
// - Esta implementación no es segura para entornos multihilo sin un adecuado control de concurrencia.
//
// Definición de la estructura del nodo
typedef struct Nodo {
    void* dato;                  // Dato compuesto
    struct Nodo* siguiente;      // Apuntador al siguiente nodo
    struct Nodo* anterior;       // Apuntador al nodo anterior
} Nodo;

// Definición de la estructura de la cola
typedef struct Cola {
    Nodo* frente;                // Nodo al frente de la cola
    Nodo* fondo;                 // Nodo al fondo de la cola
} Cola;

// Funciones de la cola
Cola* inicializarCola();
int estaVacia(Cola* cola);
void encolar(Cola* cola, void* dato);
void* desencolar(Cola* cola);
void liberarCola(Cola* cola);