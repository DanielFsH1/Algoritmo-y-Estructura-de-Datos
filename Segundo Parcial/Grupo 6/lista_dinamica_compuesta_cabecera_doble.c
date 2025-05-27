// Lista Dinámica de dato compuesto (estructura dato con cadena, entero y carácter) con 2 nodos de cabecera (1 apuntador de referencia), con enlace doble entre nodos
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
    Nodo *cabecera1;
    Nodo *cabecera2;
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
    lista->cabecera1 = (Nodo*)malloc(sizeof(Nodo));
    lista->cabecera2 = (Nodo*)malloc(sizeof(Nodo));
    lista->cabecera1->sig = lista->cabecera2;
    lista->cabecera1->ant = lista->cabecera2;
    lista->cabecera2->sig = lista->cabecera1;
    lista->cabecera2->ant = lista->cabecera1;
}

bool lista_vacia(Lista *lista) {
    return lista->cabecera1->sig == lista->cabecera2;
}

void meter_dato(Lista *lista, Dato dato) {
    Nodo *nuevo = crear_nodo(dato);
    if (!nuevo) return;
    Nodo *ultimo = lista->cabecera2->ant;
    nuevo->sig = lista->cabecera2;
    nuevo->ant = ultimo;
    ultimo->sig = nuevo;
    lista->cabecera2->ant = nuevo;
}

bool sacar_dato(Lista *lista, Dato *dato) {
    if (lista_vacia(lista)) return false;
    Nodo *primero = lista->cabecera1->sig;
    *dato = primero->dato;
    lista->cabecera1->sig = primero->sig;
    primero->sig->ant = lista->cabecera1;
    free(primero);
    return true;
}

void mostrar_lista(Lista *lista) {
    Nodo *aux = lista->cabecera1->sig;
    printf("Lista:\n");
    while (aux != lista->cabecera2) {
        printf("Nombre: %s, Edad: %d, Género: %c\n", aux->dato.nombre, aux->dato.edad, aux->dato.genero);
        aux = aux->sig;
    }
}

void liberar_lista(Lista *lista) {
    Nodo *aux = lista->cabecera1->sig;
    while (aux != lista->cabecera2) {
        Nodo *tmp = aux;
        aux = aux->sig;
        free(tmp);
    }
    free(lista->cabecera1);
    free(lista->cabecera2);
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
