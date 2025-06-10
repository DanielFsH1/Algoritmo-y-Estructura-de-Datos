#include <stdio.h>
#include <stdlib.h>

// Estructura de un nodo del árbol binario
struct nodo
{
    int clave;           // Valor almacenado en el nodo
    struct nodo *izq;    // Puntero al hijo izquierdo
    struct nodo *der;    // Puntero al hijo derecho
};

// --- Prototipos de Funciones ---
struct nodo *crear(int);
struct nodo *insertar(int, struct nodo *);
struct nodo *suprimir(int, struct nodo *);
struct nodo *suprimeMin(struct nodo *);
struct nodo *suprimeMax(struct nodo *);
int encontrarMin(struct nodo *);
int encontrarMax(struct nodo *);
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
int miembro(int, struct nodo *); // CORREGIDO: Cambiado prototipo para consistencia
int menu(void);
void limpiar_buffer(void); // NUEVO: Función para limpiar el buffer de entrada

// --- Implementación de Funciones ---

// Crea un nuevo nodo con un valor dado
struct nodo *crear(int clave)
{
    struct nodo *nuevo = (struct nodo *)malloc(sizeof(struct nodo));
    if (nuevo == NULL)
    {
        printf("Error: No se pudo asignar memoria\n");
        exit(1);
    }
    nuevo->clave = clave;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

// Inserta un valor en el árbol (evitando duplicados)
struct nodo *insertar(int clave, struct nodo *raiz)
{
    if (raiz == NULL)
    {
        return crear(clave);
    }
    if (clave < raiz->clave)
    {
        raiz->izq = insertar(clave, raiz->izq);
    }
    else if (clave > raiz->clave)
    {
        raiz->der = insertar(clave, raiz->der);
    }
    else
    {
        printf("El valor %d ya existe en el arbol\n", clave);
    }
    return raiz;
}

// Recorrido preorden (raíz → izquierdo → derecho)
void preorden(struct nodo *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->clave);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

// Recorrido inorden (izquierdo → raíz → derecho)
void inorden(struct nodo *raiz)
{
    if (raiz != NULL)
    {
        inorden(raiz->izq);
        printf("%d ", raiz->clave);
        inorden(raiz->der);
    }
}

// Recorrido postorden (izquierdo → derecho → raíz)
void postorden(struct nodo *raiz)
{
    if (raiz != NULL)
    {
        postorden(raiz->izq);
        postorden(raiz->der);
        printf("%d ", raiz->clave);
    }
}

// Suma todos los valores del árbol
int suma(struct nodo *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    return ptr->clave + suma(ptr->izq) + suma(ptr->der);
}

// Suma solo los valores de las hojas (nodos sin hijos)
int sumaHojas(struct nodo *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    if (ptr->izq == NULL && ptr->der == NULL)
    {
        return ptr->clave;
    }
    return sumaHojas(ptr->izq) + sumaHojas(ptr->der);
}

// Cuenta el número total de nodos
int contarNodos(struct nodo *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    return 1 + contarNodos(ptr->izq) + contarNodos(ptr->der);
}

// Cuenta el número de hojas (nodos sin hijos)
int contarHojas(struct nodo *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    if (ptr->izq == NULL && ptr->der == NULL)
    {
        return 1;
    }
    return contarHojas(ptr->izq) + contarHojas(ptr->der);
}

// Cuenta nodos internos (nodos con al menos un hijo)
int contarNodosInternos(struct nodo *ptr)
{
    if (ptr == NULL || (ptr->izq == NULL && ptr->der == NULL))
    {
        return 0;
    }
    return 1 + contarNodosInternos(ptr->izq) + contarNodosInternos(ptr->der);
}

// Cuenta nodos con valor mayor a uno dado
int contarMayores(struct nodo *ptr, int valor)
{
    if (ptr == NULL)
    {
        return 0;
    }
    int contador = (ptr->clave > valor) ? 1 : 0;
    return contador + contarMayores(ptr->izq, valor) + contarMayores(ptr->der, valor);
}

// Cuenta nodos con valor menor a uno dado
int contarMenores(struct nodo *ptr, int valor)
{
    if (ptr == NULL)
    {
        return 0;
    }
    int contador = (ptr->clave < valor) ? 1 : 0;
    return contador + contarMenores(ptr->izq, valor) + contarMenores(ptr->der, valor);
}

// CORREGIDO: Verifica si un valor existe en el árbol.
// Se ha cambiado para no usar doble puntero y se han añadido los 'return' que faltaban.
int miembro(int x, struct nodo *ptrA)
{
    if (ptrA == NULL)
        return 0; // No se encontró
    if (x == ptrA->clave)
        return 1; // Se encontró
    if (x < ptrA->clave)
        return miembro(x, ptrA->izq); // Falta el 'return' aquí
    else
        return miembro(x, ptrA->der); // Y aquí también
}


// Encuentra el valor mínimo sin eliminarlo
int encontrarMin(struct nodo *a)
{
    if (a == NULL)
    {
        printf("Árbol vacío\n");
        return -1; // Se asume que -1 no es un valor válido en el árbol
    }
    // El nodo más a la izquierda es el mínimo
    while (a->izq != NULL)
        a = a->izq;
    return a->clave;
}

// Encuentra el valor máximo sin eliminarlo
int encontrarMax(struct nodo *a)
{
    if (a == NULL)
    {
        printf("Árbol vacío\n");
        return -1;
    }
    // El nodo más a la derecha es el máximo
    while (a->der != NULL)
        a = a->der;
    return a->clave;
}


// Elimina el nodo con el valor mínimo del subárbol dado
struct nodo *suprimeMin(struct nodo *a)
{
    if (a->izq == NULL)
    {
        struct nodo *temp = a->der;
        free(a);
        return temp;
    }
    a->izq = suprimeMin(a->izq);
    return a;
}

// Elimina el nodo con el valor máximo del subárbol dado
struct nodo *suprimeMax(struct nodo *a)
{
    if (a->der == NULL)
    {
        struct nodo *temp = a->izq;
        free(a);
        return temp;
    }
    a->der = suprimeMax(a->der);
    return a;
}


// CORREGIDO: Elimina un nodo con un valor específico.
// La lógica anterior era incorrecta, especialmente para nodos con dos hijos.
struct nodo *suprimir(int x, struct nodo *A)
{
    if (A == NULL) {
        printf("El valor %d no se encontro para eliminar.\n", x);
        return NULL; // El elemento no está en el árbol
    }

