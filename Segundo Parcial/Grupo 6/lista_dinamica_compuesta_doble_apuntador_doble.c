// Lista Dinámica de dato compuesto (estructura dato con cadena, entero y carácter) sin nodos de cabecera con 2 apuntadores de referencia (doble apuntador), con enlace doble entre nodos
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Dato {
    char nombre[30];
    int edad;
    char genero;
} Dato;

typedef struct Nodo {
    Dato dato;
    struct Nodo *sig;
    struct Nodo *ant;
} Nodo;

typedef struct {
    Nodo *inicio;
    Nodo *final;
} Lista;

Nodo* crear_nodo(Dato dato) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo) {
        nuevo->dato = dato;
        nuevo->sig = nuevo->ant = NULL;
    }
    return nuevo;
}

void inicializar_lista(Lista *lista) {
    lista->inicio = lista->final = NULL;
}

bool lista_vacia(Lista *lista) {
    return lista->inicio == NULL;
}

void meter_dato(Lista *lista, Dato dato) {
    Nodo *nuevo = crear_nodo(dato);
    if (!nuevo) return;
    if (lista_vacia(lista)) {
        lista->inicio = lista->final = nuevo;
    } else {
        nuevo->sig = NULL;
        nuevo->ant = lista->final;
        lista->final->sig = nuevo;
        lista->final = nuevo;
    }
}

bool sacar_dato(Lista *lista, Dato *dato) {
    if (lista_vacia(lista)) return false;
    Nodo *primero = lista->inicio;
    *dato = primero->dato;
    lista->inicio = primero->sig;
    if (lista->inicio) lista->inicio->ant = NULL;
    else lista->final = NULL;
    free(primero);
    return true;
}

void mostrar_lista(Lista *lista) {
    Nodo *aux = lista->inicio;
    printf("Lista:\n");
    while (aux) {
        printf("Nombre: %s, Edad: %d, Género: %c\n", aux->dato.nombre, aux->dato.edad, aux->dato.genero);
        aux = aux->sig;
    }
}

void liberar_lista(Lista *lista) {
    Nodo *aux = lista->inicio;
    while (aux) {
        Nodo *tmp = aux;
        aux = aux->sig;
        free(tmp);
    }
    lista->inicio = lista->final = NULL;
}

int main() {
    Lista lista;
    inicializar_lista(&lista);
    int opcion;
    Dato dato;
    do {
        printf("\n1. Meter dato\n2. Sacar dato\n3. Mostrar lista\n4. Salir\nOpcion: ");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
                printf("Nombre: ");
                scanf("%s", dato.nombre);
                printf("Edad: ");
                scanf("%d", &dato.edad);
                printf("Género: ");
                scanf(" %c", &dato.genero);
                meter_dato(&lista, dato);
                break;
            case 2:
                if (sacar_dato(&lista, &dato))
                    printf("Dato sacado: %s, %d, %c\n", dato.nombre, dato.edad, dato.genero);
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
