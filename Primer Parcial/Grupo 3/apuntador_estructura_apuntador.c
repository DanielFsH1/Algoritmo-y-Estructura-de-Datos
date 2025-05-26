#include <stdio.h>

struct Datos {
    int numeros[5];
    int *ptr;
};

int main (){
    struct Datos dato, *ptrd;
    ptrd=&dato;
    for(ptrd->ptr=ptrd->numeros; ptrd->ptr<&ptrd->numeros[5]; ptrd->ptr++){
        printf("Ingresa el dato numero %d: ", (int)(ptrd->ptr-ptrd->numeros)+1);
        scanf("%d",ptrd->ptr);
    }

    for(ptrd->ptr=ptrd->numeros; ptrd->ptr<&ptrd->numeros[5]; ptrd->ptr++){
        printf("\nEn la celda #%d esta el dato %d con la direccion %lu", (int)(ptrd->ptr-ptrd->numeros), *ptrd->ptr, ptrd->ptr);
    }

    return 0;
}