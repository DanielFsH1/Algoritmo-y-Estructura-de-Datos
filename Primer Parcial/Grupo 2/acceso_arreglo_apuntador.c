#include<stdio.h>

struct persona {
    char nombre[30];
    int edad;
    float estatura;
    char sexo;
};

int main() {
    struct persona arreglo[5], *ptr;
    for(ptr=arreglo; ptr<&arreglo[5]; ptr++){
        printf("\nIngresa el nombre: ");
        gets(ptr->nombre);
        fflush(stdin);
        printf("Ingresa la edad: ");
        scanf("%d", &ptr->edad);
        fflush(stdin);
        printf("Ingresa la estatura: ");
        scanf("%f", &ptr->estatura);
        fflush(stdin);
        printf("Ingresa el sexo: ");
        scanf("%c", &ptr->sexo);
        fflush(stdin);
    }
    printf("La estructura mide %d\n", sizeof(struct persona));
    for(ptr=arreglo; ptr<&arreglo[5]; ptr++){
        printf("\nEn la celda %d y en la direccion %lu\n", (int)(ptr-&arreglo[0]), ptr);
        printf("Nombre: %s Direccion : %lu\n", ptr->nombre, &ptr->nombre);
        printf("Edad: %d Direccion : %lu\n", ptr->edad, &ptr->edad);
        printf("Estatura: %f Direccion : %lu\n", ptr->estatura, &ptr->estatura);
        printf("Sexo: %c Direccion : %lu\n", ptr->sexo, &ptr->sexo);
    }
    return 0;
}