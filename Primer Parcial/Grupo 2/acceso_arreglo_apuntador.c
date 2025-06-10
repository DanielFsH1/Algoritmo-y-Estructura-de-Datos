#include <stdio.h>

/*
 * Manejo de un arreglo de estructuras mediante punteros.
 */
struct persona {
    char  nombre[30];
    int   edad;
    float estatura;
    char  sexo;
};

int main(void) {
    struct persona datos[5], *p;

    for (p = datos; p < datos + 5; p++) {
        printf("\nIngresa el nombre: ");
        fgets(p->nombre, sizeof(p->nombre), stdin);
        fflush(stdin);
        printf("Ingresa la edad: ");
        scanf("%d", &p->edad);
        fflush(stdin);
        printf("Ingresa la estatura: ");
        scanf("%f", &p->estatura);
        fflush(stdin);
        printf("Ingresa el sexo: ");
        scanf(" %c", &p->sexo);
        fflush(stdin);
    }

    printf("La estructura mide %lu bytes\n", sizeof(struct persona));
    for (p = datos; p < datos + 5; p++) {
        printf("\nCelda %d en direccion %p\n", (int)(p - datos), (void*)p);
        printf("Nombre: %sDireccion : %p\n", p->nombre, (void*)&p->nombre);
        printf("Edad: %d Direccion : %p\n", p->edad, (void*)&p->edad);
        printf("Estatura: %f Direccion : %p\n", p->estatura, (void*)&p->estatura);
        printf("Sexo: %c Direccion : %p\n", p->sexo, (void*)&p->sexo);
    }
    return 0;
}