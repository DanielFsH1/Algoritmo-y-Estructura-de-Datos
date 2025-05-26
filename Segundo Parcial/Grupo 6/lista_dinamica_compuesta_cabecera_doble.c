// Lista Dinámica de dato compuesto con 2 nodos de cabecera (1 apuntador de referencia), con enlace doble entre nodos.

#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

typedef struct Nodo {
    struct Nodo* siguiente;
    struct Nodo* anterior;
    void* dato;
} Nodo;

typedef struct {
    Nodo* cabeza1;
    Nodo* cabeza2;
    Nodo* referencia;
} Lista;

void inicializarLista(Lista* lista);
void insertarEnLista(Lista* lista, void* dato);
void eliminarDeLista(Lista* lista, void* dato);
void* buscarEnLista(Lista* lista, void* dato);
void destruirLista(Lista* lista);

#endif // LISTA_DINAMICA_H