// 13/05/2025
#include <stdio.h>

// Función de Ackermann recursiva
unsigned int ackermann(unsigned int m, unsigned int n);

int main() {
    unsigned int m, n;
    printf("Ingrese el valor de m: ");
    scanf("%u", &m);
    printf("Ingrese el valor de n: ");
    scanf("%u", &n);

    printf("Ackermann(%u, %u) = %u\n", m, n, ackermann(m, n));
    return 0;
}

/*
Solo toma valores enteros no negativos.
Su crecimiento es extremadamente rápido, por lo que incluso para valores pequeños
puede tardar mucho o causar desbordamiento de pila.
Definición:
A(0, n) = n + 1
A(m, 0) = A(m - 1, 1) si m > 0
A(m, n) = A(m - 1, A(m, n - 1)) si m > 0 y n > 0
*/
unsigned int ackermann(unsigned int m, unsigned int n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return ackermann(m - 1, 1);
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}
