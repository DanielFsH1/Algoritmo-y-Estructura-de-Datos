#include<stdio.h>

struct persona {
    char nombre[30];
    int edad;
    float estatura;
    char sexo;
};

int main() {
    struct persona arreglo[5], *ptr, **ptr2;
    for(ptr = arreglo, ptr2=&ptr; *ptr2 < &arreglo[5]; (*ptr2)++){
        printf("\nIngresa el nombre: ");
        gets((*ptr2)->nombre);
        fflush(stdin);
        printf("Ingresa la edad: ");
        scanf("%d", &(*ptr2)->edad);
        fflush(stdin);
        printf("Ingresa la estatura: ");
        scanf("%f", &(*ptr2)->estatura);
        fflush(stdin);
        printf("Ingresa el sexo: ");
        scanf(" %c", &(*ptr2)->sexo);
        fflush(stdin);
    }
    printf("La estructura mide %d\n", sizeof(struct persona));
    for(ptr = arreglo, ptr2=&ptr; *ptr2 < &arreglo[5]; (*ptr2)++){
        printf("\nEn la celda %d y en la direccion %lu\n", (int)(*ptr2 - &arreglo[0]), *ptr2);
        printf("Nombre: %s Direccion : %lu\n", (*ptr2)->nombre, &(*ptr2)->nombre);
        printf("Edad: %d Direccion : %lu\n", (*ptr2)->edad, &(*ptr2)->edad);
        printf("Estatura: %f Direccion : %lu\n", (*ptr2)->estatura, &(*ptr2)->estatura);
        printf("Sexo: %c Direccion : %lu\n", (*ptr2)->sexo, &(*ptr2)->sexo);
    }
    return 0;
}