    // Buscar el nodo a eliminar
    if (x < A->clave) {
        A->izq = suprimir(x, A->izq);
    } else if (x > A->clave) {
        A->der = suprimir(x, A->der);
    } else { // Encontramos el nodo a eliminar (A->clave == x)
        
        // Caso 1: El nodo es una hoja (no tiene hijos)
        if (A->izq == NULL && A->der == NULL) {
            free(A);
            return NULL; // Se devuelve NULL al padre
        }
        // Caso 2: El nodo tiene un solo hijo
        else if (A->izq == NULL) {
            struct nodo *temp = A->der;
            free(A);
            return temp; // Se devuelve el hijo derecho al padre
        } else if (A->der == NULL) {
            struct nodo *temp = A->izq;
            free(A);
            return temp; // Se devuelve el hijo izquierdo al padre
        }
        // Caso 3: El nodo tiene dos hijos
        else {
            // Se busca el sucesor inorden (el mínimo del subárbol derecho)
            int sucesor = encontrarMin(A->der);
            // Se copia el valor del sucesor a este nodo
            A->clave = sucesor;
            // Se elimina el nodo sucesor del subárbol derecho
            A->der = suprimir(sucesor, A->der);
        }
    }
    return A;
}


// NUEVO: Función para limpiar el buffer de entrada de forma segura.
// fflush(stdin) no es estándar para streams de entrada.
void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Muestra el menú y retorna la opción seleccionada
int menu()
{
    int op;
    printf("\n--- MENU ARBOL BINARIO ---\n");
    printf("1.  Ingresar\n");
    printf("2.  Mostrar preorden\n");
    printf("3.  Mostrar inorden\n");
    printf("4.  Mostrar postorden\n");
    printf("5.  Imprimir arbol\n");
    printf("6.  Suma de elementos\n");
    printf("7.  Suma de hojas\n");
    printf("8.  Contar nodos totales\n");
    printf("9.  Contar hojas\n");
    printf("10. Contar nodos internos\n");
    printf("11. Contar nodos mayores/menores a un valor\n");
    printf("12. Buscar elemento\n");
    printf("13. Eliminar elemento minimo\n");
    printf("14. Mostrar elemento minimo\n");
    printf("15. Eliminar elemento maximo\n");
    printf("16. Mostrar elemento maximo\n");
    printf("17. Eliminar un elemento dado\n");
    printf("0. Salir\n");
    printf("--------------------------\n");
    printf("Ingresa la opcion: ");
    
    // Bucle para asegurar que se ingrese un número
    while (scanf("%d", &op) != 1) {
        printf("Entrada invalida. Por favor, ingrese un numero: ");
        limpiar_buffer();
    }
    limpiar_buffer(); // Limpiar el buffer después de una lectura exitosa
    return op;
}


// Imprime el árbol de forma visual (horizontal)
void imprimir(struct nodo *ptrA, int contador)
{
    int i;
    if (ptrA != NULL)
    {
        imprimir(ptrA->der, contador + 1);
        printf("\n");
        for (i = 0; i < contador; i++)
            printf("   "); // Añade espaciado para mejor visualización
        printf("%d\n", ptrA->clave);
        imprimir(ptrA->izq, contador + 1);
    }
}

// Función principal (menú interactivo)
int main()
{
    int op, clave, valor;
    struct nodo *arbol = NULL;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            printf("Ingrese el valor a guardar: ");
            scanf("%d", &clave);
            limpiar_buffer(); // CORREGIDO: Usar limpiar_buffer() en vez de fflush(stdin)
            arbol = insertar(clave, arbol);
            break;
        case 2:
            printf("\nRecorrido Preorden: ");
            preorden(arbol);
            printf("\n");
            break;
        case 3:
            printf("\nRecorrido Inorden: ");
            inorden(arbol);
            printf("\n");
            break;
        case 4:
            printf("\nRecorrido Postorden: ");
            postorden(arbol);
            printf("\n");
            break;
        case 5:
            printf("\nArbol dibujado:\n");
            imprimir(arbol, 0);
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
            limpiar_buffer();
            printf("\nResultados para el valor %d:\n", valor);
            printf("- Nodos mayores a %d: %d\n", valor, contarMayores(arbol, valor));
            printf("- Nodos menores a %d: %d\n", valor, contarMenores(arbol, valor));
            break;
        case 12:
            printf("Ingrese el valor a buscar: ");
            scanf("%d", &valor);
            limpiar_buffer();
            if (miembro(valor, arbol)) // CORREGIDO: La llamada ahora es más simple
                printf("\nEl valor %d SI existe en el arbol\n", valor);
            else
                printf("\nEl valor %d NO existe en el arbol\n", valor);
            break;
        case 13:
            if (arbol != NULL)
            {
                arbol = suprimeMin(arbol);
                printf("\nSe ha eliminado el elemento mas pequeno del arbol\n");
            }
            else
            {
                printf("\nEl arbol esta vacio\n");
            }
            break;
        case 14:
            if (arbol != NULL)
            {
                printf("\nEl elemento mas pequeno es: %d\n", encontrarMin(arbol));
            }
            else
            {
                printf("\nEl arbol esta vacio\n");
            }
            break;
        case 15:
            if (arbol != NULL)
            {
                arbol = suprimeMax(arbol);
                printf("\nSe ha eliminado el elemento mas grande del arbol\n");
            }
            else
            {
                printf("\nEl arbol esta vacio\n");
            }
            break;
        case 16:
            if (arbol != NULL)
            {
                printf("\nEl elemento mas grande es: %d\n", encontrarMax(arbol));
            }
            else
            {
                printf("\nEl arbol esta vacio\n");
            }
            break;
        case 17:
            if (arbol == NULL) {
                 printf("\nEl arbol esta vacio\n");
                 break;
            }
            printf("Ingresa el valor a eliminar: ");
            scanf("%d", &clave);
            limpiar_buffer();
            arbol = suprimir(clave, arbol);
            break;
        case 0:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opcion no valida.\n");
            break;
        }
    } while (op != 0);
    return 0;
}
