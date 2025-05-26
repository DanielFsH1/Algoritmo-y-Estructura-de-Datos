// Cola Dinámica Circular de dato compuesto sin nodos de cabecera con 2 apuntadores de referencia (triple apuntador), con enlace doble entre nodos.
//
// Estructura de un nodo:
typedef struct Nodo {
    struct Nodo* siguiente; // Apuntador al siguiente nodo
    struct Nodo* anterior;  // Apuntador al nodo anterior
    TipoDato dato;         // El dato que almacena el nodo
} Nodo;

// Estructura de la cola:
typedef struct {
    Nodo* frente;          // Apuntador al frente de la cola
    Nodo* fondo;          // Apuntador al fondo de la cola
} Cola;

// Funciones de la cola:
void inicializarCola(Cola* cola);
int estaVacia(Cola* cola);
void encolar(Cola* cola, TipoDato dato);
TipoDato desencolar(Cola* cola);
TipoDato verFrente(Cola* cola);
TipoDato verFondo(Cola* cola);
void destruirCola(Cola* cola);