// Lista Dinámica Circular de enteros sin nodos de cabecera con 2 apuntadores de referencia (triple apuntador), con enlace doble entre nodos
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    int dato;
    struct Nodo *sig;
    struct Nodo *ant;
} Nodo;

typedef struct {
    Nodo *inicio;
    Nodo *final;
    Nodo **pmedio;
} Lista;

Nodo* crear_nodo(int dato) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo) {
        nuevo->dato = dato;
        nuevo->sig = nuevo->ant = NULL;
    }
    return nuevo;
}

void inicializar_lista(Lista *lista) {
    lista->inicio = lista->final = NULL;
    lista->pmedio = NULL;
}

bool lista_vacia(Lista *lista) {
    return lista->inicio == NULL;
}

void meter_dato(Lista *lista, int dato) {
    Nodo *nuevo = crear_nodo(dato);
    if (!nuevo) return;
    if (lista_vacia(lista)) {
        lista->inicio = lista->final = nuevo;
        lista->pmedio = &lista->inicio;
        nuevo->sig = nuevo->ant = nuevo;
    } else {
        nuevo->sig = lista->inicio;
        nuevo->ant = lista->final;
        lista->final->sig = nuevo;
        lista->inicio->ant = nuevo;
        lista->final = nuevo;
    }
}

bool sacar_dato(Lista *lista, int *dato) {
    if (lista_vacia(lista)) return false;
    Nodo *primero = lista->inicio;
    *dato = primero->dato;
    if (lista->inicio == lista->final) {
        lista->inicio = lista->final = NULL;
    } else {
        lista->inicio = primero->sig;
        lista->final->sig = lista->inicio;
        lista->inicio->ant = lista->final;
    }
    free(primero);
    return true;
}

void mostrar_lista(Lista *lista) {
    if (lista_vacia(lista)) {
        printf("Lista vacía\n");
        return;
    }
    Nodo *aux = lista->inicio;
    printf("Lista: ");
    do {
        printf("%d ", aux->dato);
        aux = aux->sig;
    } while (aux != lista->inicio);
    printf("\n");
}

void liberar_lista(Lista *lista) {
    if (lista_vacia(lista)) return;
    Nodo *aux = lista->inicio;
    do {
        Nodo *tmp = aux;
        aux = aux->sig;
        free(tmp);
    } while (aux != lista->inicio);
    lista->inicio = lista->final = NULL;
    lista->pmedio = NULL;
}

int main() {
    Lista lista;
    inicializar_lista(&lista);
    int opcion, dato;
    do {
        printf("\n1. Meter dato\n2. Sacar dato\n3. Mostrar lista\n4. Salir\nOpcion: ");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
                printf("Dato a meter: ");
                scanf("%d", &dato);
                meter_dato(&lista, dato);
                break;
            case 2:
                if (sacar_dato(&lista, &dato))
                    printf("Dato sacado: %d\n", dato);
                else
                    printf("Lista vacía\n");
                break;
            case 3:
                mostrar_lista(&lista);
                break;
        }
    } while(opcion != 4);
    liberar_lista(&lista);
    return 0;
}
