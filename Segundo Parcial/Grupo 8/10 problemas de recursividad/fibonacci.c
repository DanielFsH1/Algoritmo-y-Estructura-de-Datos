#include <stdio.h>

int fibonacci(int n);

int main() {
    int n;
    printf("¿Cuántos términos de la serie de Fibonacci quieres mostrar?: ");
    scanf("%d", &n);

    printf("Serie de Fibonacci:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}

// Función recursiva para calcular el n-ésimo término de Fibonacci
/* explicación:
La serie de Fibonacci es una sucesión de números en la que cada número es la suma de los dos anteriores.
Los dos primeros términos son 0 y 1. Es decir:
    Fibonacci(0) = 0
    Fibonacci(1) = 1
    Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2) para n > 1

Ejemplo de los primeros términos:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
*/
int fibonacci(int n) {
    if (n == 0)
        return 0; // Caso base: Fibonacci(0) = 0
    else if (n == 1)
        return 1;  // Caso base: Fibonacci(1) = 1
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
