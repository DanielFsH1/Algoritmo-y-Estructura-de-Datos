#include <stdio.h>
#define TAM 5

struct Cola {
    int arreglo[TAM];
    int frente;
    int fin;
};

int resetear(struct Cola *c) {
    c->frente = 0;
    c->fin = 0;
    return 0;
}

int meter(struct Cola *c, int dato) {
    c->arreglo[c->fin] = dato;
    c->fin++;
    return 0;
}

int sacar(struct Cola *c) {
    int aux = c->arreglo[c->frente];
    c->frente++;
    return aux;
}

int vacio(struct Cola *c) {
    return c->frente == c->fin;
}

int lleno(struct Cola *c) {
    return c->fin == TAM;
}

int visualizar(struct Cola *c) {
    printf("\nCola: ");
    for (int i = c->frente; i < c->fin; i++) {
        printf("%d ", c->arreglo[i]);
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
    struct Cola *pcola = &cola;

    resetear(pcola);

    for (;;) {
        switch (menu()) {
            case 1:
                if (lleno(pcola)) {
                    printf("\nCOLA LLENA\n");
                } else {
                    printf("Ingresa el dato a meter: ");
                    scanf("%d", &dato);
                    meter(pcola, dato);
                    visualizar(pcola);
                }
                break;
            case 2:
                if (vacio(pcola)) {
                    printf("\nCOLA VACIA\n");
                } else {
                    printf("DATO SACADO: %d\n", sacar(pcola));
                    visualizar(pcola);
                }
                break;
            default:
                return 0;
        }
    }
}