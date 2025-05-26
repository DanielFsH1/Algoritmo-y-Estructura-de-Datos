#include <stdio.h>
#include <stdlib.h>

struct persona {
    char nombre[30];
    int edad;
    float est;
    char sexo;
};

int main() {
    struct persona arreglo[5];
    int i;
    printf("El tamaño del dato persona es %ld\n", sizeof(struct persona));
    for (i = 0; i < 5; i++) {
        printf("\nIngresa nombre: ");
        fgets(arreglo[i].nombre, 30, stdin);
        printf("Ingresa edad: ");
        scanf("%d", &arreglo[i].edad);
        printf("Ingresa estatura: ");
        scanf("%f", &arreglo[i].est);
        printf("Ingresa sexo: ");
        scanf(" %c", &arreglo[i].sexo);
        fflush(stdin);
    }
    for (i = 0; i < 5; i++) {
        printf("\n\nEn la celda %d está en la dirección %lu", i, &arreglo[i]);
        printf("\nEl nombre es %s y está en la dirección %lu", arreglo[i].nombre, &arreglo[i].nombre);
        printf("\nLa edad es %d y está en la dirección %lu", arreglo[i].edad, &arreglo[i].edad);
        printf("\nLa estatura es %.2f y está en la dirección %lu", arreglo[i].est, &arreglo[i].est);
        printf("\nEl sexo es %c y está en la dirección %lu\n", arreglo[i].sexo, &arreglo[i].sexo);
    }
    return 0;
}