#include <stdio.h>
#define TAM 5

struct Cola {
    int arreglo[TAM];
    int *ptrm;
    int *ptrs;
    int contador;
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
    ptrc->contador = 0;
    return 0;
}

int meter(struct Cola *ptrc, int dato) {
    *ptrc->ptrm = dato;
    ptrc->ptrm++;
    ptrc->contador++;
    if (ptrc->ptrm == ptrc->arreglo + TAM)
        ptrc->ptrm = ptrc->arreglo;
    return 0;
}

int sacar(struct Cola *ptrc, int *dato) {
    *dato = *ptrc->ptrs;
    ptrc->ptrs++;
    ptrc->contador--;
    if (ptrc->ptrs == ptrc->arreglo + TAM)
        ptrc->ptrs = ptrc->arreglo;
    return 0;
}

int vacio(struct Cola *ptrc) {
    return ptrc->contador == 0;
}

int lleno(struct Cola *ptrc) {
    return ptrc->contador == TAM;
}

int visualizar(struct Cola *ptrc) {
    printf("\nCola: ");
    int *p = ptrc->ptrs;
    for (int i = 0; i < ptrc->contador; i++) {
        printf("%d ", *p);
        p++;
        if (p == ptrc->arreglo + TAM)
            p = ptrc->arreglo;
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

int main() {
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