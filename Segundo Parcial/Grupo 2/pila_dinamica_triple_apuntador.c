// Pila Dinámica de enteros sin nodo de cabecera (triple apuntador), con enlace simple entre nodos.

// Definición de la estructura del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Definición de la estructura de la pila
typedef struct {
    Nodo* cima;
} Pila;

// Función para inicializar la pila
void inicializarPila(Pila* pila) {
    pila->cima = NULL;
}

// Función para verificar si la pila está vacía
int estaVacia(Pila* pila) {
    return pila->cima == NULL;
}

// Función para apilar un elemento
void apilar(Pila* pila, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = pila->cima;
    pila->cima = nuevoNodo;
}

// Función para desapilar un elemento
int desapilar(Pila* pila) {
    if (estaVacia(pila)) {
        printf("Pila vacía. No se puede desapilar.\n");
        return -1; // O algún otro valor que indique error
    }
    Nodo* nodoDesapilado = pila->cima;
    int dato = nodoDesapilado->dato;
    pila->cima = pila->cima->siguiente;
    free(nodoDesapilado);
    return dato;
}

// Función para obtener el elemento en la cima de la pila sin desapilarlo
int cimaPila(Pila* pila) {
    if (estaVacia(pila)) {
        printf("Pila vacía.\n");
        return -1; // O algún otro valor que indique error
    }
    return pila->cima->dato;
}