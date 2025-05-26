// Cola Dinámica Circular de enteros sin nodos de cabecera con 2 apuntadores de referencia (doble apuntador), con enlace doble entre nodos.
//
// Estructura de un nodo:
typedef struct nodo {
    int dato;
    struct nodo * siguiente;
    struct nodo * anterior;
} Nodo;
//
// Estructura de la cola:
typedef struct {
    Nodo * frente;
    Nodo * fondo;
} Cola;
//
// Función para inicializar la cola:
void inicializarCola(Cola * cola) {
    cola->frente = NULL;
    cola->fondo = NULL;
}
//
// Función para verificar si la cola está vacía:
int estaVacia(Cola * cola) {
    return (cola->frente == NULL);
}
//
// Función para agregar un elemento a la cola:
void encolar(Cola * cola, int valor) {
    Nodo * nuevoNodo = (Nodo * ) malloc( sizeof(Nodo));
    nuevoNodo->dato = valor;
//
// Si la cola está vacía, el nuevo nodo será tanto el frente como el fondo de la cola:
    if (estaVacia(cola)) {
        nuevoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = nuevoNodo;
        cola->frente = nuevoNodo;
        cola->fondo = nuevoNodo;
    } else {
// Si la cola no está vacía, se ajustan los punteros para insertar el nuevo nodo al final:
        nuevoNodo->siguiente = cola->frente;
        nuevoNodo->anterior = cola->fondo;
        cola->fondo->siguiente = nuevoNodo;
        cola->frente->anterior = nuevoNodo;
        cola->fondo = nuevoNodo;
    }
}
//
// Función para quitar un elemento de la cola (del frente):
int desencolar(Cola * cola) {
    int valor;
    Nodo * nodoARemover;
//
// Si la cola está vacía, no se puede desencolar ningún elemento:
    if (estaVacia(cola)) {
        printf("La cola está vacía. No se puede desencolar ningún elemento.\n");
        return -1;
    }
//
// Si la cola tiene un solo nodo, se elimina ese nodo y la cola queda vacía:
    nodoARemover = cola->frente;
    valor = nodoARemover->dato;
    if (cola->frente == cola->fondo) {
        cola->frente = NULL;
        cola->fondo = NULL;
    } else {
        cola->frente->anterior = cola->fondo;
        cola->fondo->siguiente = cola->frente;
        cola->frente = cola->frente->siguiente;
    }
    free(nodoARemover);
    return valor;
}
//
// Función para ver el elemento en el frente de la cola (sin quitarlo):
int verFrente(Cola * cola) {
    if (estaVacia(cola)) {
        printf("La cola está vacía.\n");
        return -1;
    }
    return cola->frente->dato;
}
//
// Función para ver el elemento en el fondo de la cola (sin quitarlo):
int verFondo(Cola * cola) {
    if (estaVacia(cola)) {
        printf("La cola está vacía.\n");
        return -1;
    }
    return cola->fondo->dato;
}