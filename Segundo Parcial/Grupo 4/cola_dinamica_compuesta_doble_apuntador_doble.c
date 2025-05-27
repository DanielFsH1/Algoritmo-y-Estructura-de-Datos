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

// Verificar si la cola está vacía
int estaVacia(Nodo** frente) {
    return (*frente == NULL);
}

// Función para insertar un elemento en la cola (meter dato)
void meterDato(Nodo** frente, Nodo** final, Datos valor) {
    Nodo* nuevo = crearNodo(valor);
    if (nuevo == NULL) return;
    
    if (estaVacia(frente)) {
        *frente = nuevo;
    } else {
        nuevo->anterior = *final;
        (*final)->siguiente = nuevo;
    }
    
    *final = nuevo;
    printf("Elemento con ID %d insertado con éxito\n", valor.id);
}

// Función para eliminar un elemento de la cola (sacar dato)
Datos sacarDato(Nodo** frente, Nodo** final) {
    Datos vacio = {-1, "", '\0'};
    
    if (estaVacia(frente)) {
        printf("Error: La cola está vacía\n");
        return vacio;
    }
    
    Nodo* temp = *frente;
    Datos valor = temp->info;
    
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
    
    printf("Contenido de la cola:\n");
    printf("-----------------------------------------\n");
    printf("| ID  | Nombre               | Tipo     |\n");
    printf("-----------------------------------------\n");
    
    Nodo* actual = *frente;
    while (actual != NULL) {
        printf("| %-3d | %-20s | %-8c |\n", 
               actual->info.id, 
               actual->info.nombre, 
               actual->info.tipo);
        actual = actual->siguiente;
    }
    printf("-----------------------------------------\n");
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
    int opcion;
    Datos dato;
    
    do {
        printf("\n--- Menú Cola Dinámica Compuesta con Doble Apuntador y Enlace Doble ---\n");
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
                
                meterDato(&frente, &final, dato);
                break;
                
            case 2:
                dato = sacarDato(&frente, &final);
                if (dato.id != -1) {
                    printf("Elemento eliminado: ID=%d, Nombre=%s, Tipo=%c\n", 
                           dato.id, dato.nombre, dato.tipo);
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
