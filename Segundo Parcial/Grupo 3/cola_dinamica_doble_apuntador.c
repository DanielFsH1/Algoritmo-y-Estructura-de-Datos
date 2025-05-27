/*
 * IMPLEMENTACIÓN DE COLA DINÁMICA CON DOBLE APUNTADOR
 * 
 * Esta implementación utiliza doble nivel de indirección para manipular la cola,
 * con punteros a punteros (struct Nodo**) para frente y final.
 * 
 * Características:
 * - Utiliza dos punteros separados (frente y final) con doble nivel de indirección
 * - Las funciones reciben struct Nodo** frente y struct Nodo** final
 * - Almacena datos simples (enteros)
 * - Implementa las operaciones básicas: encolar, desencolar, mostrar
 * 
 * Diferencia con otras implementaciones:
 * - Nivel intermedio de indirección entre la cabecera simple y triple apuntador
 * - No usa una estructura contenedora para los punteros como la versión de cabecera simple
 * - Pasa las direcciones de los punteros a las funciones (&frente, &final)
 * - A diferencia de las versiones compuestas, solo maneja datos simples
 * - Más simple que la versión triple apuntador pero requiere pasar dos punteros por referencia
 */
#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Prototipos de funciones
int encolar(struct Nodo** frente, struct Nodo** final, int valor);
int desencolar(struct Nodo** frente, struct Nodo** final);
int estaVacia(struct Nodo* frente);
void mostrarCola(struct Nodo* frente);
int menu();

int main() {
    struct Nodo* frente = NULL;
    struct Nodo* final = NULL;
    int valor;
    
    while (1) {
        switch (menu()) {
            case 1:
                printf("Ingrese el valor a encolar: ");
                scanf("%d", &valor);
                if (encolar(&frente, &final, valor) == 0) {
                    printf("Valor encolado correctamente\n");
                    mostrarCola(frente);
                }
                break;
            case 2:
                if (!estaVacia(frente)) {
                    valor = desencolar(&frente, &final);
                    printf("Valor desencolado: %d\n", valor);
                    mostrarCola(frente);
                } else {
                    printf("La cola está vacía\n");
                }
                break;
            case 3:
                mostrarCola(frente);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                // Liberar memoria antes de salir
                while (!estaVacia(frente)) {
                    desencolar(&frente, &final);
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
// Función para encolar usando doble apuntador
int encolar(struct Nodo** frente, struct Nodo** final, int valor) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return -1;
    }
    
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    
    if (*final == NULL) {
        // Cola vacía
        *frente = nuevo;
        *final = nuevo;
    } else {
        // Agregar al final
        (*final)->siguiente = nuevo;
        *final = nuevo;
    }
    return 0;
}

// Función para desencolar usando doble apuntador
int desencolar(struct Nodo** frente, struct Nodo** final) {
    if (*frente == NULL) {
        printf("Error: Cola vacía\n");
        return -1;
    }
    
    struct Nodo* temp = *frente;
    int valor = temp->dato;
    
    *frente = (*frente)->siguiente;
    
    // Si la cola queda vacía
    if (*frente == NULL) {
        *final = NULL;
    }
    
    free(temp);
    return valor;
}

// Función para verificar si la cola está vacía
int estaVacia(struct Nodo* frente) {
    return frente == NULL;
}

// Función para mostrar la cola
void mostrarCola(struct Nodo* frente) {
    if (frente == NULL) {
        printf("Cola vacía\n");
        return;
    }
    
    printf("Cola: ");
    struct Nodo* actual = frente;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Función del menú
int menu() {
    int opcion;
    printf("\n---- MENU COLA DINAMICA (DOBLE APUNTADOR) ----\n");
    printf("1. Encolar\n");
    printf("2. Desencolar\n");
    printf("3. Mostrar cola\n");
    printf("4. Salir\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    return opcion;
}
