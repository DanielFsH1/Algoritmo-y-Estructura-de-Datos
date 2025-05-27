/*
 * IMPLEMENTACIÓN DE PILA DINÁMICA CON TRIPLE APUNTADOR
 * 
 * Esta implementación utiliza triple nivel de indirección para manipular la pila,
 * lo que implica el uso de punteros a punteros a punteros (struct Nodo***).
 * 
 * Características:
 * - Utiliza un triple apuntador para las operaciones sobre la pila
 * - Demuestra el manejo avanzado de niveles de indirección
 * - Las funciones principales trabajan con struct Nodo*** tope
 * - Almacena datos simples (enteros)
 * 
 * Diferencia con otras implementaciones:
 * - Mayor nivel de indirección comparado con las versiones de cabecera simple y doble apuntador
 * - Requiere dereferenciación triple (**tope) para acceder al contenido
 * - Útil para entender conceptos avanzados de punteros en C
 * - A diferencia de las versiones compuestas, solo maneja datos simples
 */
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Prototipos de funciones
int apilar(struct Nodo*** tope, int valor);
int desapilar(struct Nodo*** tope);
int estaVacia(struct Nodo** tope);
void mostrarPila(struct Nodo** tope);
int menu();

int main() {
    struct Nodo* pila = NULL;
    struct Nodo** ptrPila = &pila;
    struct Nodo*** ptrPtrPila = &ptrPila;
    int valor;
    
    while (1) {
        switch (menu()) {
            case 1:
                printf("Ingrese el valor a apilar: ");
                scanf("%d", &valor);
                if (apilar(ptrPtrPila, valor) == 0) {
                    printf("Valor apilado correctamente\n");
                    mostrarPila(ptrPila);
                }
                break;
            case 2:
                if (!estaVacia(ptrPila)) {
                    valor = desapilar(ptrPtrPila);
                    printf("Valor desapilado: %d\n", valor);
                    mostrarPila(ptrPila);
                } else {
                    printf("La pila está vacía\n");
                }
                break;
            case 3:
                mostrarPila(ptrPila);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                // Liberar memoria antes de salir
                while (!estaVacia(ptrPila)) {
                    desapilar(ptrPtrPila);
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
// Función para apilar usando triple apuntador
int apilar(struct Nodo*** tope, int valor) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return -1;
    }
    nuevo->dato = valor;
    nuevo->siguiente = **tope;
    **tope = nuevo;
    return 0;
}

// Función para desapilar usando triple apuntador
int desapilar(struct Nodo*** tope) {
    if (**tope == NULL) {
        printf("Error: Pila vacía\n");
        return -1;
    }
    struct Nodo* temp = **tope;
    int valor = temp->dato;
    **tope = (**tope)->siguiente;
    free(temp);
    return valor;
}

// Función para verificar si la pila está vacía
int estaVacia(struct Nodo** tope) {
    return *tope == NULL;
}

// Función para mostrar la pila
void mostrarPila(struct Nodo** tope) {
    if (*tope == NULL) {
        printf("Pila vacía\n");
        return;
    }
    printf("Pila: ");
    struct Nodo* actual = *tope;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Función del menú
int menu() {
    int opcion;
    printf("\n---- MENU PILA DINAMICA TRIPLE APUNTADOR ----\n");
    printf("1. Apilar\n");
    printf("2. Desapilar\n");
    printf("3. Mostrar pila\n");
    printf("4. Salir\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    return opcion;
}
