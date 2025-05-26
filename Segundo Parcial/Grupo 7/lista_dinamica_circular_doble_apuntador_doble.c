// Lista Dinámica Circular de enteros sin nodos de cabecera con 2 apuntadores de referencia (doble apuntador), con enlace doble entre nodos.

// Estructura del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
} Nodo;

// Estructura de la lista
typedef struct {
    Nodo* cabeza;
    Nodo* cola;
} ListaCircular;

// Función para inicializar la lista
void inicializarLista(ListaCircular* lista) {
    lista->cabeza = NULL;
    lista->cola = NULL;
}

// Función para verificar si la lista está vacía
int listaVacia(ListaCircular* lista) {
    return lista->cabeza == NULL;
}

// Función para agregar un nodo al final de la lista
void agregarNodo(ListaCircular* lista, int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = valor;

    if (listaVacia(lista)) {
        nuevoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = nuevoNodo;
        lista->cabeza = nuevoNodo;
        lista->cola = nuevoNodo;
    } else {
        nuevoNodo->siguiente = lista->cabeza;
        nuevoNodo->anterior = lista->cola;
        lista->cola->siguiente = nuevoNodo;
        lista->cabeza->anterior = nuevoNodo;
        lista->cola = nuevoNodo;
    }
}

// Función para eliminar un nodo de la lista
void eliminarNodo(ListaCircular* lista, Nodo* nodo) {
    if (!listaVacia(lista)) {
        if (lista->cabeza == nodo && lista->cola == nodo) {
            lista->cabeza = NULL;
            lista->cola = NULL;
        } else {
            nodo->anterior->siguiente = nodo->siguiente;
            nodo->siguiente->anterior = nodo->anterior;
            if (lista->cabeza == nodo) {
                lista->cabeza = nodo->siguiente;
            }
            if (lista->cola == nodo) {
                lista->cola = nodo->anterior;
            }
        }
        free(nodo);
    }
}

// Función para liberar la memoria de la lista
void liberarLista(ListaCircular* lista) {
    if (!listaVacia(lista)) {
        Nodo* actual = lista->cabeza;
        Nodo* siguienteNodo;
        do {
            siguienteNodo = actual->siguiente;
            free(actual);
            actual = siguienteNodo;
        } while (actual != lista->cabeza);
        lista->cabeza = NULL;
        lista->cola = NULL;
    }
}