#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para datos compuestos
typedef struct {
    int id;
    char nombre[50];
    char tipo;
} Datos;

// Estructura del nodo con doble enlace
typedef struct nodo {
    Datos info;
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
Nodo* crearNodo(Datos valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error: No hay memoria disponible\n");
        return NULL;
    }
    
    nuevo->info = valor;
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
void meterDato(Cola *c, Datos valor) {
    Nodo* nuevo = crearNodo(valor);
    if (nuevo == NULL) return;
    
    if (estaVacia(c)) {
        *(c->frente) = nuevo;
    } else {
        nuevo->anterior = *(c->final);
        (*(c->final))->siguiente = nuevo;
    }
    
    *(c->final) = nuevo;
    printf("Elemento con ID %d insertado con éxito\n", valor.id);
}

// Función para eliminar un elemento de la cola (sacar dato)
Datos sacarDato(Cola *c) {
    Datos vacio = {-1, "", '\0'};
    
    if (estaVacia(c)) {
        printf("Error: La cola está vacía\n");
        return vacio;
    }
    
    Nodo* temp = *(c->frente);
    Datos valor = temp->info;
    
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
    
    printf("Contenido de la cola:\n");
    printf("-----------------------------------------\n");
    printf("| ID  | Nombre               | Tipo     |\n");
    printf("-----------------------------------------\n");
    
    *(c->actual) = *(c->frente);
    while (*(c->actual) != NULL) {
        printf("| %-3d | %-20s | %-8c |\n", 
               (*(c->actual))->info.id, 
               (*(c->actual))->info.nombre, 
               (*(c->actual))->info.tipo);
        *(c->actual) = (*(c->actual))->siguiente;
    }
    printf("-----------------------------------------\n");
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
    int opcion;
    Datos dato;
    
    inicializarCola(&cola);
    
    do {
        printf("\n--- Menú Cola Dinámica Compuesta con Triple Apuntador y Enlace Doble ---\n");
        printf("1. Insertar elemento\n");
        printf("2. Eliminar elemento\n");
        printf("3. Mostrar cola\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        fflush(stdin);
        
        switch (opcion) {
            case 1:
                printf("Ingrese ID: ");
                scanf("%d", &dato.id);
                fflush(stdin);
                
                printf("Ingrese nombre: ");
                fgets(dato.nombre, 50, stdin);
                dato.nombre[strcspn(dato.nombre, "\n")] = '\0';
                
                printf("Ingrese tipo (un carácter): ");
                scanf("%c", &dato.tipo);
                fflush(stdin);
                
                meterDato(&cola, dato);
                break;
                
            case 2:
                dato = sacarDato(&cola);
                if (dato.id != -1) {
                    printf("Elemento eliminado: ID=%d, Nombre=%s, Tipo=%c\n", 
                           dato.id, dato.nombre, dato.tipo);
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
