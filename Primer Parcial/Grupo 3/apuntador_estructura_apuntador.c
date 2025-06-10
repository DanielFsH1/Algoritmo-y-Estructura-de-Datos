#include <stdio.h>

/*
 * Puntero a estructura y puntero dentro de la estructura para recorrer
 * un arreglo.
 */
struct Datos {
    int numeros[5];
    int *ptr;
};

int main(void){
    struct Datos dato, *pd;
    pd = &dato;

    for (pd->ptr = pd->numeros; pd->ptr < pd->numeros + 5; pd->ptr++) {
        printf("Ingresa el dato numero %d: ", (int)(pd->ptr - pd->numeros) + 1);
        scanf("%d", pd->ptr);
    }

    for (pd->ptr = pd->numeros; pd->ptr < pd->numeros + 5; pd->ptr++) {
        printf("Celda %d => %d (dir %p)\n",
               (int)(pd->ptr - pd->numeros), *pd->ptr, (void*)pd->ptr);
    }

    return 0;
}