#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo con doble enlace
typedef struct nodo {
    int dato;
    struct nodo *siguiente;
    struct nodo *anterior;
} Nodo;

// Función para crear un nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error: No hay memoria disponible\n");
        return NULL;
    }
    
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}

// Verificar si la cola está vacía
int estaVacia(Nodo** frente) {
    return (*frente == NULL);
}

// Función para insertar un elemento en la cola (meter dato)
void meterDato(Nodo** frente, Nodo** final, int valor) {
    Nodo* nuevo = crearNodo(valor);
    if (nuevo == NULL) return;
    
    if (estaVacia(frente)) {
        *frente = nuevo;
    } else {
        nuevo->anterior = *final;
        (*final)->siguiente = nuevo;
    }
    
    *final = nuevo;
    printf("Elemento %d insertado con éxito\n", valor);
}

// Función para eliminar un elemento de la cola (sacar dato)
int sacarDato(Nodo** frente, Nodo** final) {
    if (estaVacia(frente)) {
        printf("Error: La cola está vacía\n");
        return -1;
    }
    
    Nodo* temp = *frente;
    int valor = temp->dato;
    
    *frente = temp->siguiente;
    
    if (*frente == NULL) {
        *final = NULL;
    } else {
        (*frente)->anterior = NULL;
    }
    
    free(temp);
    return valor;
}

// Función para mostrar la cola con enlaces dobles
void mostrarCola(Nodo** frente) {
    if (estaVacia(frente)) {
        printf("La cola está vacía\n");
        return;
    }
    
    printf("Cola: ");
    Nodo* actual = *frente;
    while (actual != NULL) {
        printf("%d <-> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Función para liberar toda la memoria de la cola
void liberarCola(Nodo** frente, Nodo** final) {
    while (!estaVacia(frente)) {
        sacarDato(frente, final);
    }
}

int main() {
    Nodo* frente = NULL;
    Nodo* final = NULL;
    int opcion, valor;
    
    do {
        printf("\n--- Menú Cola Dinámica con Doble Apuntador y Enlace Doble ---\n");
        printf("1. Insertar elemento\n");
        printf("2. Eliminar elemento\n");
        printf("3. Mostrar cola\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                printf("Ingrese valor a insertar: ");
                scanf("%d", &valor);
                meterDato(&frente, &final, valor);
                break;
            case 2:
                valor = sacarDato(&frente, &final);
                if (valor != -1) {
                    printf("Elemento eliminado: %d\n", valor);
                }
                break;
            case 3:
                mostrarCola(&frente);
                break;
            case 4:
                liberarCola(&frente, &final);
                printf("Memoria liberada. Programa terminado\n");
                break;
            default:
                printf("Opción inválida\n");
        }
    } while (opcion != 4);
    
    return 0;
}
