#include <stdio.h>

/*
 * Estructura que almacena un arreglo y accede a él por índice.
 */
struct Datos {
    int numeros[5];
    int i;
};

int main(void){
    struct Datos dato;
    for (dato.i = 0; dato.i < 5; dato.i++) {
        printf("Ingresa el dato numero %d: ", dato.i + 1);
        scanf("%d", &dato.numeros[dato.i]);
    }

    for (dato.i = 0; dato.i < 5; dato.i++) {
        printf("Celda %d => %d (dir %p)\n",
               dato.i, dato.numeros[dato.i], (void*)&dato.numeros[dato.i]);
    }

    return 0;
}