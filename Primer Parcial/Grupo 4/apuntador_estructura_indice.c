#include <stdio.h>
#define tam 5

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
    struct Persona arreglo[tam];
    int i;
};

int main() {
    struct Datos var, *pt = &var;
    for(pt->i = 0; pt->i < tam; pt->i = pt->i + 1) {
        fflush(stdin);
        printf("Nombre:\n");
        gets(pt->arreglo[pt->i].nombre);
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
        gets(pt->arreglo[pt->i].dom.calle);
        fflush(stdin);
        printf("Numero:\n");
        scanf("%d", &pt->arreglo[pt->i].dom.num);
        fflush(stdin);
        printf("Colonia:\n");
        gets(pt->arreglo[pt->i].dom.colonia);
        fflush(stdin);
    }
    for(pt->i = 0; pt->i < tam; pt->i = pt->i + 1) {
        printf("En la celda %d la cadena %s en la direccion %lu\n", pt->i, pt->arreglo[pt->i].nombre, pt->arreglo[pt->i].nombre);
        printf("En la celda %d la edad %d en la direccion %lu\n", pt->i, pt->arreglo[pt->i].edad, &pt->arreglo[pt->i].edad);
        printf("En la celda %d la estatura %.2f en la direccion %lu\n", pt->i, pt->arreglo[pt->i].est, &pt->arreglo[pt->i].est);
        printf("En la celda %d el sexo %c en la direccion %lu\n", pt->i, pt->arreglo[pt->i].sexo, &pt->arreglo[pt->i].sexo);
        printf("En la celda %d la calle %s en la direccion %lu\n", pt->i, pt->arreglo[pt->i].dom.calle, pt->arreglo[pt->i].dom.calle);
        printf("En la celda %d el numero %d en la direccion %lu\n", pt->i, pt->arreglo[pt->i].dom.num, &pt->arreglo[pt->i].dom.num);
        printf("En la celda %d la colonia %s en la direccion %lu\n", pt->i, pt->arreglo[pt->i].dom.colonia, pt->arreglo[pt->i].dom.colonia);
    }
    return 0;
}