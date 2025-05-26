#include <stdio.h>

int main()
{
    int arreglo[5];
    int i; // índice
    
    for(i = 0; i < 5; i++) {
        printf("Ingresa un numero entero: ");
        scanf("%d", &arreglo[i]);
    }

    for(i = 0; i < 5; i++)
        printf("Celda:%d Direccion de memoria: %lu Numero: %d\n", i, &arreglo[i], arreglo[i]);
    
    return 0;

    //Luis Enrique Cruz Estrella
}