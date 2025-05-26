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
    struct Persona *pt1;
};

int main() {
    struct Datos var, *pt = &var;
    for(pt->pt1 = pt->arreglo; pt->pt1 < &pt->arreglo[tam]; pt->pt1 = pt->pt1 + 1) {
        fflush(stdin);
        printf("Nombre:\n");
        gets(pt->pt1->nombre);
        fflush(stdin);
        printf("Edad:\n");
        scanf("%d", &pt->pt1->edad);
        fflush(stdin);
        printf("Estatura:\n");
        scanf("%f", &pt->pt1->est);
        fflush(stdin);
        printf("Sexo:\n");
        scanf(" %c", &pt->pt1->sexo);
        fflush(stdin);
        printf("Calle:\n");
        gets(pt->pt1->dom.calle);
        fflush(stdin);
        printf("Numero:\n");
        scanf("%d", &pt->pt1->dom.num);
        fflush(stdin);
        printf("Colonia:\n");
        gets(pt->pt1->dom.colonia);
        fflush(stdin);
    }
    for(pt->pt1 = pt->arreglo; pt->pt1 < &pt->arreglo[tam]; pt->pt1 = pt->pt1 + 1) {
        printf("En la celda %d la cadena %s en la direccion %lu\n", (int)(pt->pt1 - pt->arreglo), pt->pt1->nombre, pt->pt1->nombre);
        printf("En la celda %d la edad %d en la direccion %lu\n", (int)(pt->pt1 - pt->arreglo), pt->pt1->edad, &pt->pt1->edad);
        printf("En la celda %d la estatura %.2f en la direccion %lu\n", (int)(pt->pt1 - pt->arreglo), pt->pt1->est, &pt->pt1->est);
        printf("En la celda %d el sexo %c en la direccion %lu\n", (int)(pt->pt1 - pt->arreglo), pt->pt1->sexo, &pt->pt1->sexo);
        printf("En la celda %d la calle %s en la direccion %lu\n", (int)(pt->pt1 - pt->arreglo), pt->pt1->dom.calle, pt->pt1->dom.calle);
        printf("En la celda %d el numero %d en la direccion %lu\n", (int)(pt->pt1 - pt->arreglo), pt->pt1->dom.num, &pt->pt1->dom.num);
        printf("En la celda %d la colonia %s en la direccion %lu\n", (int)(pt->pt1 - pt->arreglo), pt->pt1->dom.colonia, pt->pt1->dom.colonia);
    }
    return 0;
}