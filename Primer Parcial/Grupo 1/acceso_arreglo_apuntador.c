#include <stdio.h>

/*
 * Ejemplo de acceso a un arreglo utilizando un puntero.
 * Se ingresan cinco enteros y posteriormente se muestran con
 * su respectiva dirección de memoria.
 */
int main(void)
{
    int datos[5];
    int *p;             /* Puntero que recorrerá el arreglo */

    for (p = datos; p < datos + 5; p++) {
        printf("Ingresa un numero entero: ");
        scanf("%d", p);
    }

    for (p = datos; p < datos + 5; p++) {
        printf("Celda:%d Direccion: %p Numero: %d\n",
               (int)(p - datos), (void*)p, *p);
    }
    return 0;
}