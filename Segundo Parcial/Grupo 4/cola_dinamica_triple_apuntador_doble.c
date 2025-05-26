// Cola Dinámica de enteros sin nodos de cabecera con 2 apuntadores de referencia (triple apuntador), con enlace doble entre nodos.

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
} Nodo;

typedef struct {
    Nodo* cabeza;
    Nodo* cola;
    int tamaño;
} ColaDinamica;

void inicializarCola(ColaDinamica* cola) {
    cola->cabeza = NULL;
    cola->cola = NULL;
    cola->tamaño = 0;
}

int estaVacia(ColaDinamica* cola) {
    return cola->tamaño == 0;
}

void encolar(ColaDinamica* cola, int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = cola->cola;

    if (estaVacia(cola)) {
        cola->cabeza = nuevoNodo;
    } else {
        cola->cola->siguiente = nuevoNodo;
    }

    cola->cola = nuevoNodo;
    cola->tamaño++;
}

int desencolar(ColaDinamica* cola) {
    if (estaVacia(cola)) {
        printf("La cola está vacía. No se puede desencolar.\n");
        return -1; // Valor de error
    }

    Nodo* nodoAEliminar = cola->cabeza;
    int valor = nodoAEliminar->dato;

    cola->cabeza = cola->cabeza->siguiente;

    if (cola->cabeza != NULL) {
        cola->cabeza->anterior = NULL;
    } else {
        cola->cola = NULL;
    }

    free(nodoAEliminar);
    cola->tamaño--;

    return valor;
}

void liberarCola(ColaDinamica* cola) {
    while (!estaVacia(cola)) {
        desencolar(cola);
    }
}