/*
 * IMPLEMENTACIÓN DE COLA DINÁMICA CON CABECERA SIMPLE
 * 
 * Esta implementación utiliza una estructura Cola que contiene punteros
 * al frente y final de la cola.
 * 
 * Características:
 * - Usa una estructura Cola para manejar los punteros frente y final
 * - Implementa la creación explícita de la cola con crearCola()
 * - Mantiene los punteros dentro de la estructura Cola
 * - Almacena datos simples (enteros)
 * 
 * Diferencia con otras implementaciones:
 * - A diferencia de las versiones de doble y triple apuntador, encapsula los punteros
 *   en una estructura dedicada
 * - Más orientada a objetos que las versiones que usan punteros directamente
 * - No requiere pasar múltiples punteros a las funciones, solo el puntero a la estructura
 * - A diferencia de las versiones compuestas, solo maneja datos simples (enteros)
 */
#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Estructura de la cola con frente y final
struct Cola {
    struct Nodo* frente;
    struct Nodo* final;
};

// Prototipos de funciones
struct Cola* crearCola();
int encolar(struct Cola* cola, int valor);
int desencolar(struct Cola* cola);
int estaVacia(struct Cola* cola);
void mostrarCola(struct Cola* cola);
int menu();

int main() {
    struct Cola* cola = crearCola();
    if (cola == NULL) return -1;
    
    int valor;
    
    while (1) {
        switch (menu()) {
            case 1:
                printf("Ingrese el valor a encolar: ");
                scanf("%d", &valor);
                if (encolar(cola, valor) == 0) {
                    printf("Valor encolado correctamente\n");
                    mostrarCola(cola);
                }
                break;
            case 2:
                if (!estaVacia(cola)) {
                    valor = desencolar(cola);
                    printf("Valor desencolado: %d\n", valor);
                    mostrarCola(cola);
                } else {
                    printf("La cola está vacía\n");
                }
                break;
            case 3:
                mostrarCola(cola);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                // Liberar memoria antes de salir
                while (!estaVacia(cola)) {
                    desencolar(cola);
                }
                free(cola);
                return 0;
            default:
                printf("Opción inválida\n");
                break;
        }
    }
    return 0;
}

// Definiciones de funciones
// Función para crear una cola vacía
struct Cola* crearCola() {
    struct Cola* cola = (struct Cola*)malloc(sizeof(struct Cola));
    if (cola == NULL) {
        printf("Error: No se pudo asignar memoria para la cola\n");
        return NULL;
    }
    cola->frente = NULL;
    cola->final = NULL;
    return cola;
}

// Función para encolar (enqueue)
int encolar(struct Cola* cola, int valor) {
    if (cola == NULL) {
        printf("Error: Cola no inicializada\n");
        return -1;
    }
    
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return -1;
    }
    
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    
    if (cola->final == NULL) {
        // Cola vacía
        cola->frente = nuevo;
        cola->final = nuevo;
    } else {
        // Agregar al final
        cola->final->siguiente = nuevo;
        cola->final = nuevo;
    }
    return 0;
}

// Función para desencolar (dequeue)
int desencolar(struct Cola* cola) {
    if (cola == NULL || cola->frente == NULL) {
        printf("Error: Cola vacía\n");
        return -1;
    }
    
    struct Nodo* temp = cola->frente;
    int valor = temp->dato;
    
    cola->frente = cola->frente->siguiente;
    
    // Si la cola queda vacía
    if (cola->frente == NULL) {
        cola->final = NULL;
    }
    
    free(temp);
    return valor;
}

// Función para verificar si la cola está vacía
int estaVacia(struct Cola* cola) {
    return (cola == NULL || cola->frente == NULL);
}

// Función para mostrar la cola
void mostrarCola(struct Cola* cola) {
    if (estaVacia(cola)) {
        printf("Cola vacía\n");
        return;
    }
    
    printf("Cola: ");
    struct Nodo* actual = cola->frente;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Función del menú
int menu() {
    int opcion;
    printf("\n---- MENU COLA DINAMICA ----\n");
    printf("1. Encolar\n");
    printf("2. Desencolar\n");
    printf("3. Mostrar cola\n");
    printf("4. Salir\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    return opcion;
}
