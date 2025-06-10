#include <stdio.h>

/*
 * Uso de doble puntero para manipular un arreglo de estructuras.
 */
struct persona {
    char nombre[30];
    int  edad;
    float estatura;
    char sexo;
};

int main(void) {
    struct persona datos[5], *p, **p2;

    for (p = datos, p2 = &p; *p2 < datos + 5; (*p2)++) {
        printf("\nIngresa el nombre: ");
        fgets((*p2)->nombre, sizeof((*p2)->nombre), stdin);
        fflush(stdin);
        printf("Ingresa la edad: ");
        scanf("%d", &(*p2)->edad);
        fflush(stdin);
        printf("Ingresa la estatura: ");
        scanf("%f", &(*p2)->estatura);
        fflush(stdin);
        printf("Ingresa el sexo: ");
        scanf(" %c", &(*p2)->sexo);
        fflush(stdin);
    }
    printf("La estructura mide %lu bytes\n", sizeof(struct persona));
    for (p = datos, p2 = &p; *p2 < datos + 5; (*p2)++) {
        printf("\nCelda %d en direccion %p\n", (int)(*p2 - datos), (void*)*p2);
        printf("Nombre: %sDireccion : %p\n", (*p2)->nombre, (void*)&(*p2)->nombre);
        printf("Edad: %d Direccion : %p\n", (*p2)->edad, (void*)&(*p2)->edad);
        printf("Estatura: %f Direccion : %p\n", (*p2)->estatura, (void*)&(*p2)->estatura);
        printf("Sexo: %c Direccion : %p\n", (*p2)->sexo, (void*)&(*p2)->sexo);
    }
    return 0;
}