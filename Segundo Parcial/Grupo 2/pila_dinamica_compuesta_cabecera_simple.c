/*
 * IMPLEMENTACIÓN DE PILA DINÁMICA COMPUESTA CON CABECERA SIMPLE
 * 
 * Esta implementación utiliza estructuras compuestas (struct Persona)
 * con un manejo simple de punteros para las operaciones de la pila.
 * 
 * Características:
 * - Almacena datos compuestos (struct Persona con id, nombre y edad)
 * - Utiliza un único puntero para la cabecera (struct Nodo* pila)
 * - Las funciones reciben un doble puntero para modificar la cabecera
 * 
 * Diferencia con otras implementaciones:
 * - Maneja datos compuestos pero con el nivel más simple de indirección
 * - Similar a la versión simple pero con estructura de datos más compleja
 * - Más fácil de entender que las versiones de doble y triple apuntador
 * - Las funciones devuelven estructuras completas (struct Persona)
 * - Enfocada en gestión de personas en lugar de productos
 */
#include <stdio.h>
#include <stdlib.h>

// Estructura para datos compuestos
struct Persona {
    int id;
    char nombre[50];
    int edad;
};

struct Nodo {
    struct Persona dato;
    struct Nodo* siguiente;
};

// Prototipos de funciones
int apilar(struct Nodo** tope, struct Persona persona);
struct Persona desapilar(struct Nodo** tope);
int estaVacia(struct Nodo* tope);
void mostrarPila(struct Nodo* tope);
int menu();

int main() {
    struct Nodo* pila = NULL;
    struct Persona persona;
    
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
                
                if (apilar(&pila, persona) == 0) {
                    printf("Persona apilada correctamente\n");
                    mostrarPila(pila);
                }
                break;
            case 2:
                if (!estaVacia(pila)) {
                    persona = desapilar(&pila);
                    if (persona.id != -1) {
                        printf("Persona desapilada:\n");
                        printf("  ID: %d\n", persona.id);
                        printf("  Nombre: %s\n", persona.nombre);
                        printf("  Edad: %d\n", persona.edad);
                        mostrarPila(pila);
                    }
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
// Función para apilar (push) con datos compuestos
int apilar(struct Nodo** tope, struct Persona persona) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return -1;
    }
    nuevo->dato = persona;
    nuevo->siguiente = *tope;
    *tope = nuevo;
    return 0;
}

// Función para desapilar (pop) con datos compuestos
struct Persona desapilar(struct Nodo** tope) {
    struct Persona vacio = {-1, "", -1};
    if (*tope == NULL) {
        printf("Error: Pila vacía\n");
        return vacio;
    }
    struct Nodo* temp = *tope;
    struct Persona persona = temp->dato;
    *tope = (*tope)->siguiente;
    free(temp);
    return persona;
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
    printf("\n=== CONTENIDO DE LA PILA ===\n");
    struct Nodo* actual = tope;
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
}

// Función del menú
int menu() {
    int opcion;
    printf("\n---- MENU PILA DINAMICA COMPUESTA ----\n");
    printf("1. Apilar persona\n");
    printf("2. Desapilar persona\n");
    printf("3. Mostrar pila\n");
    printf("4. Salir\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    return opcion;
}
