#include <stdio.h>

/*
 * Ejemplo de estructura que contiene un arreglo y un puntero
 * para recorrerlo.
 */
struct Datos {
    int numeros[5];
    int *ptr;
};

int main(void){
    struct Datos datos;

    for (datos.ptr = datos.numeros; datos.ptr < datos.numeros + 5; datos.ptr++) {
        printf("Ingresa el dato numero %d: ", (int)(datos.ptr - datos.numeros) + 1);
        scanf("%d", datos.ptr);
    }

    for (datos.ptr = datos.numeros; datos.ptr < datos.numeros + 5; datos.ptr++) {
        printf("Celda %d => %d (dir %p)\n",
               (int)(datos.ptr - datos.numeros), *datos.ptr, (void*)datos.ptr);
    }

    return 0;
}