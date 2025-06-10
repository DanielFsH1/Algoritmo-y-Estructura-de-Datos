#include <stdio.h>

/*
 * Acceso a un arreglo mediante índice.
 * El usuario ingresa cinco valores que luego son
 * mostrados junto con su dirección de memoria.
 */
int main(void)
{
    int datos[5];
    int idx; /* variable índice */

    for (idx = 0; idx < 5; idx++) {
        printf("Ingresa un numero entero: ");
        scanf("%d", &datos[idx]);
    }

    for (idx = 0; idx < 5; idx++) {
        printf("Celda:%d Direccion: %p Numero: %d\n",
               idx, (void*)&datos[idx], datos[idx]);
    }

    return 0;
}