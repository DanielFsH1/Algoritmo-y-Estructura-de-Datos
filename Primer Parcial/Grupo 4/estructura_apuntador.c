#include<stdio.h>
#define TAM 5
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
int main(){
    struct Datos var;
    for(var.ptr=var.arreglo; var.ptr<&var.arreglo[TAM]; var.ptr++){
        fflush(stdin);
        printf("Nombre: \n");
        gets(var.ptr->nombre);
        fflush(stdin);
        printf("Edad: \n");
        scanf("%d",&var.ptr->edad);
        fflush(stdin);
        printf("Estatura: \n");
        scanf("%f",&var.ptr->est);
        fflush(stdin);
        printf("Sexo: \n");
        scanf("%c",&var.ptr->sexo);
        fflush(stdin);
        printf("Calle: \n");
        gets(var.ptr->dom.calle);
        fflush(stdin);
        printf("Numero: \n");
        scanf("%d",&var.ptr->dom.num);
        fflush(stdin);
        printf("Colonia: \n");
        gets(var.ptr->dom.colonia);
        fflush(stdin);
    }
    for(var.ptr=var.arreglo; var.ptr<&var.arreglo[TAM]; var.ptr++){
        printf("En la celda %d la cadena nombre: %s en la direccion %lu\n", (int)(var.ptr - var.arreglo), var.ptr->nombre, &var.ptr->nombre);
        printf("En la celda %d la edad: %d en la direccion %lu\n", (int)(var.ptr - var.arreglo), var.ptr->edad, &var.ptr->edad);
        printf("En la celda %d la estatura: %.2f en la direccion %lu\n", (int)(var.ptr - var.arreglo), var.ptr->est, &var.ptr->est);
        printf("En la celda %d el sexo: %c en la direccion %lu\n", (int)(var.ptr - var.arreglo), var.ptr->sexo, &var.ptr->sexo);
    }
    return 0;
}