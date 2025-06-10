#include <stdio.h>

/*
 * Puntero a estructura con acceso a elementos mediante índice.
 */
struct Datos {
    int numeros[5];
    int i;
};

int main(void){
    struct Datos dato, *pd;
    pd = &dato;

    for (pd->i = 0; pd->i < 5; pd->i++) {
        printf("Ingresa el dato numero %d: ", pd->i + 1);
        scanf("%d", &pd->numeros[pd->i]);
    }

    for (pd->i = 0; pd->i < 5; pd->i++) {
        printf("Celda %d => %d (dir %p)\n",
               pd->i + 1, pd->numeros[pd->i], (void*)&pd->numeros[pd->i]);
    }

    return 0;
}