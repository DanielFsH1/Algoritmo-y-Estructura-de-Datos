#include <stdio.h>

int main() {
    int arreglo[5];  // Declaración de un arreglo de 5 enteros
    int *ptr1, **ptr2;  // ptr1 es un puntero a entero, ptr2 es un puntero a puntero a entero

    ptr1 = arreglo;  // ptr1 apunta al inicio del arreglo

    // Bucle para ingresar valores en el arreglo usando doble puntero
    for (ptr2 = &ptr1; *ptr2 < &arreglo[5]; *ptr2 = *ptr2 + 1) {
        printf("Ingrese dato entero: \n");
        scanf("%d", *ptr2);  // Se almacena el valor ingresado en la dirección apuntada por *ptr2
    }

    // Bucle para imprimir los valores almacenados junto con sus direcciones
    for (ptr1 = arreglo, ptr2 = &ptr1; *ptr2 < &arreglo[5]; *ptr2 = *ptr2 + 1) {
        printf("\nEn la celda %d está el valor %d en la dirección %p",
               (int)(*ptr2 - arreglo),  // Índice calculado restando la dirección base
               **ptr2,  // Valor almacenado en la posición apuntada por *ptr2
               *ptr2);  // Dirección de memoria del elemento del arreglo
    }

    return 0;
}