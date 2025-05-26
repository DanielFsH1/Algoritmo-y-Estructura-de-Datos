// Cola Dinámica de enteros con 2 nodos de cabecera (2 apuntadores de referencia), con enlace doble entre nodos.

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
} Nodo;

typedef struct Cola {
    Nodo* cabeza1;
    Nodo* cabeza2;
} Cola;

// Función para inicializar la cola
void inicializarCola(Cola* cola) {
    cola->cabeza1 = NULL;
    cola->cabeza2 = NULL;
}

// Función para verificar si la cola está vacía
int estaVacia(Cola* cola) {
    return (cola->cabeza1 == NULL && cola->cabeza2 == NULL);
}

// Función para agregar un elemento a la cola
void encolar(Cola* cola, int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = cola->cabeza2;

    if (estaVacia(cola)) {
        cola->cabeza1 = nuevoNodo;
        cola->cabeza2 = nuevoNodo;
    } else {
        cola->cabeza2->siguiente = nuevoNodo;
        cola->cabeza2 = nuevoNodo;
    }
}

// Función para eliminar un elemento de la cola
int desencolar(Cola* cola) {
    if (estaVacia(cola)) {
        printf("La cola está vacía. No se puede desencolar.\n");
        return -1;
    }

    Nodo* nodoAEliminar = cola->cabeza1;
    int valor = nodoAEliminar->dato;

    cola->cabeza1 = cola->cabeza1->siguiente;

    if (cola->cabeza1 != NULL) {
        cola->cabeza1->anterior = NULL;
    } else {
        cola->cabeza2 = NULL;
    }

    free(nodoAEliminar);
    return valor;
}

// Función para liberar la memoria de la cola
void liberarCola(Cola* cola) {
    while (!estaVacia(cola)) {
        desencolar(cola);
    }
}