#include <stdio.h>

struct Datos {
    int numeros[5];
    int *ptr;
};

int main (){
    struct Datos dato;
    for(dato.ptr=dato.numeros; dato.ptr<&dato.numeros[5]; dato.ptr++){
        printf("Ingresa el dato numero %d: ", (int)(dato.ptr-dato.numeros)+1);
        scanf("%d",dato.ptr);
    }

    for(dato.ptr=dato.numeros; dato.ptr<&dato.numeros[5]; dato.ptr++){
        printf("\nEn la celda #%d esta el dato %d con la direccion %lu", (int)(dato.ptr-dato.numeros), *dato.ptr, dato.ptr);
    }

    return 0;
}