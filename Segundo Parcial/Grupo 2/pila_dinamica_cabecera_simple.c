// Pila Dinámica de enteros con nodo de cabecera (apuntador simple), con enlace simple entre nodos.

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* cabeza;
} Pila;

// Función para inicializar la pila
void inicializarPila(Pila* pila) {
    pila->cabeza = NULL;
}

// Función para verificar si la pila está vacía
int esPilaVacia(Pila* pila) {
    return pila->cabeza == NULL;
}

// Función para apilar un elemento
void apilar(Pila* pila, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = pila->cabeza;
    pila->cabeza = nuevoNodo;
}

// Función para desapilar un elemento
int desapilar(Pila* pila) {
    if (esPilaVacia(pila)) {
        printf("Pila vacía. No se puede desapilar.\n");
        return -1; // O algún otro valor que indique error
    }
    Nodo* nodoAEliminar = pila->cabeza;
    int dato = nodoAEliminar->dato;
    pila->cabeza = nodoAEliminar->siguiente;
    free(nodoAEliminar);
    return dato;
}

// Función para obtener el elemento en la cima de la pila sin desapilarlo
int cimaPila(Pila* pila) {
    if (esPilaVacia(pila)) {
        printf("Pila vacía. No hay elemento en la cima.\n");
        return -1; // O algún otro valor que indique error
    }
    return pila->cabeza->dato;
}

// Función para liberar la memoria de la pila
void liberarPila(Pila* pila) {
    while (!esPilaVacia(pila)) {
        desapilar(pila);
    }
}