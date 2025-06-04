//04 - 06 - 25
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
int sumaHojas(struct nodo *);
int contarNodos(struct nodo *);
int contarHojas(struct nodo *);
int contarNodosInternos(struct nodo *);
int contarMayores(struct nodo *, int);
int contarMenores(struct nodo *, int);
int menu(void);
int suprimeMin(struct nodo **raiz); // Nueva función

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

int sumaHojas(struct nodo *ptr) {
    if (ptr == NULL) {
        return 0;
    }
    if (ptr->izq == NULL && ptr->der == NULL) {
        return ptr->clave;
    }
    return sumaHojas(ptr->izq) + sumaHojas(ptr->der);
}

int contarNodos(struct nodo *ptr) {
    if (ptr == NULL) {
        return 0;
    }
    return 1 + contarNodos(ptr->izq) + contarNodos(ptr->der);
}

int contarHojas(struct nodo *ptr) {
    if (ptr == NULL) {
        return 0;
    }
    if (ptr->izq == NULL && ptr->der == NULL) {
        return 1;
    }
    return contarHojas(ptr->izq) + contarHojas(ptr->der);
}

int contarNodosInternos(struct nodo *ptr) {
    if (ptr == NULL) {
        return 0;
    }
    if (ptr->izq == NULL && ptr->der == NULL) {
        return 0;
    }
    return 1 + contarNodosInternos(ptr->izq) + contarNodosInternos(ptr->der);
}

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
    printf("12. Eliminar el nodo más pequeño (SUPRIME_MIN)\n");
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

// Implementación de SUPRIME_MIN
// Elimina el nodo con el valor más pequeño y devuelve su clave
int suprimeMin(struct nodo **raiz) {
    if (*raiz == NULL) {
        printf("El arbol está vacío.\n");
        return -1; // o algún valor de error
    }
    struct nodo *tmp;
    int min;
    if ((*raiz)->izq == NULL) {
        // El nodo actual es el más pequeño
        min = (*raiz)->clave;
        tmp = *raiz;
        *raiz = (*raiz)->der; // Reemplaza el nodo por su hijo derecho
        free(tmp);
        return min;
    } else {
        // Buscar en el subárbol izquierdo
        return suprimeMin(&((*raiz)->izq));
    }
}

int main(){
    int op, clave, valor, eliminado;
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
                break;
            case 10:
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
            case 12:
                eliminado = suprimeMin(&arbol);
                if (eliminado != -1)
                    printf("\nEl valor eliminado más pequeño es: %d\n", eliminado);
                break;
        }
    } while(op != 0);
    return 0;
}
