#include <stdio.h>
#define TAM 5

/*
 * Implementación de una pila estática manejada mediante índices.
 */

struct Pila {
    int arreglo[TAM];
    int tope;
};

int meterpila(struct Pila *, int);
int sacarpila(struct Pila *);
int vaciopila(struct Pila *);
int llenapila(struct Pila *);
int mostrarpila(struct Pila *);
int menu();

int meterpila(struct Pila *p, int dato) {
    p->arreglo[p->tope] = dato;
    p->tope++;
    return 0;
}

int sacarpila(struct Pila *p) {
    p->tope--;
    return p->arreglo[p->tope];
}

int vaciopila(struct Pila *p) {
    if (p->tope == 0)
        return 1;
    else
        return 0;
}

int llenapila(struct Pila *p) {
    if (p->tope == TAM)
        return 1;
    else
        return 0;
}

int mostrarpila(struct Pila *p) {
    printf("PILA: ");
    for (int i = 0; i < p->tope; i++) {
        printf("[%d] ", p->arreglo[i]);
    }
    printf("\n");
    return 0;
}

int menu() {
    printf("--MENU--\n");
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. salir\n");
    printf("Ingresa la opcion\n");
    int op;
    scanf("%d", &op);
    return op;
}

int main(void) {
    int num;
    struct Pila pila;
    pila.tope = 0;
    for (;;) {
        if (vaciopila(&pila) == 0) {
            mostrarpila(&pila);
        }
        int op = menu();
        switch (op) {
        case 1:
            if (llenapila(&pila) == 0) {
                printf("Ingresa el numero a insertar: ");
                scanf("%d", &num);
                meterpila(&pila, num);
            } else
                printf("No hay espacio en la pila\n");
            break;
        case 2:
            if (vaciopila(&pila) == 0) {
                sacarpila(&pila);
                printf("Dato sacado\n");
            } else
                printf("La pila esta vacia\n");
            break;
        case 3:
            printf("Saliendo del programa");
            return 0;
        default:
            printf("Opcion invalida, intente de nuevo\n");
            break;
        }
    }
    return 0;
}