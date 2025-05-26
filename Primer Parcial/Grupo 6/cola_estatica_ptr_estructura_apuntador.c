#include <stdio.h>
#define TAM 5

struct Cola
{
    int arreglo[TAM];
    int *ptrm;
    int *ptrs;
};

int resetear(struct Cola *);
int meter(struct Cola *, int);
int sacar(struct Cola *);
int vacio(struct Cola *);
int lleno(struct Cola *);
int menu();
int visualizar(struct Cola *);

int resetear(struct Cola *ptrc)
{
    ptrc->ptrm = ptrc->arreglo;
    ptrc->ptrs = ptrc->arreglo;

    return 0;
}

int meter(struct Cola *ptrc, int dato)
{
    *ptrc->ptrm = dato;
    ptrc->ptrm++;
    return 0;
}

int sacar(struct Cola *ptrc)
{
    int aux;
    aux = *ptrc->ptrs;
    ptrc->ptrs++;
    return aux;
}

int vacio(struct Cola *ptrc)
{
    if (ptrc->ptrm == ptrc->ptrs)
        return 1;
    else
        return 0;
}

int lleno(struct Cola *ptrc)
{
    if (ptrc->ptrm == &ptrc->arreglo[TAM])
        return 1;
    else
        return 0;
}

int visualizar(struct Cola *ptrc){
    printf("\nCola: ");
    for (int *ptr = ptrc->ptrs; ptr < ptrc->ptrm; ptr++)
    {
        printf("%d ", *ptr);
    }
    printf("\n");
    return 0;
}

int menu()
{
    int op;
    printf("----MENU---");
    printf("\n1. Insertar");
    printf("\n2. Sacar");
    printf("\n3. Salir\n");
    printf("Ingresa la opcion: ");
    scanf("%d", &op);
    fflush(stdin);
    return op;
}

int main()
{

    int dato;
    struct Cola cola, *miptrc;

    miptrc = &cola;
    resetear(miptrc);
    for (;;)
    {
        switch (menu())
        {
        case 1:
            if (lleno(miptrc))
                printf("\nCOLA LLENA\n");
            else
            {
                printf("Ingresa el dato a meter: ");
                scanf("%d", &dato);
                fflush(stdin);
                meter(miptrc, dato);
                visualizar(miptrc);
            }
            break;
        
        case 2: 
            if(vacio(miptrc))
                printf("\nCOLA VACIA\n");
            else{
                printf("DATO SACADO: %d", sacar(miptrc));
                visualizar(miptrc);
            }
            break;
        default:
            return 0;
            break;
        }
    }
    return 0;
}