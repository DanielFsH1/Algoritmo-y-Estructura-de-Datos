#include <stdio.h>
#define TAM 5

struct Cola {
    int arreglo[TAM];
    int frente;
    int fin;
    int contador;
};

int resetear(struct Cola *c) {
    c->frente = 0;
    c->fin = 0;
    c->contador = 0;
    return 0;
}

int meter(struct Cola *c, int dato) {
    c->arreglo[c->fin] = dato;
    c->fin = (c->fin + 1) % TAM;
    c->contador++;
    return 0;
}

int sacar(struct Cola *c) {
    int aux = c->arreglo[c->frente];
    c->frente = (c->frente + 1) % TAM;
    c->contador--;
    return aux;
}

int vacio(struct Cola *c) {
    return c->contador == 0;
}

int lleno(struct Cola *c) {
    return c->contador == TAM;
}

int visualizar(struct Cola *c) {
    printf("\nCola: ");
    for (int i = 0; i < c->contador; i++) {
        int indice = (c->frente + i) % TAM;
        printf("%d ", c->arreglo[indice]);
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
    struct Cola *ptrCola = &cola;
    resetear(ptrCola);
    for (;;) {
        switch (menu()) {
            case 1:
                if (lleno(ptrCola)) {
                    printf("\nCOLA LLENA\n");
                } else {
                    printf("Ingresa el dato a meter: ");
                    scanf("%d", &dato);
                    meter(ptrCola, dato);
                    visualizar(ptrCola);
                }
                break;
            case 2:
                if (vacio(ptrCola)) {
                    printf("\nCOLA VACIA\n");
                } else {
                    printf("DATO SACADO: %d\n", sacar(ptrCola));
                    visualizar(ptrCola);
                }
                break;
            default:
                return 0;
        }
    }
}