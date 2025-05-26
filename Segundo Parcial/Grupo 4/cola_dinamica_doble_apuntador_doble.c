// Cola Dinámica de enteros sin nodo de cabecera con 2 apuntadores de referencia (doble apuntador), con enlace doble entre nodos.

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
} Nodo;

typedef struct {
    Nodo* cabeza;
    Nodo* cola;
} ColaDinamica;

void inicializarCola(ColaDinamica* cola) {
    cola->cabeza = NULL;
    cola->cola = NULL;
}

int estaVacia(ColaDinamica* cola) {
    return cola->cabeza == NULL;
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
}

int desencolar(ColaDinamica* cola) {
    if (estaVacia(cola)) {
        printf("La cola está vacía.\n");
        return -1;
    }

    Nodo* nodoAEliminar = cola->cabeza;
    int dato = nodoAEliminar->dato;

    cola->cabeza = cola->cabeza->siguiente;

    if (cola->cabeza != NULL) {
        cola->cabeza->anterior = NULL;
    } else {
        cola->cola = NULL;
    }

    free(nodoAEliminar);
    return dato;
}

void liberarCola(ColaDinamica* cola) {
    while (!estaVacia(cola)) {
        desencolar(cola);
    }
}