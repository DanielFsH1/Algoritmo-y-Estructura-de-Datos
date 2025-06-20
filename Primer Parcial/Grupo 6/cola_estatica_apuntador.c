#include <stdio.h>
#define TAM 5

/*
 * Cola estática implementada con punteros de movimiento y salida.
 */

struct Cola {
    int arreglo[TAM];
    int *ptrm;
    int *ptrs;
};

int resetear(struct Cola *);
int meter(struct Cola *, int);
int sacar(struct Cola *, int *);
int vacio(struct Cola *);
int lleno(struct Cola *);
int menu();
int visualizar(struct Cola *);

int resetear(struct Cola *ptrc) {
    ptrc->ptrm = ptrc->arreglo;
    ptrc->ptrs = ptrc->arreglo;
    return 0;
}

int meter(struct Cola *ptrc, int dato) {
    *ptrc->ptrm = dato;
    ptrc->ptrm++;
    return 0;
}

int sacar(struct Cola *ptrc, int *dato) {
    *dato = *ptrc->ptrs;
    ptrc->ptrs++;
    return 0;
}

int vacio(struct Cola *ptrc) {
    return ptrc->ptrm == ptrc->ptrs;
}

int lleno(struct Cola *ptrc) {
    return ptrc->ptrm == &ptrc->arreglo[TAM];
}

int visualizar(struct Cola *ptrc) {
    printf("\nCola: ");
    for (int *p = ptrc->ptrs; p < ptrc->ptrm; p++) {
        printf("%d ", *p);
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
    fflush(stdin);
    return op;
}

int main(void) {
    struct Cola cola;
    int dato;

    resetear(&cola);

    while (1) {
        switch (menu()) {
            case 1:
                if (lleno(&cola))
                    printf("\nCOLA LLENA\n");
                else {
                    printf("Ingresa el dato a meter: ");
                    scanf("%d", &dato);
                    meter(&cola, dato);
                    visualizar(&cola);
                }
                break;
            case 2:
                if (vacio(&cola))
                    printf("\nCOLA VACIA\n");
                else {
                    sacar(&cola, &dato);
                    printf("DATO SACADO: %d\n", dato);
                    visualizar(&cola);
                }
                break;
            default:
                return 0;
        }
    }
    return 0;
}