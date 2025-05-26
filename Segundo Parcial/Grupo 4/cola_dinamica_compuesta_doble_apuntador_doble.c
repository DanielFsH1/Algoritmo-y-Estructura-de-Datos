// Cola Dinámica de dato compuesto sin nodos de cabecera con 2 apuntadores de referencia (doble apuntador), con enlace doble entre nodos.
//
// Estructura de un nodo de la cola
typedef struct Nodo {
    struct Nodo* siguiente; // Apuntador al siguiente nodo en la cola
    struct Nodo* anterior;  // Apuntador al nodo anterior en la cola
    // Aquí se pueden agregar otros campos para almacenar datos
} Nodo;

// Estructura de la cola
typedef struct {
    Nodo* frente; // Apuntador al primer nodo de la cola
    Nodo* fondo;  // Apuntador al último nodo de la cola
} Cola;

// Funciones para manejar la cola
void inicializarCola(Cola* cola);
int estaVacia(Cola* cola);
void encolar(Cola* cola, /* otros parámetros según los datos */);
void desencolar(Cola* cola);
void limpiarCola(Cola* cola);