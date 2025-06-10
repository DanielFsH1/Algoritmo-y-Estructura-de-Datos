#include <stdio.h>

/*
 * Uso de doble puntero para rellenar e imprimir un arreglo.
 */
int main(void) {
    int datos[5];                  /* arreglo de enteros */
    int *p1, **p2;                 /* p1 apunta a entero, p2 a puntero de entero */

    p1 = datos;                    /* p1 inicia al comienzo del arreglo */

    /* Ingreso de datos mediante el doble puntero */
    for (p2 = &p1; *p2 < datos + 5; (*p2)++) {
        printf("Ingrese dato entero: ");
        scanf("%d", *p2);
    }

    /* Impresión de valores y direcciones usando el doble puntero */
    for (p1 = datos, p2 = &p1; *p2 < datos + 5; (*p2)++) {
        printf("Celda %d -> valor %d en direccion %p\n",
               (int)(*p2 - datos), **p2, *p2);
    }

    return 0;
}