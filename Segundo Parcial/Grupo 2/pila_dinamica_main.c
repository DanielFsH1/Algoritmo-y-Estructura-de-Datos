/*
 * IMPLEMENTACIÓN DE PILA DINÁMICA INTEGRADA EN MAIN
 * 
 * Esta implementación integra todas las operaciones de la pila directamente
 * en la función main, sin usar funciones auxiliares separadas.
 * 
 * Características:
 * - Todas las operaciones (push, pop, mostrar) están codificadas en el main
 * - Utiliza un único puntero simple (struct Nodo *tope)
 * - Implementación más compacta pero menos modular
 * - El campo siguiente se nombra "sig" en lugar de "siguiente"
 * 
 * Diferencia con otras implementaciones:
 * - No utiliza funciones separadas para operaciones de pila
 * - No implementa el patrón de pasar punteros por referencia
 * - Enfoque más directo pero menos reusable
 * - Código menos estructurado pero más fácil de seguir linealmente
 */
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *sig;
};

int main() {
    struct Nodo *tope = NULL; // Tope de la pila
    int opcion, num;
    
    do {
        printf("\n--- MENU PILA DINÁMICA ---\n");
        printf("1. Push (meter dato)\n");
        printf("2. Pop (sacar dato)\n");
        printf("3. Mostrar pila\n");
        printf("4. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        if(opcion == 1) {
            printf("Ingresa un número entero: ");
            scanf("%d", &num);

            // Crear nuevo nodo
            struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
            if(nuevo == NULL) {
                printf("Memoria insuficiente\n");
                continue;
            }
            nuevo->dato = num;
            nuevo->sig = tope;
            tope = nuevo;
            printf("Dato agregado!\n");
        }
        else if(opcion == 2) {
            if(tope == NULL) {
                printf("La pila está vacía\n");
            } else {
                struct Nodo *aux = tope;
                printf("Dato sacado: %d\n", tope->dato);
                tope = tope->sig;
                free(aux);
            }
        }
        else if(opcion == 3) {
            struct Nodo *tmp = tope;
            printf("Contenido de la pila:\n");
            while(tmp != NULL) {
                printf("%d -> ", tmp->dato);
                tmp = tmp->sig;
            }
            printf("NULL\n");
        }
    } while(opcion != 4);

    // Liberar memoria restante si hay elementos
    while(tope != NULL) {
        struct Nodo *aux = tope;
        tope = tope->sig;
        free(aux);
    }
    return 0;
}
