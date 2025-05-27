// Cola Dinámica Circular de enteros con 2 nodos de cabecera (2 apuntadores de referencia), con enlace doble entre nodos
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Nodo de la cola
typedef struct Nodo {
    int dato;
    struct Nodo *sig;
    struct Nodo *ant;
} Nodo;

// Cabeceras de la cola
typedef struct {
    Nodo *cabecera1;
    Nodo *cabecera2;
} Cola;

Nodo* crear_nodo(int dato) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo) {
        nuevo->dato = dato;
        nuevo->sig = nuevo->ant = NULL;
    }
    return nuevo;
}

void inicializar_cola(Cola *cola) {
    cola->cabecera1 = (Nodo*)malloc(sizeof(Nodo));
    cola->cabecera2 = (Nodo*)malloc(sizeof(Nodo));
    cola->cabecera1->sig = cola->cabecera2;
    cola->cabecera1->ant = cola->cabecera2;
    cola->cabecera2->sig = cola->cabecera1;
    cola->cabecera2->ant = cola->cabecera1;
}

bool cola_vacia(Cola *cola) {
    return cola->cabecera1->sig == cola->cabecera2;
}

void meter_dato(Cola *cola, int dato) {
    Nodo *nuevo = crear_nodo(dato);
    if (!nuevo) return;
    Nodo *ultimo = cola->cabecera2->ant;
    // Insertar entre ultimo y cabecera2
    nuevo->sig = cola->cabecera2;
    nuevo->ant = ultimo;
    ultimo->sig = nuevo;
    cola->cabecera2->ant = nuevo;
}

bool sacar_dato(Cola *cola, int *dato) {
    if (cola_vacia(cola)) return false;
    Nodo *primero = cola->cabecera1->sig;
    *dato = primero->dato;
    cola->cabecera1->sig = primero->sig;
    primero->sig->ant = cola->cabecera1;
    free(primero);
    return true;
}

void mostrar_cola(Cola *cola) {
    Nodo *aux = cola->cabecera1->sig;
    printf("Cola: ");
    while (aux != cola->cabecera2) {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}

void liberar_cola(Cola *cola) {
    Nodo *aux = cola->cabecera1->sig;
    while (aux != cola->cabecera2) {
        Nodo *tmp = aux;
        aux = aux->sig;
        free(tmp);
    }
    free(cola->cabecera1);
    free(cola->cabecera2);
}

int main() {
    Cola cola;
    inicializar_cola(&cola);
    int opcion, dato;
    do {
        printf("\n1. Meter dato\n2. Sacar dato\n3. Mostrar cola\n4. Salir\nOpcion: ");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
                printf("Dato a meter: ");
                scanf("%d", &dato);
                meter_dato(&cola, dato);
                break;
            case 2:
                if (sacar_dato(&cola, &dato))
                    printf("Dato sacado: %d\n", dato);
                else
                    printf("Cola vacia\n");
                break;
            case 3:
                mostrar_cola(&cola);
                break;
        }
    } while(opcion != 4);
    liberar_cola(&cola);
    return 0;
}
