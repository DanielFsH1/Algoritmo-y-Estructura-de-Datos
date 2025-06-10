#include <stdio.h>
#define TAM 5

/*
 * Pila estática donde la estructura es accedida mediante punteros dobles.
 */

struct Pila {
    int arreglo[TAM];
    int *ptr1, **ptr2;
};

int meterpila(struct Pila *, int);
int sacarpila(struct Pila *);
int vacia(struct Pila *);
int llena(struct Pila *);
int mostrarpila(struct Pila *);
int menu();

int meterpila(struct Pila *ptr, int dato){
    **ptr->ptr2=dato;
    *ptr->ptr2=*ptr->ptr2+1;
    return 0;
}

int sacarpila(struct Pila *ptr){
    *ptr->ptr2=*ptr->ptr2-1;
    return (**ptr->ptr2);
}

int vacia(struct Pila *ptr){
    if(*ptr->ptr2==ptr->arreglo)
        return 1;
    else
        return 0;
}

int llena(struct Pila *ptr){
    if(*ptr->ptr2==&ptr->arreglo[TAM])
        return 1;
    else
        return 0;
}
int mostrarpila(struct Pila *ptrs)
{
    printf("PILA: ");
    int *temp = ptrs->arreglo;
    while (temp < *ptrs->ptr2)
    {
        printf("[%d] ", *temp);
        temp++;
    }
    printf("\n");
    return 0;
}
int menu()
{
    printf("--MENU--\n");
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. salir\n");
    printf("Ingresa la opcion\n");
    int op;
    scanf("%d", &op);
    return op;
}

int main(void){
    struct Pila pila, *miptr;
    int dato, num;
    miptr=&pila;
    miptr->ptr1=miptr->arreglo;
    miptr->ptr2=&miptr->ptr1;
    for (;;)
    {
        if (vacia(miptr) == 0)
            {
                mostrarpila(miptr);
            }
        int op = menu();
        switch (op)
        {
        case 1:
            if (llena(miptr) == 0)
            {
                printf("Ingresa el numero a insertar: ");
                scanf("%d", &num);
                meterpila(miptr, num);
            }
            else
                printf("No hay espacio en la pila\n");
            break;
        case 2:
            if (vacia(miptr) == 0)
            {
                sacarpila(miptr);
                printf("Dato sacado\n");
            }
            else
                printf("La pila esta vacia\n");
            break;
        case 3:
            printf("Saliendo del programa");
            return 0;
            break;
        default:
            printf("Opcion invalida, intente de nuevo\n");
            break;
        }
    }
    return 0;
}