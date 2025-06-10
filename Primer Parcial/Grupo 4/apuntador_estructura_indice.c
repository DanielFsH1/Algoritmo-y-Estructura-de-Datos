#include <stdio.h>
#define TAM 5

/*
 * Uso de puntero a estructura con acceso por índice.
 */
struct Domicilio {
    char calle[30];
    int num;
    char colonia[30];
};

struct Persona {
    char nombre[30];
    int edad;
    float est;
    char sexo;
    struct Domicilio dom;
};

struct Datos {
    struct Persona arreglo[TAM];
    int i;
};

int main(void) {
    struct Datos var, *pt = &var;
    for (pt->i = 0; pt->i < TAM; pt->i++) {
        fflush(stdin);
        printf("Nombre:\n");
        fgets(pt->arreglo[pt->i].nombre, sizeof(pt->arreglo[pt->i].nombre), stdin);
        fflush(stdin);
        printf("Edad:\n");
        scanf("%d", &pt->arreglo[pt->i].edad);
        fflush(stdin);
        printf("Estatura:\n");
        scanf("%f", &pt->arreglo[pt->i].est);
        fflush(stdin);
        printf("Sexo:\n");
        scanf(" %c", &pt->arreglo[pt->i].sexo);
        fflush(stdin);
        printf("Calle:\n");
        fgets(pt->arreglo[pt->i].dom.calle, sizeof(pt->arreglo[pt->i].dom.calle), stdin);
        fflush(stdin);
        printf("Numero:\n");
        scanf("%d", &pt->arreglo[pt->i].dom.num);
        fflush(stdin);
        printf("Colonia:\n");
        fgets(pt->arreglo[pt->i].dom.colonia, sizeof(pt->arreglo[pt->i].dom.colonia), stdin);
        fflush(stdin);
    }
    for (pt->i = 0; pt->i < TAM; pt->i++) {
        printf("Celda %d nombre %sDireccion %p\n", pt->i, pt->arreglo[pt->i].nombre, (void*)pt->arreglo[pt->i].nombre);
        printf("Celda %d edad %d Direccion %p\n", pt->i, pt->arreglo[pt->i].edad, (void*)&pt->arreglo[pt->i].edad);
        printf("Celda %d estatura %.2f Direccion %p\n", pt->i, pt->arreglo[pt->i].est, (void*)&pt->arreglo[pt->i].est);
        printf("Celda %d sexo %c Direccion %p\n", pt->i, pt->arreglo[pt->i].sexo, (void*)&pt->arreglo[pt->i].sexo);
        printf("Celda %d calle %sDireccion %p\n", pt->i, pt->arreglo[pt->i].dom.calle, (void*)pt->arreglo[pt->i].dom.calle);
        printf("Celda %d numero %d Direccion %p\n", pt->i, pt->arreglo[pt->i].dom.num, (void*)&pt->arreglo[pt->i].dom.num);
        printf("Celda %d colonia %sDireccion %p\n", pt->i, pt->arreglo[pt->i].dom.colonia, (void*)pt->arreglo[pt->i].dom.colonia);
    }
    return 0;
}