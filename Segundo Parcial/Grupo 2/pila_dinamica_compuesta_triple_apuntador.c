/*
 * IMPLEMENTACIÓN DE PILA DINÁMICA COMPUESTA CON TRIPLE APUNTADOR
 * 
 * Esta implementación combina el uso de estructuras compuestas (struct Producto)
 * con el manejo de triple nivel de indirección para las operaciones de la pila.
 * 
 * Características:
 * - Almacena datos compuestos (struct Producto con código, descripción, precio y stock)
 * - Utiliza triple nivel de indirección (struct Nodo***)
 * - Simula un sistema de inventario con productos
 * 
 * Diferencia con otras implementaciones:
 * - Combina datos compuestos con el nivel más alto de indirección
 * - Las funciones devuelven estructuras completas (struct Producto) en lugar de tipos simples
 * - Incluye manejo de casos de error retornando una estructura vacía con valores centinela
 * - Interfaz de usuario orientada a la gestión de inventario
 */
#include <stdio.h>
#include <stdlib.h>

// Estructura para datos compuestos
struct Producto {
    int codigo;
    char descripcion[100];
    float precio;
    int stock;
};

struct Nodo {
    struct Producto dato;
    struct Nodo* siguiente;
};

// Prototipos de funciones
int apilar(struct Nodo*** tope, struct Producto producto);
struct Producto desapilar(struct Nodo*** tope);
int estaVacia(struct Nodo** tope);
void mostrarPila(struct Nodo** tope);
int menu();

int main() {
    struct Nodo* pila = NULL;
    struct Nodo** ptrPila = &pila;
    struct Nodo*** ptrPtrPila = &ptrPila;
    struct Producto producto;
    
    while (1) {
        switch (menu()) {
            case 1:
                printf("Ingrese los datos del producto:\n");
                printf("Código: ");
                scanf("%d", &producto.codigo);
                printf("Descripción: ");
                scanf("%s", producto.descripcion);
                printf("Precio: ");
                scanf("%f", &producto.precio);
                printf("Stock: ");
                scanf("%d", &producto.stock);
                
                if (apilar(ptrPtrPila, producto) == 0) {
                    printf("Producto agregado correctamente\n");
                    mostrarPila(ptrPila);
                }
                break;
            case 2:
                if (!estaVacia(ptrPila)) {
                    producto = desapilar(ptrPtrPila);
                    if (producto.codigo != -1) {
                        printf("Producto retirado:\n");
                        printf("  Código: %d\n", producto.codigo);
                        printf("  Descripción: %s\n", producto.descripcion);
                        printf("  Precio: $%.2f\n", producto.precio);
                        printf("  Stock: %d\n", producto.stock);
                        mostrarPila(ptrPila);
                    }
                } else {
                    printf("El inventario está vacío\n");
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
// Función para apilar usando triple apuntador con datos compuestos
int apilar(struct Nodo*** tope, struct Producto producto) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return -1;
    }
    nuevo->dato = producto;
    nuevo->siguiente = **tope;
    **tope = nuevo;
    return 0;
}

// Función para desapilar usando triple apuntador con datos compuestos
struct Producto desapilar(struct Nodo*** tope) {
    struct Producto vacio = {-1, "", -1.0, -1};
    if (**tope == NULL) {
        printf("Error: Pila vacía\n");
        return vacio;
    }
    struct Nodo* temp = **tope;
    struct Producto producto = temp->dato;
    **tope = (**tope)->siguiente;
    free(temp);
    return producto;
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
    printf("\n=== INVENTARIO DE PRODUCTOS ===\n");
    struct Nodo* actual = *tope;
    int posicion = 1;
    while (actual != NULL) {
        printf("Producto %d:\n", posicion);
        printf("  Código: %d\n", actual->dato.codigo);
        printf("  Descripción: %s\n", actual->dato.descripcion);
        printf("  Precio: $%.2f\n", actual->dato.precio);
        printf("  Stock: %d\n", actual->dato.stock);
        printf("  ========================\n");
        actual = actual->siguiente;
        posicion++;
    }
}

// Función del menú
int menu() {
    int opcion;
    printf("\n---- MENU PILA DINAMICA TRIPLE APUNTADOR COMPUESTA ----\n");
    printf("1. Agregar producto\n");
    printf("2. Quitar producto\n");
    printf("3. Mostrar inventario\n");
    printf("4. Salir\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    return opcion;
}
