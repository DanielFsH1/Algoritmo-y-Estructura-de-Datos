#include <stdio.h>

void invertir(char *cad) {
    if (*cad == '\0') return;
    invertir(cad + 1);
    putchar(*cad);
}

int main() {
    char cadena[100];
    printf("Ingrese una cadena: ");
    scanf("%s", cadena);
    printf("La cadena invertida es: ");
    invertir(cadena);
    printf("\n");
    return 0;
}
