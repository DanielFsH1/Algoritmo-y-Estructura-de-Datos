#include <stdio.h>
#define TAM 5

/*
 * Ejemplo de estructura con puntero para recorrer un arreglo de estructuras.
 */
struct Domicilio{
    char calle[30];
    int num;
    char colonia[30];
};
struct Persona{
    char nombre[30];
    int edad;
    float est;
    char sexo;
    struct Domicilio dom;
};
struct Datos{
    struct Persona arreglo[TAM];
    struct Persona *ptr;
};
int main(void){
    struct Datos var;
    for (var.ptr = var.arreglo; var.ptr < var.arreglo + TAM; var.ptr++) {
        fflush(stdin);
        printf("Nombre: \n");
        fgets(var.ptr->nombre, sizeof(var.ptr->nombre), stdin);
        fflush(stdin);
        printf("Edad: \n");
        scanf("%d", &var.ptr->edad);
        fflush(stdin);
        printf("Estatura: \n");
        scanf("%f", &var.ptr->est);
        fflush(stdin);
        printf("Sexo: \n");
        scanf(" %c", &var.ptr->sexo);
        fflush(stdin);
        printf("Calle: \n");
        fgets(var.ptr->dom.calle, sizeof(var.ptr->dom.calle), stdin);
        fflush(stdin);
        printf("Numero: \n");
        scanf("%d", &var.ptr->dom.num);
        fflush(stdin);
        printf("Colonia: \n");
        fgets(var.ptr->dom.colonia, sizeof(var.ptr->dom.colonia), stdin);
        fflush(stdin);
    }
    for (var.ptr = var.arreglo; var.ptr < var.arreglo + TAM; var.ptr++) {
        printf("En la celda %d nombre: %sDireccion %p\n",
               (int)(var.ptr - var.arreglo), var.ptr->nombre, (void*)&var.ptr->nombre);
        printf("En la celda %d edad: %d Direccion %p\n",
               (int)(var.ptr - var.arreglo), var.ptr->edad, (void*)&var.ptr->edad);
        printf("En la celda %d estatura: %.2f Direccion %p\n",
               (int)(var.ptr - var.arreglo), var.ptr->est, (void*)&var.ptr->est);
        printf("En la celda %d sexo: %c Direccion %p\n",
               (int)(var.ptr - var.arreglo), var.ptr->sexo, (void*)&var.ptr->sexo);
    }
    return 0;
}