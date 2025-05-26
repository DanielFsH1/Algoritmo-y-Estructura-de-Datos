#include <stdio.h>

struct Datos {
    int numeros[5];
    int i;
};

int main (){
    struct Datos dato;
    for(dato.i=0; dato.i<5; dato.i=dato.i+1){
        printf("Ingresa el dato numero %d: ", dato.i+1);
        scanf("%d",&dato.numeros[dato.i]);
    }

    for(dato.i=0; dato.i<5; dato.i++){
        printf("\nEn la celda #%d esta el dato %d con la direccion %lu", dato.i, dato.numeros[dato.i], &dato.numeros[dato.i]);
    }

    return 0;
}