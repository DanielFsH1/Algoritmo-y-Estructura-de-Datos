// 9/05/2025
// operaciones con recursión

#include <stdio.h>

int multiplicacion(int num1, int num2);
int potencia(int num1, int num2);
int potencia_mult(int num1, int num2);
int suma(int num1, int num2);
int factorial(int num1);

int main(){
    printf("----programa de multiplicación y potencias por recursión----\n");
    int opcion, num1, num2, resultado;
    for(;;){
        printf("1. para multiplicación.\n2. para potencias.\n3. para suma. \n4. para factorial. \n5. Para  salir.\n");
        printf("ingrese opción: ");
        scanf("%d", &opcion);
        switch (opcion){
            // multiplicación
            case 1:
                printf("ingrese número base: ");
                scanf("%d", &num1);
                printf("ingrese cuántas veces lo quiere multiplicar: ");
                scanf("%d", &num2);
                resultado = multiplicacion(num1, num2);
                printf("resultado: %d\n", resultado);
                printf("\n");
                break;
            // potencia
            case 2:
                printf("ingrese número base: ");
                scanf("%d", &num1);
                printf("ingrese el número potencia: ");
                scanf("%d", &num2);
                resultado = potencia(num1, num2);
                printf("resultado usando función `potencia`: %d\n", resultado);
                resultado = potencia_mult(num1, num2);
                printf("resultado usando función `multiplicación`: %d\n", resultado);
                printf("\n");
                break;
            // suma
            case 3:
                printf("ingrese el primer número: ");
                scanf("%d", &num1);
                printf("ingrese el segundo número: ");
                scanf("%d", &num2);
                resultado = suma(num1, num2);
                printf("resultado: %d\n", resultado);
                printf("\n");
                break;
            // factorial
            case 4:
                printf("ingrese el número: ");
                scanf("%d", &num1);
                resultado = factorial(num1);
                printf("resultado: %d\n", resultado);
                printf("\n");
                break;
            case 5:
                printf("saliendo del programa...\n");
                return 0;
            default:
                printf("Ingresa una opción válida\n");
        }
    }
}

int multiplicacion(int num1, int num2) {
    if (num2 == 0 || num1 == 0) {
        return 0;
    }
    return num1 + multiplicacion(num1, num2 - 1);
}

int potencia(int num1, int num2){
    if (num2==0){
        return 1;
    }else{
        return num1 * potencia(num1, num2-1);
    }
}

int potencia_mult(int num1, int num2) {
    if (num2 == 0) {
        return 1;
    } else {
        int resultado = 1;
        for (int i = 0; i < num2; i++) {
            resultado = multiplicacion(resultado, num1);
        }
        return resultado;
    }
}

int suma(int num1, int num2){
    if (num2 == 0) {
        return num1;
    } else if (num1 == 0) {
        return num2;
    } else if (num1 == 0 && num2 == 0) {
        return 0;    
    }else {
        return suma(num1 + 1, num2 - 1);
    }
}

int factorial(int num1){
    if (num1 == 0) {
        return 1;
    } else {
        return num1 * factorial(num1 - 1);
    }
}
