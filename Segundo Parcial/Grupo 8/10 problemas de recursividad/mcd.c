// 13/05/2025
// Máximo común divisor (algoritmo de Euclides)

#include <stdio.h>

int mcd(int a, int b);
int mcd_arreglo(int arr[], int numeros);

int main() {
    int numeros;
    printf("¿Cuántos números quieres ingresar? ");
    scanf("%d", &numeros);
    if (numeros < 2) {
        printf("Debes ingresar al menos dos números.\n");
        return 0;
    }
    int arreglo[numeros];
    for (int i = 0; i < numeros; i++) {
        printf("Ingresa el número %d: ", i + 1);
        scanf("%d", &arreglo[i]);
    }
    printf("El MCD de los números ingresados es %d\n", mcd_arreglo(arreglo, numeros));
    return 0;
}

/*
El algoritmo de Euclides para calcular el MCD:
1. si b es 0, entonces el MCD es a.
2. Si b no es 0, se calcula el MCD de b y el residuo de a entre b (a % b).
3. Este proceso se repite recursivamente hasta que b sea 0.
Ejemplo:
    MCD(48, 18)
    48 % 18 = 12 -> MCD(18, 12)
    18 % 12 = 6  -> MCD(12, 6)
    12 % 6 = 0   -> MCD(6, 0)
    Resultado: 6
*/

int mcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return mcd(b, a % b);
}

// Calcula el MCD de un arreglo de números de manera recursiva
/*
1. Si hay más de dos números, se calcula el MCD del primer número con el resultado del MCD del resto del arreglo.
2. Este proceso se repite recursivamente hasta reducir el arreglo a dos elementos.
Ejemplo:
    Para el arreglo [24, 36, 60]:
    - Primero se calcula MCD(24, MCD(36, 60))
    - MCD(36, 60) = 12
    - MCD(24, 12) = 12
    Resultado: 12
*/
int mcd_arreglo(int arr[], int n) {
    if (n == 2)
        return mcd(arr[0], arr[1]);
    else
        return mcd(arr[0], mcd_arreglo(arr + 1, n - 1));
}
