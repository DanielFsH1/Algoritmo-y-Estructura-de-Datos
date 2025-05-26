#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int clave;
    struct Nodo* siguiente;
};

// Función para verificar duplicados
int existeClave(struct Nodo* inicio, int clave) {
    struct Nodo* actual = inicio;
    while (actual != NULL) {
        if (actual->clave == clave) return 1;
        actual = actual->siguiente;
    }
    return 0;  // Cambiar a 0 cuando no encuentra la clave
}

// Función para imprimir la lista
void imprimirLista(struct Nodo* inicio) {
    struct Nodo* actual = inicio;
    printf("Lista: ");
    while (actual != NULL) {
        printf("%d -> ", actual->clave);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Función de inserción implementando los 4 casos
int insertar(struct Nodo** ptrref, int valor) {
    // Verificar duplicados
    if (existeClave(*ptrref, valor)) {
        printf("Error: La clave %d ya existe\n", valor);
        return 1;
    }

    struct Nodo* ptrN = (struct Nodo*)malloc(sizeof(struct Nodo));
    ptrN->clave = valor;
    ptrN->siguiente = NULL;

    // Si la lista está completamente vacía
    if (*ptrref == NULL) {
        *ptrref = ptrN;
        return 1;
    }

    // Caso 1: Si está vacío el siguiente
    if ((*ptrref)->siguiente == NULL) {
        // Si el nuevo valor es menor que el actual
        if (valor < (*ptrref)->clave) {
            ptrN->siguiente = *ptrref;
            *ptrref = ptrN;
        } else {
            (*ptrref)->siguiente = ptrN;
        }
        return 1;
    }

    // Caso 2: Si el nuevo es menor que el primer nodo
    if (valor < (*ptrref)->clave) {
        ptrN->siguiente = *ptrref;
        *ptrref = ptrN;
        return 1;
    }

    // Caso 3: Recorrer con dos punteros
    struct Nodo* ptrretaguardia = *ptrref;
    struct Nodo* ptravanzada = (*ptrref)->siguiente;

    while (ptravanzada != NULL) {
        if (ptrN->clave > ptrretaguardia->clave && 
            ptrN->clave < ptravanzada->clave) {
            ptrN->siguiente = ptravanzada;
            ptrretaguardia->siguiente = ptrN;
            return 1;
        }
        ptrretaguardia = ptravanzada;
        ptravanzada = ptravanzada->siguiente;
    }

    // Caso 4: Por default al final
    ptrretaguardia->siguiente = ptrN;
    return 1;
}

int main() {
    struct Nodo* lista = NULL;  // Iniciamos con lista vacía
    int opcion, valor;

    do {
        printf("\n1. Insertar valor\n");
        printf("2. Mostrar lista\n");
        printf("3. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese valor a insertar: ");
                scanf("%d", &valor);
                insertar(&lista, valor);
                break;
            case 2:
                imprimirLista(lista);
                break;
            case 3:
                printf("Programa terminado\n");
                break;
            default:
                printf("Opción inválida\n");
        }
    } while (opcion != 3);

    return 0;
}
