#include <stdio.h>
#define TAM 5

/*
 * Acceso mediante un puntero a variable estructura y puntero interno
 * para recorrer un arreglo de estructuras.
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
    struct Persona *pt1;
};

int main(void) {
    struct Datos var, *pt = &var;
    for (pt->pt1 = pt->arreglo; pt->pt1 < pt->arreglo + TAM; pt->pt1++) {
        fflush(stdin);
        printf("Nombre:\n");
        fgets(pt->pt1->nombre, sizeof(pt->pt1->nombre), stdin);
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
        fgets(pt->pt1->dom.calle, sizeof(pt->pt1->dom.calle), stdin);
        fflush(stdin);
        printf("Numero:\n");
        scanf("%d", &pt->pt1->dom.num);
        fflush(stdin);
        printf("Colonia:\n");
        fgets(pt->pt1->dom.colonia, sizeof(pt->pt1->dom.colonia), stdin);
        fflush(stdin);
    }
    for (pt->pt1 = pt->arreglo; pt->pt1 < pt->arreglo + TAM; pt->pt1++) {
        printf("Celda %d nombre %sDireccion %p\n", (int)(pt->pt1 - pt->arreglo), pt->pt1->nombre, (void*)pt->pt1->nombre);
        printf("Celda %d edad %d Direccion %p\n", (int)(pt->pt1 - pt->arreglo), pt->pt1->edad, (void*)&pt->pt1->edad);
        printf("Celda %d estatura %.2f Direccion %p\n", (int)(pt->pt1 - pt->arreglo), pt->pt1->est, (void*)&pt->pt1->est);
        printf("Celda %d sexo %c Direccion %p\n", (int)(pt->pt1 - pt->arreglo), pt->pt1->sexo, (void*)&pt->pt1->sexo);
        printf("Celda %d calle %sDireccion %p\n", (int)(pt->pt1 - pt->arreglo), pt->pt1->dom.calle, (void*)pt->pt1->dom.calle);
        printf("Celda %d numero %d Direccion %p\n", (int)(pt->pt1 - pt->arreglo), pt->pt1->dom.num, (void*)&pt->pt1->dom.num);
        printf("Celda %d colonia %sDireccion %p\n", (int)(pt->pt1 - pt->arreglo), pt->pt1->dom.colonia, (void*)pt->pt1->dom.colonia);
    }
    return 0;
}