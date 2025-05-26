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
    return p->ptr == p->arreglo;
}

int llenapila(struct Pila *p) {
    return p->ptr == p->arreglo + TAM;
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
    struct Pila *ptr = &pila;
    ptr->ptr = ptr->arreglo;
    for (;;) {
        if (!vaciopila(ptr)) {
            mostrarpila(ptr);
        }
        int op = menu();
        switch (op) {
        case 1:
            if (!llenapila(ptr)) {
                printf("Ingresa el numero a insertar: ");
                scanf("%d", &num);
                meterpila(ptr, num);
            } else
                printf("No hay espacio en la pila\n");
            break;
        case 2:
            if (!vaciopila(ptr)) {
                sacarpila(ptr);
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