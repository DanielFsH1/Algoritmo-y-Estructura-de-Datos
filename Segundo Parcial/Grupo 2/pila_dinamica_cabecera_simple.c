/*
 * IMPLEMENTACIÓN DE PILA DINÁMICA CON CABECERA SIMPLE
 * 
 * Esta implementación utiliza un único puntero (struct Nodo* pila) para
 * mantener la referencia al tope de la pila.
 * 
 * Características:
 * - Usa un puntero simple como cabecera
 * - Las funciones reciben un doble puntero (&pila) para modificar la cabecera
 * - Implementa las operaciones básicas: apilar, desapilar, mostrar
 * - Almacena datos simples (enteros)
 * 
 * Diferencia con otras implementaciones:
 * - A diferencia de la versión de doble apuntador, aquí se pasa la dirección 
 *   del puntero directamente en cada llamada
 * - A diferencia de la versión triple apuntador, tiene un nivel menos de indirección
 * - A diferencia de las versiones compuestas, solo maneja datos simples (enteros)
 */
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Prototipos de funciones
int apilar(struct Nodo** tope, int valor);
int desapilar(struct Nodo** tope);
int estaVacia(struct Nodo* tope);
void mostrarPila(struct Nodo* tope);
int menu();

int main() {
    struct Nodo* pila = NULL;
    int valor;
    
    while (1) {
        switch (menu()) {
            case 1:
                printf("Ingrese el valor a apilar: ");
                scanf("%d", &valor);
                if (apilar(&pila, valor) == 0) {
                    printf("Valor apilado correctamente\n");
                    mostrarPila(pila);
                }
                break;
            case 2:
                if (!estaVacia(pila)) {
                    valor = desapilar(&pila);
                    printf("Valor desapilado: %d\n", valor);
                    mostrarPila(pila);
                } else {
                    printf("La pila está vacía\n");
                }
                break;
            case 3:
                mostrarPila(pila);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                // Liberar memoria antes de salir
                while (!estaVacia(pila)) {
                    desapilar(&pila);
                }
                return 0;
            default:
                printf("Opción inválida\n");
                break;
        }
    }
    return 0;
}

// Definiciones de funciones
// Función para apilar (push)
int apilar(struct Nodo** tope, int valor) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return -1;
    }
    nuevo->dato = valor;
    nuevo->siguiente = *tope;
    *tope = nuevo;
    return 0;
}

// Función para desapilar (pop)
int desapilar(struct Nodo** tope) {
    if (*tope == NULL) {
        printf("Error: Pila vacía\n");
        return -1;
    }
    struct Nodo* temp = *tope;
    int valor = temp->dato;
    *tope = (*tope)->siguiente;
    free(temp);
    return valor;
}

// Función para verificar si la pila está vacía
int estaVacia(struct Nodo* tope) {
    return tope == NULL;
}

// Función para mostrar la pila
void mostrarPila(struct Nodo* tope) {
    if (tope == NULL) {
        printf("Pila vacía\n");
        return;
    }
    printf("Pila: ");
    struct Nodo* actual = tope;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Función del menú
int menu() {
    int opcion;
    printf("\n---- MENU PILA DINAMICA ----\n");
    printf("1. Apilar\n");
    printf("2. Desapilar\n");
    printf("3. Mostrar pila\n");
    printf("4. Salir\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    return opcion;
}
