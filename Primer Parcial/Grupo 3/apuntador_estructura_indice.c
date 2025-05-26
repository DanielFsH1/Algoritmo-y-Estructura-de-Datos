#include <stdio.h>

struct Datos {
    int numeros[5];
    int i;
};

int main (){
    struct Datos dato, *ptrd;
    ptrd=&dato;
    for(ptrd->i=0; ptrd->i<5; ptrd->i++){
        printf("Ingresa el dato numero %d: ", ptrd->i+1);
        scanf("%d",&ptrd->numeros[ptrd->i]);
    }

    for(ptrd->i=0; ptrd->i<5; ptrd->i++){
        printf("\nEn la celda #%d esta el dato %d con la direccion %lu", ptrd->i+1, ptrd->numeros[ptrd->i], &ptrd->numeros[ptrd->i]);
    }

    return 0;
}