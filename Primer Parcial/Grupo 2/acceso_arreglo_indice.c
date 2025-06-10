#include <stdio.h>

/*
 * Acceso a arreglo de estructuras mediante índice.
 */
struct persona {
    char nombre[30];
    int  edad;
    float est;
    char sexo;
};

int main(void) {
    struct persona datos[5];
    int idx;

    printf("El tamaño del dato persona es %lu\n", sizeof(struct persona));
    for (idx = 0; idx < 5; idx++) {
        printf("\nIngresa nombre: ");
        fgets(datos[idx].nombre, sizeof(datos[idx].nombre), stdin);
        printf("Ingresa edad: ");
        scanf("%d", &datos[idx].edad);
        printf("Ingresa estatura: ");
        scanf("%f", &datos[idx].est);
        printf("Ingresa sexo: ");
        scanf(" %c", &datos[idx].sexo);
        fflush(stdin);
    }
    for (idx = 0; idx < 5; idx++) {
        printf("\n\nCelda %d en direccion %p", idx, (void*)&datos[idx]);
        printf("\nNombre: %sDireccion: %p", datos[idx].nombre, (void*)&datos[idx].nombre);
        printf("\nEdad: %d Direccion: %p", datos[idx].edad, (void*)&datos[idx].edad);
        printf("\nEstatura: %.2f Direccion: %p", datos[idx].est, (void*)&datos[idx].est);
        printf("\nSexo: %c Direccion: %p\n", datos[idx].sexo, (void*)&datos[idx].sexo);
    }
    return 0;
}