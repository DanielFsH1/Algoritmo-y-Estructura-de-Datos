#include <stdio.h>
#define TAM 5

struct Cola {
    int arreglo[TAM];
    int *posiciones[TAM];
    int **frente;
    int **fin;
    int contador;
};

int resetear(struct Cola **c) {
    for (int i = 0; i < TAM; i++)
        (*c)->posiciones[i] = &(*c)->arreglo[i];
    (*c)->frente = &(*c)->posiciones[0];
    (*c)->fin = &(*c)->posiciones[0];
    (*c)->contador = 0;
    return 0;
}

int meter(struct Cola **c, int dato) {
    **((*c)->fin) = dato;
    (*c)->fin++;
    if ((*c)->fin == (*c)->posiciones + TAM)
        (*c)->fin = (*c)->posiciones;
    (*c)->contador++;
    return 0;
}

int sacar(struct Cola **c) {
    int aux = **((*c)->frente);
    (*c)->frente++;
    if ((*c)->frente == (*c)->posiciones + TAM)
        (*c)->frente = (*c)->posiciones;
    (*c)->contador--;
    return aux;
}

int vacio(struct Cola **c) {
    return (*c)->contador == 0;
}

int lleno(struct Cola **c) {
    return (*c)->contador == TAM;
}

int visualizar(struct Cola **c) {
    printf("\nCola: ");
    int **ptr = (*c)->frente;
    for (int i = 0; i < (*c)->contador; i++) {
        printf("%d ", **ptr);
        ptr++;
        if (ptr == (*c)->posiciones + TAM)
            ptr = (*c)->posiciones;
    }
    printf("\n");
    return 0;
}

int menu() {
    int op;
    printf("----MENU---");
    printf("\n1. Insertar");
    printf("\n2. Sacar");
    printf("\n3. Salir\n");
    printf("Ingresa la opcion: ");
    scanf("%d", &op);
    return op;
}

int main() {
    int dato;
    struct Cola cola;
    struct Cola *ptr = &cola;
    struct Cola **c = &ptr;
    resetear(c);
    for (;;) {
        switch (menu()) {
            case 1:
                if (lleno(c)) {
                    printf("\nCOLA LLENA\n");
                } else {
                    printf("Ingresa el dato a meter: ");
                    scanf("%d", &dato);
                    meter(c, dato);
                    visualizar(c);
                }
                break;
            case 2:
                if (vacio(c)) {
                    printf("\nCOLA VACIA\n");
                } else {
                    printf("DATO SACADO: %d\n", sacar(c));
                    visualizar(c);
                }
                break;
            default:
                return 0;
        }
    }
}