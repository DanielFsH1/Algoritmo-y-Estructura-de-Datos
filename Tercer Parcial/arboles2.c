//03 - 06 - 25
#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int clave;
    struct nodo *izq;
    struct nodo *der;
};

// Prototipos
struct nodo *crear(int);
struct nodo *insertar(int, struct nodo * );
void preorden(struct nodo *);
void inorden(struct nodo *);
void postorden(struct nodo *);
void imprimir(struct nodo *, int);
int suma(struct nodo *);
int sumaHojas(struct nodo *);  // Nuevo prototipo
int contarNodos(struct nodo *);
int contarHojas(struct nodo *);
int contarNodosInternos(struct nodo *);
int contarMayores(struct nodo *, int);
int contarMenores(struct nodo *, int);
int menu(void);

struct nodo *crear(int clave){
    struct nodo *nuevo = (struct nodo *)malloc(sizeof(struct nodo));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        exit(1);
    }
    nuevo->clave = clave;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

struct nodo *insertar(int clave, struct nodo *raiz){
    if(raiz == NULL){
        return crear(clave);
    }
    if (clave < raiz->clave){
        raiz->izq = insertar(clave, raiz->izq);
    }
    else if (clave > raiz->clave){
        raiz->der = insertar(clave, raiz->der);
    }
    else {
        printf("El valor %d ya existe en el arbol\n", clave);
    }
    return raiz;
}

void preorden(struct nodo *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->clave);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void inorden(struct nodo *raiz) {
    if (raiz != NULL) {
        inorden(raiz->izq);
        printf("%d ", raiz->clave);
        inorden(raiz->der);
    }
}

void postorden(struct nodo *raiz) {
    if (raiz != NULL) {
        postorden(raiz->izq);
        postorden(raiz->der);
        printf("%d ", raiz->clave);
    }
}

int suma(struct nodo *ptr) {
    if (ptr == NULL) {
        return 0;
    }
    return ptr->clave + suma(ptr->izq) + suma(ptr->der);
}

// Función para sumar solo las hojas
int sumaHojas(struct nodo *ptr) {
    if (ptr == NULL) {
        return 0;
    }
    // Si es una hoja (no tiene hijos)
    if (ptr->izq == NULL && ptr->der == NULL) {
        return ptr->clave;
    }
    // Si no es hoja, suma las hojas de los subárboles
    return sumaHojas(ptr->izq) + sumaHojas(ptr->der);
}

// Función para contar el número total de nodos
int contarNodos(struct nodo *ptr) {
    if (ptr == NULL) {
        return 0;
    }
    return 1 + contarNodos(ptr->izq) + contarNodos(ptr->der);
}

// Función para contar el número de hojas
int contarHojas(struct nodo *ptr) {
    if (ptr == NULL) {
        return 0;
    }
    // Si es una hoja (no tiene hijos)
    if (ptr->izq == NULL && ptr->der == NULL) {
        return 1;
    }
    // Si no es hoja, cuenta las hojas de los subárboles
    return contarHojas(ptr->izq) + contarHojas(ptr->der);
}

// Función para contar el número de nodos internos
int contarNodosInternos(struct nodo *ptr) {
    if (ptr == NULL) {
        return 0;
    }
    // Si es una hoja, no es nodo interno
    if (ptr->izq == NULL && ptr->der == NULL) {
        return 0;
    }
    // Si tiene al menos un hijo, es nodo interno
    return 1 + contarNodosInternos(ptr->izq) + contarNodosInternos(ptr->der);
}

// Función para contar nodos mayores a un valor dado
int contarMayores(struct nodo *ptr, int valor) {
    if (ptr == NULL) {
        return 0;
    }
    int contador = 0;
    if (ptr->clave > valor) {
        contador = 1;
    }
    return contador + contarMayores(ptr->izq, valor) + contarMayores(ptr->der, valor);
}

// Función para contar nodos menores a un valor dado
int contarMenores(struct nodo *ptr, int valor) {
    if (ptr == NULL) {
        return 0;
    }
    int contador = 0;
    if (ptr->clave < valor) {
        contador = 1;
    }
    return contador + contarMenores(ptr->izq, valor) + contarMenores(ptr->der, valor);
}

int menu() {
    int op;
    printf("\n1. Ingresar\n");
    printf("2. Mostrar preorden\n");
    printf("3. Mostrar inorden\n");
    printf("4. Mostrar postorden\n");
    printf("5. Imprimir arbol\n");
    printf("6. Suma de elementos\n");
    printf("7. Suma de hojas\n");
    printf("8. Contar nodos totales\n");
    printf("9. Contar hojas\n");
    printf("10. Contar nodos internos\n");
    printf("11. Contar nodos mayores y menores a un valor\n");
    printf("0. Salir\n");
    printf("Ingresa la opcion: ");
    scanf("%d", &op);
    fflush(stdin);
    return op;
}

void imprimir(struct nodo *ptrA, int contador){
    int i, j;
    i=contador;
    if(ptrA!=NULL){
        imprimir(ptrA->der, i+1);
        printf("\n");
        for(j=1;j<i;j++)
            printf("-");
        printf("%d", ptrA->clave);
        imprimir(ptrA->izq, i+1);
    }
}

int main(){
    int op, clave, valor;
    struct nodo *arbol = NULL;

    do{
        op = menu();
        switch (op) {
            case 1:
                printf("Ingrese el valor a guardar (0-99): ");
                scanf("%d", &clave);
                fflush(stdin);
                arbol = insertar(clave, arbol);
                break;
            case 2:
                printf("\nRecorrido Preorden: ");
                preorden(arbol);
                break;
            case 3:
                printf("\nRecorrido Inorden: ");
                inorden(arbol);
                break;
            case 4:
                printf("\nRecorrido Postorden: ");
                postorden(arbol);
                break;
            case 5:
                printf("\nArbol dibujado:\n");
                imprimir(arbol, 1);
                break;
            case 6:
                printf("\nLa suma de todos los elementos es: %d\n", suma(arbol));
                break;
            case 7:
                printf("\nLa suma de las hojas es: %d\n", sumaHojas(arbol));
                break;
            case 8:
                printf("\nEl numero total de nodos es: %d\n", contarNodos(arbol));
                break;
            case 9:
                printf("\nEl numero de hojas es: %d\n", contarHojas(arbol));
                break;            case 10:
                printf("\nEl numero de nodos internos es: %d\n", contarNodosInternos(arbol));
                break;
            case 11:
                printf("Ingrese el valor de referencia: ");
                scanf("%d", &valor);
                fflush(stdin);
                printf("\nResultados para el valor %d:\n", valor);
                printf("- Nodos mayores a %d: %d\n", valor, contarMayores(arbol, valor));
                printf("- Nodos menores a %d: %d\n", valor, contarMenores(arbol, valor));
                break;
        }
    } while(op != 0);
    return 0;
}
