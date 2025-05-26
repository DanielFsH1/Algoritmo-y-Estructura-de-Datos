#include <stdio.h>

int longitud(char *cad) {
    if (*cad == '\0') return 0;
    return 1 + longitud(cad + 1);
}

int main() {
    char cadena[100];
    printf("Ingrese una cadena: ");
    scanf("%s", cadena);
    printf("La longitud de la cadena '%s' es: %d\n", cadena, longitud(cadena));
    return 0;
}
