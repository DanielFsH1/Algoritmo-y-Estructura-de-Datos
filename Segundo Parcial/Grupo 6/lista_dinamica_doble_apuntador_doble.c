// Lista Dinámica de enteros sin nodos de cabecera con 1 apuntador de referencia (doble apuntador), con enlace doble entre nodos.

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
} Nodo;

typedef struct {
    Nodo* cabeza;
    Nodo* cola;
} ListaDinamica;

void inicializarLista(ListaDinamica* lista) {
    lista->cabeza = NULL;
    lista->cola = NULL;
}

int estaVacia(ListaDinamica* lista) {
    return lista->cabeza == NULL;
}

void insertarAlPrincipio(ListaDinamica* lista, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = lista->cabeza;
    nuevoNodo->anterior = NULL;

    if (estaVacia(lista)) {
        lista->cola = nuevoNodo;
    } else {
        lista->cabeza->anterior = nuevoNodo;
    }

    lista->cabeza = nuevoNodo;
}

void insertarAlFinal(ListaDinamica* lista, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = lista->cola;

    if (estaVacia(lista)) {
        lista->cabeza = nuevoNodo;
    } else {
        lista->cola->siguiente = nuevoNodo;
    }

    lista->cola = nuevoNodo;
}

void eliminarDelPrincipio(ListaDinamica* lista) {
    if (!estaVacia(lista)) {
        Nodo* nodoAEliminar = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;

        if (lista->cabeza != NULL) {
            lista->cabeza->anterior = NULL;
        } else {
            lista->cola = NULL;
        }

        free(nodoAEliminar);
    }
}

void eliminarDelFinal(ListaDinamica* lista) {
    if (!estaVacia(lista)) {
        Nodo* nodoAEliminar = lista->cola;
        lista->cola = lista->cola->anterior;

        if (lista->cola != NULL) {
            lista->cola->siguiente = NULL;
        } else {
            lista->cabeza = NULL;
        }

        free(nodoAEliminar);
    }
}

void liberarLista(ListaDinamica* lista) {
    while (!estaVacia(lista)) {
        eliminarDelPrincipio(lista);
    }
}