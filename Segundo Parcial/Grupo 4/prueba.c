#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo con doble enlace
struct Nodo {
    int dato;                    // Dato a almacenar
    struct Nodo* siguiente;      // Enlace al siguiente nodo
    struct Nodo* anterior;       // Enlace al nodo anterior
};

// Función para inicializar los dos nodos cabecera
void inicializar(struct Nodo** frente, struct Nodo** final) {
    *frente = NULL;    // Nodo cabecera del frente
    *final = NULL;     // Nodo cabecera del final
}

int estaVacia(struct Nodo* frente) {
    return frente == NULL;
}

void insertar(struct Nodo** frente, struct Nodo** final, int valor) {
    // Crear nuevo nodo
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: No hay memoria disponible\n");
        return;
    }
    
    nuevo->dato = valor;
    // Enlaces dobles
    nuevo->siguiente = NULL;     // El nuevo nodo apunta a NULL
    nuevo->anterior = *final;    // El anterior del nuevo apunta al actual final

    // Actualización de nodos cabecera
    if (estaVacia(*frente)) {
        *frente = nuevo;         // Si está vacía, el frente es el nuevo
    } else {
        (*final)->siguiente = nuevo;  // Si no, el siguiente del final es el nuevo
    }
    *final = nuevo;             // El final siempre es el nuevo
    printf("Elemento %d insertado con éxito\n", valor);
}

int eliminar(struct Nodo** frente, struct Nodo** final) {
    if (estaVacia(*frente)) {
        printf("Error: La cola está vacía\n");
        return -1;
    }

    struct Nodo* temp = *frente;
    int valor = temp->dato;
    
    // Actualización de enlaces dobles al eliminar
    *frente = (*frente)->siguiente;   // El frente avanza
    if (*frente == NULL) {
        *final = NULL;               // Si queda vacía, final también a NULL
    } else {
        (*frente)->anterior = NULL;  // Si no, el anterior del nuevo frente es NULL
    }
    
    free(temp);
    return valor;
}

// Función para mostrar la cola con enlaces dobles
void mostrarCola(struct Nodo* frente) {
    if (estaVacia(frente)) {
        printf("La cola está vacía\n");
        return;
    }

    printf("Cola: ");
    struct Nodo* actual = frente;
    while (actual != NULL) {
        printf("%d <-> ", actual->dato);  // Muestra los enlaces dobles con <->
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

int main() {
    struct Nodo* frente = NULL;
    struct Nodo* final = NULL;
    int opcion, valor;

    do {
        printf("\n--- Menú Cola Dinámica ---\n");
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
                insertar(&frente, &final, valor);
                break;
            case 2:
                valor = eliminar(&frente, &final);
                if (valor != -1) {
                    printf("Elemento eliminado: %d\n", valor);
                }
                break;
            case 3:
                mostrarCola(frente);
                break;
            case 4:
                printf("Programa terminado\n");
                break;
            default:
                printf("Opción inválida\n");
        }
    } while (opcion != 4);

    return 0;
}
