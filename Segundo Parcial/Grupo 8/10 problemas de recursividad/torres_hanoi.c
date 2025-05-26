#include <stdio.h>

void hanoi(int n, char origen, char auxiliar, char destino);

int main() {
    int n;
    printf("Ingrese el número de discos: ");
    scanf("%d", &n);
    printf("Los pasos para resolver las Torres de Hanoi son:\n");
    hanoi(n, 'A', 'B', 'C');
    return 0;
}

/*
Mover una torre de n discos desde el poste de origen hasta el poste de destino, usando un poste auxiliar.
mientras mayor sea el número, mayor será el disco.
Reglas:
- Solo se puede mover un disco a la vez.
- Un disco más grande no puede estar encima de uno más pequeño.
*/
void hanoi(int n, char origen, char auxiliar, char destino) {
    if (n == 1) { // Si solo hay un disco, se mueve directamente del origen al destino.
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }
    hanoi(n - 1, origen, destino, auxiliar);
    printf("Mover disco %d de %c a %c\n", n, origen, destino);
    hanoi(n - 1, auxiliar, origen, destino);
}
