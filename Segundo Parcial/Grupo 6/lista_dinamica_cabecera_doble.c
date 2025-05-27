// Lista Dinámica de enteros con 1 nodo de cabecera (2 apuntadores de referencia), con enlace doble entre nodos
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    int dato;
    struct Nodo *sig;
    struct Nodo *ant;
} Nodo;

typedef struct {
    Nodo *cabecera;
    Nodo *final;
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
    lista->cabecera = (Nodo*)malloc(sizeof(Nodo));
    lista->cabecera->sig = lista->cabecera->ant = lista->cabecera;
    lista->final = lista->cabecera;
}

bool lista_vacia(Lista *lista) {
    return lista->cabecera->sig == lista->cabecera;
}

void meter_dato(Lista *lista, int dato) {
    Nodo *nuevo = crear_nodo(dato);
    if (!nuevo) return;
    nuevo->sig = lista->cabecera;
    nuevo->ant = lista->final;
    lista->final->sig = nuevo;
    lista->cabecera->ant = nuevo;
    lista->final = nuevo;
}

bool sacar_dato(Lista *lista, int *dato) {
    if (lista_vacia(lista)) return false;
    Nodo *primero = lista->cabecera->sig;
    *dato = primero->dato;
    lista->cabecera->sig = primero->sig;
    primero->sig->ant = lista->cabecera;
    if (primero == lista->final) lista->final = lista->cabecera;
    free(primero);
    return true;
}

void mostrar_lista(Lista *lista) {
    Nodo *aux = lista->cabecera->sig;
    printf("Lista: ");
    while (aux != lista->cabecera) {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}

void liberar_lista(Lista *lista) {
    Nodo *aux = lista->cabecera->sig;
    while (aux != lista->cabecera) {
        Nodo *tmp = aux;
        aux = aux->sig;
        free(tmp);
    }
    free(lista->cabecera);
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
