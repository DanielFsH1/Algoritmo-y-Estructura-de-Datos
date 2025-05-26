#include <stdio.h>

int main()
{
    int arreglo[5];
    int *ptr; //declaracion de puntero
    
    for(ptr=arreglo; ptr<&arreglo[5]; ptr++){
        printf("Ingresa un numero entero: ");
        scanf("%d", ptr);
    }
    
    for(ptr=arreglo; ptr<&arreglo[5]; ptr++)
        printf("Celda:%d Direccion de memoria: %lu Numero: %d\n", (int)(ptr-arreglo), ptr, *ptr);
    return 0;
    
    //Luis Enrique Cruz Estrella
}