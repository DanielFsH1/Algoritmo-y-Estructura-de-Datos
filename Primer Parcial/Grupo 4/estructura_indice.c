#include <stdio.h>
#define TAM 5

/*
 * Acceso a un arreglo de estructuras mediante índice.
 */
struct Domicilio {
    char calle[30];
    int num;
    char colonia[30];
};

struct Persona {
    char nombre[30];
    int edad;
    float estatura;
    char sexo;
    struct Domicilio domicilio;
};

struct datos {
    struct Persona arreglo[TAM];
    int i;
};

int main(void) {
    struct datos var;
    for (var.i = 0; var.i < TAM; var.i++) {
        printf("\nIngresa el nombre: ");
        fflush(stdin);
        fgets(var.arreglo[var.i].nombre, sizeof(var.arreglo[var.i].nombre), stdin);
        printf("Ingresa la edad: ");
        scanf("%d", &var.arreglo[var.i].edad);
        fflush(stdin);
        printf("Ingresa la estatura: ");
        scanf("%f", &var.arreglo[var.i].estatura);
        fflush(stdin);
        printf("Ingresa el sexo: ");
        scanf(" %c", &var.arreglo[var.i].sexo);
        fflush(stdin);
        printf("Ingresa la calle: ");
        fflush(stdin);
        fgets(var.arreglo[var.i].domicilio.calle, sizeof(var.arreglo[var.i].domicilio.calle), stdin);
        printf("Ingresa el número: ");
        scanf("%d", &var.arreglo[var.i].domicilio.num);
        fflush(stdin);
        printf("Ingresa la colonia: ");
        fflush(stdin);
        fgets(var.arreglo[var.i].domicilio.colonia, sizeof(var.arreglo[var.i].domicilio.colonia), stdin);
    }
    printf("\nTamaño de struct datos: %lu\n", sizeof(struct datos));
    for (var.i = 0; var.i < TAM; var.i++) {
        printf("\nCelda %d:", var.i);
        printf("\nNombre: %s | Dirección: %p", var.arreglo[var.i].nombre, (void*)&var.arreglo[var.i].nombre);
        printf("\nEdad: %d | Dirección: %p", var.arreglo[var.i].edad, (void*)&var.arreglo[var.i].edad);
        printf("\nEstatura: %.2f | Dirección: %p", var.arreglo[var.i].estatura, (void*)&var.arreglo[var.i].estatura);
        printf("\nSexo: %c | Dirección: %p", var.arreglo[var.i].sexo, (void*)&var.arreglo[var.i].sexo);
        printf("\nCalle: %s | Dirección: %p", var.arreglo[var.i].domicilio.calle, (void*)&var.arreglo[var.i].domicilio.calle);
        printf("\nNúmero: %d | Dirección: %p", var.arreglo[var.i].domicilio.num, (void*)&var.arreglo[var.i].domicilio.num);
        printf("\nColonia: %s | Dirección: %p\n", var.arreglo[var.i].domicilio.colonia, (void*)&var.arreglo[var.i].domicilio.colonia);
    }
    return 0;
}