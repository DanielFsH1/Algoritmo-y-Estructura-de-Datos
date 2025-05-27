#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo con doble enlace
typedef struct nodo {
    int dato;
    struct nodo *siguiente;
    struct nodo *anterior;
} Nodo;

// Estructura para gestionar la cola con triple apuntador
typedef struct {
    Nodo **frente;    // Doble apuntador al frente de la cola
    Nodo **final;     // Doble apuntador al final de la cola
    Nodo **actual;    // Doble apuntador adicional para recorrer la cola
} Cola;

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

// Inicializar cola con triple apuntador
void inicializarCola(Cola *c) {
    c->frente = (Nodo**)malloc(sizeof(Nodo*));
    c->final = (Nodo**)malloc(sizeof(Nodo*));
    c->actual = (Nodo**)malloc(sizeof(Nodo*));
    
    if (c->frente == NULL || c->final == NULL || c->actual == NULL) {
        printf("Error: No se pudo asignar memoria para los apuntadores\n");
        exit(1);
    }
    
    *(c->frente) = NULL;
    *(c->final) = NULL;
    *(c->actual) = NULL;
}

// Verificar si la cola está vacía
int estaVacia(Cola *c) {
    return (*(c->frente) == NULL);
}

// Función para insertar un elemento en la cola (meter dato)
void meterDato(Cola *c, int valor) {
    Nodo* nuevo = crearNodo(valor);
    if (nuevo == NULL) return;
    
    if (estaVacia(c)) {
        *(c->frente) = nuevo;
    } else {
        nuevo->anterior = *(c->final);
        (*(c->final))->siguiente = nuevo;
    }
    
    *(c->final) = nuevo;
    printf("Elemento %d insertado con éxito\n", valor);
}

// Función para eliminar un elemento de la cola (sacar dato)
int sacarDato(Cola *c) {
    if (estaVacia(c)) {
        printf("Error: La cola está vacía\n");
        return -1;
    }
    
    Nodo* temp = *(c->frente);
    int valor = temp->dato;
    
    *(c->frente) = temp->siguiente;
    
    if (*(c->frente) == NULL) {
        *(c->final) = NULL;
    } else {
        (*(c->frente))->anterior = NULL;
    }
    
    free(temp);
    return valor;
}

// Función para mostrar la cola con enlaces dobles
void mostrarCola(Cola *c) {
    if (estaVacia(c)) {
        printf("La cola está vacía\n");
        return;
    }
    
    printf("Cola: ");
    *(c->actual) = *(c->frente);
    while (*(c->actual) != NULL) {
        printf("%d <-> ", (*(c->actual))->dato);
        *(c->actual) = (*(c->actual))->siguiente;
    }
    printf("NULL\n");
}

// Función para liberar toda la memoria de la cola
void liberarCola(Cola *c) {
    while (!estaVacia(c)) {
        sacarDato(c);
    }
    free(c->frente);
    free(c->final);
    free(c->actual);
}

int main() {
    Cola cola;
    int opcion, valor;
    
    inicializarCola(&cola);
    
    do {
        printf("\n--- Menú Cola Dinámica con Triple Apuntador y Enlace Doble ---\n");
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
                meterDato(&cola, valor);
                break;
            case 2:
                valor = sacarDato(&cola);
                if (valor != -1) {
                    printf("Elemento eliminado: %d\n", valor);
                }
                break;
            case 3:
                mostrarCola(&cola);
                break;
            case 4:
                liberarCola(&cola);
                printf("Memoria liberada. Programa terminado\n");
                break;
            default:
                printf("Opción inválida\n");
        }
    } while (opcion != 4);
    
    return 0;
}
