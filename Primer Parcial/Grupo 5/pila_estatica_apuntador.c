#include <stdio.h>
#define TAM 5

struct Pila {
    int arreglo[TAM];
    int *ptr;
};

int meterpila(struct Pila *, int);
int sacarpila(struct Pila *);
int vaciopila(struct Pila *);
int llenapila(struct Pila *);
int mostrarpila(struct Pila *);
int menu();

int meterpila(struct Pila *p, int dato) {
    *(p->ptr) = dato;
    p->ptr++;
    return 0;
}

int sacarpila(struct Pila *p) {
    p->ptr--;
    return *(p->ptr);
}

int vaciopila(struct Pila *p) {
    if (p->ptr == p->arreglo)
        return 1;
    else
        return 0;
}

int llenapila(struct Pila *p) {
    if (p->ptr == p->arreglo + TAM)
        return 1;
    else
        return 0;
}

int mostrarpila(struct Pila *p) {
    printf("PILA: ");
    for (int *i = p->arreglo; i < p->ptr; i++) {
        printf("[%d] ", *i);
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

int main() {
    int num;
    struct Pila pila;
    pila.ptr = pila.arreglo;
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