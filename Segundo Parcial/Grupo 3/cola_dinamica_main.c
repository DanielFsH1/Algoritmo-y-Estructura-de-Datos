/*
 * IMPLEMENTACIÓN DE COLA DINÁMICA COMPLETA
 * 
 * Esta implementación es la más completa y funcional, con una estructura Cola
 * que incluye frente, final y tamaño, además de múltiples operaciones adicionales.
 * 
 * Características:
 * - Usa una estructura Cola completa (frente, final y tamaño)
 * - Implementa más operaciones que las otras versiones: frente(), final(), tamaño()
 * - Incluye funciones para limpiar y destruir la cola
 * - Proporciona un menú más detallado con más opciones
 * - Usa mensajes más informativos y formateo mejorado en la salida
 * 
 * Diferencia con otras implementaciones:
 * - Mantiene el conteo del tamaño de la cola (las otras versiones no lo hacen)
 * - Incluye funciones adicionales para consultar elementos sin desencolados
 * - Implementa destrucción controlada de la cola con liberación de memoria
 * - Interfaz de usuario más completa y amigable
 * - Mejor gestión de errores y casos especiales
 */
#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Estructura de la cola
struct Cola {
    struct Nodo* frente;
    struct Nodo* final;
    int tamaño;
};

// Prototipos de funciones
struct Cola* crearCola();
int encolar(struct Cola* cola, int valor);
int desencolar(struct Cola* cola);
int frente(struct Cola* cola);
int final(struct Cola* cola);
int tamaño(struct Cola* cola);
int estaVacia(struct Cola* cola);
void mostrarCola(struct Cola* cola);
void limpiarCola(struct Cola* cola);
void destruirCola(struct Cola** cola);
int menu();

int main() {
    struct Cola* cola = crearCola();
    if (cola == NULL) return -1;
    
    int valor;
    
    printf("=== PROGRAMA DE MANEJO DE COLA DINAMICA ===\n");
    printf("Este programa demuestra las operaciones básicas de una cola dinámica\n");
    
    while (1) {
        switch (menu()) {
            case 1:
                printf("Ingrese el valor a encolar: ");
                scanf("%d", &valor);
                if (encolar(cola, valor) == 0) {
                    printf("✓ Valor %d encolado correctamente\n", valor);
                    mostrarCola(cola);
                }
                break;
                
            case 2:
                if (!estaVacia(cola)) {
                    valor = desencolar(cola);
                    printf("✓ Valor desencolado: %d\n", valor);
                    mostrarCola(cola);
                } else {
                    printf("✗ La cola está vacía\n");
                }
                break;
                
            case 3:
                if (!estaVacia(cola)) {
                    printf("Frente de la cola: %d\n", frente(cola));
                } else {
                    printf("✗ La cola está vacía\n");
                }
                break;
                
            case 4:
                if (!estaVacia(cola)) {
                    printf("Final de la cola: %d\n", final(cola));
                } else {
                    printf("✗ La cola está vacía\n");
                }
                break;
                
            case 5:
                mostrarCola(cola);
                break;
                
            case 6:
                printf("Tamaño actual de la cola: %d elementos\n", tamaño(cola));
                break;
                
            case 7:
                if (estaVacia(cola)) {
                    printf("✓ La cola está vacía\n");
                } else {
                    printf("✗ La cola NO está vacía (tiene %d elementos)\n", tamaño(cola));
                }
                break;
                
            case 8:
                limpiarCola(cola);
                break;
                
            case 9:
                printf("Saliendo del programa...\n");
                destruirCola(&cola);
                printf("¡Hasta luego!\n");
                return 0;
                
            default:
                printf("✗ Opción inválida. Por favor, ingrese un número del 1 al 9.\n");
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
    cola->tamaño = 0;
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
    cola->tamaño++;
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
    
    cola->tamaño--;
    free(temp);
    return valor;
}

// Función para obtener el elemento del frente sin eliminarlo
int frente(struct Cola* cola) {
    if (cola == NULL || cola->frente == NULL) {
        printf("Error: Cola vacía\n");
        return -1;
    }
    return cola->frente->dato;
}

// Función para obtener el elemento del final sin eliminarlo
int final(struct Cola* cola) {
    if (cola == NULL || cola->final == NULL) {
        printf("Error: Cola vacía\n");
        return -1;
    }
    return cola->final->dato;
}

// Función para obtener el tamaño de la cola
int tamaño(struct Cola* cola) {
    if (cola == NULL) return 0;
    return cola->tamaño;
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
    
    printf("Cola (tamaño: %d): ", cola->tamaño);
    struct Nodo* actual = cola->frente;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Función para limpiar la cola
void limpiarCola(struct Cola* cola) {
    if (cola == NULL) return;
    
    while (!estaVacia(cola)) {
        desencolar(cola);
    }
    printf("Cola limpiada\n");
}

// Función para destruir la cola
void destruirCola(struct Cola** cola) {
    if (*cola == NULL) return;
    
    limpiarCola(*cola);
    free(*cola);
    *cola = NULL;
    printf("Cola destruida\n");
}

// Función del menú
int menu() {
    int opcion;
    printf("\n========== MENU PRINCIPAL COLA DINAMICA ==========\n");
    printf("1. Encolar elemento\n");
    printf("2. Desencolar elemento\n");
    printf("3. Ver frente de la cola\n");
    printf("4. Ver final de la cola\n");
    printf("5. Mostrar cola completa\n");
    printf("6. Mostrar tamaño\n");
    printf("7. Verificar si está vacía\n");
    printf("8. Limpiar cola\n");
    printf("9. Salir\n");
    printf("================================================\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    return opcion;
}
