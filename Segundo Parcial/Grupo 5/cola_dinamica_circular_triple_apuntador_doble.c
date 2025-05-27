// Cola Dinámica Circular de enteros sin nodos de cabecera con 2 apuntadores de referencia (triple apuntador), con enlace doble entre nodos
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    int dato;
    struct Nodo *sig;
    struct Nodo *ant;
} Nodo;

typedef struct {
    Nodo *frente;
    Nodo *final;
    Nodo **pmedio; // triple apuntador (puntero a puntero a Nodo)
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
    cola->frente = cola->final = NULL;
    cola->pmedio = NULL;
}

bool cola_vacia(Cola *cola) {
    return cola->frente == NULL;
}

void meter_dato(Cola *cola, int dato) {
    Nodo *nuevo = crear_nodo(dato);
    if (!nuevo) return;
    if (cola_vacia(cola)) {
        nuevo->sig = nuevo->ant = nuevo;
        cola->frente = cola->final = nuevo;
        cola->pmedio = &cola->frente;
    } else {
        nuevo->sig = cola->frente;
        nuevo->ant = cola->final;
        cola->final->sig = nuevo;
        cola->frente->ant = nuevo;
        cola->final = nuevo;
    }
}

bool sacar_dato(Cola *cola, int *dato) {
    if (cola_vacia(cola)) return false;
    Nodo *primero = cola->frente;
    *dato = primero->dato;
    if (cola->frente == cola->final) {
        cola->frente = cola->final = NULL;
        cola->pmedio = NULL;
    } else {
        cola->frente = primero->sig;
        cola->frente->ant = cola->final;
        cola->final->sig = cola->frente;
    }
    free(primero);
    return true;
}

void mostrar_cola(Cola *cola) {
    if (cola_vacia(cola)) {
        printf("Cola vacía\n");
        return;
    }
    Nodo *aux = cola->frente;
    printf("Cola: ");
    do {
        printf("%d ", aux->dato);
        aux = aux->sig;
    } while (aux != cola->frente);
    printf("\n");
}

void liberar_cola(Cola *cola) {
    if (cola_vacia(cola)) return;
    Nodo *aux = cola->frente;
    do {
        Nodo *tmp = aux;
        aux = aux->sig;
        free(tmp);
    } while (aux != cola->frente);
    cola->frente = cola->final = NULL;
    cola->pmedio = NULL;
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
                    printf("Cola vacía\n");
                break;
            case 3:
                mostrar_cola(&cola);
                break;
        }
    } while(opcion != 4);
    liberar_cola(&cola);
    return 0;
}
