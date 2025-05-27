/*
 * IMPLEMENTACIÓN DE COLA DINÁMICA COMPUESTA CON DOBLE APUNTADOR
 * 
 * Esta implementación utiliza estructuras compuestas (struct Persona) 
 * junto con doble nivel de indirección para las operaciones de la cola.
 * 
 * Características:
 * - Almacena datos compuestos (struct Persona con id, nombre y edad)
 * - Utiliza doble nivel de indirección (struct Nodo**)
 * - Las funciones devuelven estructuras completas en lugar de valores simples
 * - Usa un parámetro adicional para indicar el éxito o fracaso de la operación
 * 
 * Diferencia con otras implementaciones:
 * - Similar a la versión triple apuntador compuesta pero con un nivel menos de indirección
 * - Más directa que la versión triple pero requiere pasar las direcciones de los punteros
 * - A diferencia de las versiones simples, devuelve estructuras completas
 * - Incluye manejo de errores mediante un parámetro de éxito por referencia
 * - A diferencia de la versión de cabecera simple, maneja dos punteros separados
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

// Prototipos de funciones
int encolar(struct Nodo** frente, struct Nodo** final, struct Persona persona);
struct Persona desencolar(struct Nodo** frente, struct Nodo** final, int* exito);
int estaVacia(struct Nodo* frente);
void mostrarCola(struct Nodo* frente);
int menu();

int main() {
    struct Nodo* frente = NULL;
    struct Nodo* final = NULL;
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
                
                if (encolar(&frente, &final, persona) == 0) {
                    printf("Persona encolada correctamente\n");
                    mostrarCola(frente);
                }
                break;
            case 2:
                if (!estaVacia(frente)) {
                    persona = desencolar(&frente, &final, &exito);
                    if (exito) {
                        printf("Persona desencolada:\n");
                        printf("ID: %d, Nombre: %s, Edad: %d\n", 
                               persona.id, persona.nombre, persona.edad);
                        mostrarCola(frente);
                    }
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
                    desencolar(&frente, &final, &exito);
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
int encolar(struct Nodo** frente, struct Nodo** final, struct Persona persona) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return -1;
    }
    
    nuevo->dato = persona;
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
struct Persona desencolar(struct Nodo** frente, struct Nodo** final, int* exito) {
    struct Persona personaVacia = {-1, "", -1};
    
    if (*frente == NULL) {
        printf("Error: Cola vacía\n");
        *exito = 0;
        return personaVacia;
    }
    
    struct Nodo* temp = *frente;
    struct Persona persona = temp->dato;
    
    *frente = (*frente)->siguiente;
    
    // Si la cola queda vacía
    if (*frente == NULL) {
        *final = NULL;
    }
    
    free(temp);
    *exito = 1;
    return persona;
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
    
    printf("\n=== CONTENIDO DE LA COLA ===\n");
    struct Nodo* actual = frente;
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
    printf("\n---- MENU COLA DINAMICA (ESTRUCTURA COMPUESTA - DOBLE APUNTADOR) ----\n");
    printf("1. Encolar persona\n");
    printf("2. Desencolar persona\n");
    printf("3. Mostrar cola\n");
    printf("4. Salir\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    return opcion;
}
