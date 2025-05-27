/*
 * IMPLEMENTACIÓN DE COLA DINÁMICA COMPUESTA CON CABECERA SIMPLE
 * 
 * Esta implementación utiliza estructuras compuestas (struct Persona)
 * con una estructura Cola que contiene punteros al frente y final.
 * 
 * Características:
 * - Almacena datos compuestos (struct Persona con id, nombre y edad)
 * - Usa una estructura Cola para manejar los punteros frente y final
 * - Implementa la creación explícita de la cola con crearCola()
 * - Las funciones devuelven estructuras completas en lugar de valores simples
 * 
 * Diferencia con otras implementaciones:
 * - Combina las ventajas de la estructura contenedora con el manejo de datos compuestos
 * - Más orientada a objetos que las versiones que usan punteros directamente
 * - A diferencia de las versiones de doble y triple apuntador, encapsula los punteros
 * - Más organizada y fácil de extender que las versiones de punteros directos
 * - Usa un parámetro de éxito para manejo de errores, como las otras versiones compuestas
 */
#include <stdio.h>
#include <stdlib.h>

// Estructura de datos compuesta
struct Persona {
    int id;
    char nombre[50];
    int edad;
};

// Estructura del nodo
struct Nodo {
    struct Persona dato;
    struct Nodo* siguiente;
};

// Estructura de la cola con frente y final
struct Cola {
    struct Nodo* frente;
    struct Nodo* final;
};

// Prototipos de funciones
struct Cola* crearCola();
int encolar(struct Cola* cola, struct Persona persona);
struct Persona desencolar(struct Cola* cola, int* exito);
int estaVacia(struct Cola* cola);
void mostrarCola(struct Cola* cola);
int menu();

int main() {
    struct Cola* cola = crearCola();
    if (cola == NULL) return -1;
    
    struct Persona persona;
    int exito;
    
    while (1) {
        switch (menu()) {
            case 1:
                printf("Ingrese los datos de la persona:\n");
                printf("ID: ");
                scanf("%d", &persona.id);
                printf("Nombre: ");
                scanf("%s", persona.nombre);
                printf("Edad: ");
                scanf("%d", &persona.edad);
                
                if (encolar(cola, persona) == 0) {
                    printf("Persona encolada correctamente\n");
                    mostrarCola(cola);
                }
                break;
            case 2:
                if (!estaVacia(cola)) {
                    persona = desencolar(cola, &exito);
                    if (exito) {
                        printf("Persona desencolada:\n");
                        printf("ID: %d, Nombre: %s, Edad: %d\n", 
                               persona.id, persona.nombre, persona.edad);
                        mostrarCola(cola);
                    }
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
                    desencolar(cola, &exito);
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
int encolar(struct Cola* cola, struct Persona persona) {
    if (cola == NULL) {
        printf("Error: Cola no inicializada\n");
        return -1;
    }
    
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return -1;
    }
    
    nuevo->dato = persona;
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
struct Persona desencolar(struct Cola* cola, int* exito) {
    struct Persona personaVacia = {-1, "", -1};
    
    if (cola == NULL || cola->frente == NULL) {
        printf("Error: Cola vacía\n");
        *exito = 0;
        return personaVacia;
    }
    
    struct Nodo* temp = cola->frente;
    struct Persona persona = temp->dato;
    
    cola->frente = cola->frente->siguiente;
    
    // Si la cola queda vacía
    if (cola->frente == NULL) {
        cola->final = NULL;
    }
    
    free(temp);
    *exito = 1;
    return persona;
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
    
    printf("\n=== CONTENIDO DE LA COLA ===\n");
    struct Nodo* actual = cola->frente;
    int posicion = 1;
    while (actual != NULL) {
        printf("Posición %d:\n", posicion);
        printf("  ID: %d\n", actual->dato.id);
        printf("  Nombre: %s\n", actual->dato.nombre);
        printf("  Edad: %d\n", actual->dato.edad);
        printf("  ----------------\n");
        actual = actual->siguiente;
        posicion++;
    }
    printf("============================\n");
}

// Función del menú
int menu() {
    int opcion;
    printf("\n---- MENU COLA DINAMICA (ESTRUCTURA COMPUESTA) ----\n");
    printf("1. Encolar persona\n");
    printf("2. Desencolar persona\n");
    printf("3. Mostrar cola\n");
    printf("4. Salir\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    return opcion;
}
