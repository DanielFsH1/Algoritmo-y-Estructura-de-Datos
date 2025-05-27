/*
 * IMPLEMENTACIÓN DE COLA DINÁMICA CON TRIPLE APUNTADOR
 * 
 * Esta implementación utiliza triple nivel de indirección para manipular la cola,
 * lo que implica el uso de punteros a punteros a punteros (struct Nodo***).
 * 
 * Características:
 * - Utiliza dos punteros separados (frente y final) con triple nivel de indirección
 * - Demuestra el manejo avanzado de niveles de indirección en C
 * - Las funciones principales trabajan con struct Nodo*** frente y struct Nodo*** final
 * - Almacena datos simples (enteros)
 * 
 * Diferencia con otras implementaciones:
 * - Mayor nivel de indirección comparado con las versiones de cabecera simple y doble apuntador
 * - Requiere dereferenciación triple (**frente, **final) para acceder al contenido
 * - No usa una estructura contenedora para los punteros como la versión de cabecera simple
 * - A diferencia de las versiones compuestas, solo maneja datos simples
 */
#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Prototipos de funciones
int encolar(struct Nodo*** frente, struct Nodo*** final, int valor);
int desencolar(struct Nodo*** frente, struct Nodo*** final);
int estaVacia(struct Nodo** frente);
void mostrarCola(struct Nodo** frente);
int menu();

int main() {
    struct Nodo* frente = NULL;
    struct Nodo* final = NULL;
    struct Nodo** ptrFrente = &frente;
    struct Nodo** ptrFinal = &final;
    struct Nodo*** ptrPtrFrente = &ptrFrente;
    struct Nodo*** ptrPtrFinal = &ptrFinal;
    int valor;
    
    while (1) {
        switch (menu()) {
            case 1:
                printf("Ingrese el valor a encolar: ");
                scanf("%d", &valor);
                if (encolar(ptrPtrFrente, ptrPtrFinal, valor) == 0) {
                    printf("Valor encolado correctamente\n");
                    mostrarCola(ptrFrente);
                }
                break;
            case 2:
                if (!estaVacia(ptrFrente)) {
                    valor = desencolar(ptrPtrFrente, ptrPtrFinal);
                    printf("Valor desencolado: %d\n", valor);
                    mostrarCola(ptrFrente);
                } else {
                    printf("La cola está vacía\n");
                }
                break;
            case 3:
                mostrarCola(ptrFrente);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                // Liberar memoria antes de salir
                while (!estaVacia(ptrFrente)) {
                    desencolar(ptrPtrFrente, ptrPtrFinal);
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
// Función para encolar usando triple apuntador
int encolar(struct Nodo*** frente, struct Nodo*** final, int valor) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return -1;
    }
    
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    
    if (**final == NULL) {
        // Cola vacía
        **frente = nuevo;
        **final = nuevo;
    } else {
        // Agregar al final
        (**final)->siguiente = nuevo;
        **final = nuevo;
    }
    return 0;
}

// Función para desencolar usando triple apuntador
int desencolar(struct Nodo*** frente, struct Nodo*** final) {
    if (**frente == NULL) {
        printf("Error: Cola vacía\n");
        return -1;
    }
    
    struct Nodo* temp = **frente;
    int valor = temp->dato;
    
    **frente = (**frente)->siguiente;
    
    // Si la cola queda vacía
    if (**frente == NULL) {
        **final = NULL;
    }
    
    free(temp);
    return valor;
}

// Función para verificar si la cola está vacía
int estaVacia(struct Nodo** frente) {
    return *frente == NULL;
}

// Función para mostrar la cola
void mostrarCola(struct Nodo** frente) {
    if (*frente == NULL) {
        printf("Cola vacía\n");
        return;
    }
    
    printf("Cola: ");
    struct Nodo* actual = *frente;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Función del menú
int menu() {
    int opcion;
    printf("\n---- MENU COLA DINAMICA (TRIPLE APUNTADOR) ----\n");
    printf("1. Encolar\n");
    printf("2. Desencolar\n");
    printf("3. Mostrar cola\n");
    printf("4. Salir\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    return opcion;
}
