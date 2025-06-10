//04 - 06 - 25 (Versión Sorprendente)
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcmp en algunas implementaciones de system()
#include <stdbool.h> // Para bool

// --- Definiciones de Colores ANSI ---
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_BOLD          "\x1b[1m"

// --- Constantes ---
#define NOMBRE_ARCHIVO "arbol_bst.dat"
#define MARCADOR_NULO -99999 // Un valor improbable para marcar hijos nulos en el archivo

// --- Estructura del Nodo ---
typedef struct Nodo {
    int clave;
    struct Nodo *izq;
    struct Nodo *der;
} Nodo;

// --- Prototipos de Funciones ---

// Funciones básicas del árbol
Nodo *crearNodo(int clave);
Nodo *insertar(Nodo *raiz, int clave);
Nodo *buscar(Nodo *raiz, int clave);
Nodo *encontrarMinimoNodo(Nodo *nodo); // Auxiliar para eliminar
Nodo *eliminarNodo(Nodo *raiz, int clave);
void destruirArbol(Nodo **raiz);

// Recorridos
void preorden(Nodo *raiz);
void inorden(Nodo *raiz);
void postorden(Nodo *raiz);
void nivelOrden(Nodo *raiz); // Nuevo

// Información del árbol
int altura(Nodo *raiz);
int sumaClaves(Nodo *raiz);
int sumaHojas(Nodo *raiz);
int contarNodos(Nodo *raiz);
int contarHojas(Nodo *raiz);
int contarNodosInternos(Nodo *raiz);
int contarMayoresQue(Nodo *raiz, int valor); // Optimizado
int contarMenoresQue(Nodo *raiz, int valor); // Optimizado
int encontrarMinimo(Nodo *raiz);
int encontrarMaximo(Nodo *raiz);
int contarEnRango(Nodo* raiz, int minVal, int maxVal); // Nuevo

// Visualización
void imprimirArbol(Nodo *raiz, int espacio, int dir); // Mejorado

// Persistencia (Guardar/Cargar)
void guardarArbolRecursivo(Nodo *raiz, FILE *archivo);
bool guardarArbol(Nodo *raiz, const char *nombreArchivo);
Nodo *cargarArbolRecursivo(FILE *archivo);
Nodo *cargarArbol(const char *nombreArchivo);

// Utilidades de UI
void limpiarPantalla();
void esperarTecla();
int leerEntero(const char *mensaje);
void mostrarBanner();

// Menú
typedef enum {
    SALIR = 0,
    INGRESAR,
    BUSCAR,
    ELIMINAR,
    PREORDEN,
    INORDEN,
    POSTORDEN,
    NIVELORDEN,
    IMPRIMIR_ARBOL,
    ALTURA_ARBOL,
    SUMA_CLAVES,
    SUMA_HOJAS,
    CONTAR_NODOS,
    CONTAR_HOJAS,
    CONTAR_NODOS_INTERNOS,
    CONTAR_MAYORES_MENORES,
    ENCONTRAR_MIN_MAX,
    CONTAR_EN_RANGO,
    GUARDAR_ARBOL,
    CARGAR_ARBOL,
    DESTRUIR_ARBOL_OP
} OpcionMenu;

OpcionMenu menu(void);


// --- Implementación de Funciones ---

Nodo *crearNodo(int clave) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        fprintf(stderr, ANSI_COLOR_RED "Error: No se pudo asignar memoria para nuevo nodo.\n" ANSI_COLOR_RESET);
        exit(EXIT_FAILURE); // Termina el programa si no hay memoria
    }
    nuevo->clave = clave;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

Nodo *insertar(Nodo *raiz, int clave) {
    if (raiz == NULL) {
        return crearNodo(clave);
    }
    if (clave < raiz->clave) {
        raiz->izq = insertar(raiz->izq, clave);
    } else if (clave > raiz->clave) {
        raiz->der = insertar(raiz->der, clave);
    } else {
        printf(ANSI_COLOR_YELLOW "Información: El valor %d ya existe en el árbol.\n" ANSI_COLOR_RESET, clave);
    }
    return raiz;
}

Nodo *buscar(Nodo *raiz, int clave) {
    if (raiz == NULL || raiz->clave == clave) {
        return raiz;
    }
    if (clave < raiz->clave) {
        return buscar(raiz->izq, clave);
    }
    return buscar(raiz->der, clave);
}

Nodo *encontrarMinimoNodo(Nodo *nodo) {
    Nodo *actual = nodo;
    while (actual && actual->izq != NULL) {
        actual = actual->izq;
    }
    return actual;
}

Nodo *eliminarNodo(Nodo *raiz, int clave) {
    if (raiz == NULL) {
        printf(ANSI_COLOR_YELLOW "Información: Valor %d no encontrado para eliminar.\n" ANSI_COLOR_RESET, clave);
        return raiz;
    }

    if (clave < raiz->clave) {
        raiz->izq = eliminarNodo(raiz->izq, clave);
    } else if (clave > raiz->clave) {
        raiz->der = eliminarNodo(raiz->der, clave);
    } else { // Nodo encontrado
        // Caso 1: Nodo sin hijos o con un solo hijo
        if (raiz->izq == NULL) {
            Nodo *temp = raiz->der;
            printf(ANSI_COLOR_GREEN "Nodo %d eliminado (tenía 0 o 1 hijo derecho).\n" ANSI_COLOR_RESET, raiz->clave);
            free(raiz);
            return temp;
        } else if (raiz->der == NULL) {
            Nodo *temp = raiz->izq;
            printf(ANSI_COLOR_GREEN "Nodo %d eliminado (tenía 0 o 1 hijo izquierdo).\n" ANSI_COLOR_RESET, raiz->clave);
            free(raiz);
            return temp;
        }

        // Caso 2: Nodo con dos hijos
        // Obtener el sucesor inorden (el más pequeño en el subárbol derecho)
        Nodo *temp = encontrarMinimoNodo(raiz->der);
        // Copiar el contenido del sucesor inorden a este nodo
        raiz->clave = temp->clave;
        // Eliminar el sucesor inorden
        printf(ANSI_COLOR_GREEN "Nodo %d reemplazado por %d y sucesor eliminado.\n" ANSI_COLOR_RESET, clave, temp->clave);
        raiz->der = eliminarNodo(raiz->der, temp->clave);
    }
    return raiz;
}

void destruirArbol(Nodo **raiz) {
    if (*raiz != NULL) {
        destruirArbol(&((*raiz)->izq));
        destruirArbol(&((*raiz)->der));
        // printf(ANSI_COLOR_MAGENTA "Liberando nodo: %d\n" ANSI_COLOR_RESET, (*raiz)->clave); // Para depuración
        free(*raiz);
        *raiz = NULL;
    }
}

void preorden(Nodo *raiz) {
    if (raiz != NULL) {
        printf(ANSI_BOLD "%d " ANSI_COLOR_RESET, raiz->clave);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void inorden(Nodo *raiz) {
    if (raiz != NULL) {
        inorden(raiz->izq);
        printf(ANSI_BOLD "%d " ANSI_COLOR_RESET, raiz->clave);
        inorden(raiz->der);
    }
}

void postorden(Nodo *raiz) {
    if (raiz != NULL) {
        postorden(raiz->izq);
        postorden(raiz->der);
        printf(ANSI_BOLD "%d " ANSI_COLOR_RESET, raiz->clave);
    }
}

void nivelOrden(Nodo *raiz) {
    if (raiz == NULL) return;

    // Usar una cola simple (array como cola circular para simplicidad)
    Nodo* cola[100]; // Asumimos un máximo de 100 nodos para la cola en este ejemplo
    int frente = 0, final = 0;

    cola[final++] = raiz;

    while (frente < final) {
        Nodo *actual = cola[frente++];
        printf(ANSI_BOLD "%d " ANSI_COLOR_RESET, actual->clave);

        if (actual->izq != NULL) {
            cola[final++] = actual->izq;
        }
        if (actual->der != NULL) {
            cola[final++] = actual->der;
        }
        // Manejo de desbordamiento de cola (básico)
        if (final >= 99 && (actual->izq || actual->der)) {
             printf(ANSI_COLOR_RED "\nAdvertencia: Cola de recorrido por niveles llena.\n" ANSI_COLOR_RESET);
             break;
        }
    }
}

int altura(Nodo *raiz) {
    if (raiz == NULL) {
        return -1; // Altura de un árbol vacío o de una hoja (convención)
    }
    int alturaIzq = altura(raiz->izq);
    int alturaDer = altura(raiz->der);
    return (alturaIzq > alturaDer ? alturaIzq : alturaDer) + 1;
}

int sumaClaves(Nodo *ptr) {
    if (ptr == NULL) {
        return 0;
    }
    return ptr->clave + sumaClaves(ptr->izq) + sumaClaves(ptr->der);
}

int sumaHojas(Nodo *ptr) {
    if (ptr == NULL) {
        return 0;
    }
    if (ptr->izq == NULL && ptr->der == NULL) { // Es una hoja
        return ptr->clave;
    }
    return sumaHojas(ptr->izq) + sumaHojas(ptr->der);
}

int contarNodos(Nodo *ptr) {
    if (ptr == NULL) {
        return 0;
    }
    return 1 + contarNodos(ptr->izq) + contarNodos(ptr->der);
}

int contarHojas(Nodo *ptr) {
    if (ptr == NULL) {
        return 0;
    }
    if (ptr->izq == NULL && ptr->der == NULL) {
        return 1;
    }
    return contarHojas(ptr->izq) + contarHojas(ptr->der);
}

int contarNodosInternos(Nodo *ptr) {
    if (ptr == NULL || (ptr->izq == NULL && ptr->der == NULL)) { // No es interno si es nulo o es hoja
        return 0;
    }
    return 1 + contarNodosInternos(ptr->izq) + contarNodosInternos(ptr->der);
}

// Optimizado: si la clave actual no es mayor, no necesitamos buscar en el subárbol izquierdo (para mayores)
int contarMayoresQue(Nodo *ptr, int valor) {
    if (ptr == NULL) {
        return 0;
    }
    int contador = 0;
    if (ptr->clave > valor) {
        contador = 1 + contarMayoresQue(ptr->izq, valor) + contarMayoresQue(ptr->der, valor);
    } else { // ptr->clave <= valor, solo pueden estar en el subárbol derecho
        contador = contarMayoresQue(ptr->der, valor);
    }
    return contador;
}

// Optimizado: si la clave actual no es menor, no necesitamos buscar en el subárbol derecho (para menores)
int contarMenoresQue(Nodo *ptr, int valor) {
    if (ptr == NULL) {
        return 0;
    }
    int contador = 0;
    if (ptr->clave < valor) {
        contador = 1 + contarMenoresQue(ptr->izq, valor) + contarMenoresQue(ptr->der, valor);
    } else { // ptr->clave >= valor, solo pueden estar en el subárbol izquierdo
        contador = contarMenoresQue(ptr->izq, valor);
    }
    return contador;
}

int encontrarMinimo(Nodo *raiz) {
    if (raiz == NULL) {
        fprintf(stderr, ANSI_COLOR_RED "Error: Árbol vacío, no se puede encontrar mínimo.\n" ANSI_COLOR_RESET);
        return -1; // O un valor de error adecuado
    }
    Nodo *actual = raiz;
    while (actual->izq != NULL) {
        actual = actual->izq;
    }
    return actual->clave;
}

int encontrarMaximo(Nodo *raiz) {
    if (raiz == NULL) {
        fprintf(stderr, ANSI_COLOR_RED "Error: Árbol vacío, no se puede encontrar máximo.\n" ANSI_COLOR_RESET);
        return -1; // O un valor de error adecuado
    }
    Nodo *actual = raiz;
    while (actual->der != NULL) {
        actual = actual->der;
    }
    return actual->clave;
}

int contarEnRango(Nodo* raiz, int minVal, int maxVal) {
    if (raiz == NULL) {
        return 0;
    }
    int cuenta = 0;
    if (raiz->clave >= minVal && raiz->clave <= maxVal) {
        cuenta = 1 + contarEnRango(raiz->izq, minVal, maxVal) + contarEnRango(raiz->der, minVal, maxVal);
    } else if (raiz->clave < minVal) {
        // Si la clave actual es menor que minVal, todos los nodos en el rango (si existen)
        // deben estar en el subárbol derecho.
        cuenta = contarEnRango(raiz->der, minVal, maxVal);
    } else { // raiz->clave > maxVal
        // Si la clave actual es mayor que maxVal, todos los nodos en el rango (si existen)
        // deben estar en el subárbol izquierdo.
        cuenta = contarEnRango(raiz->izq, minVal, maxVal);
    }
    return cuenta;
}

// dir: 0 para raíz, -1 para izquierdo, 1 para derecho
void imprimirArbol(Nodo *raiz, int espacio, int dir) {
    if (raiz == NULL) return;

    espacio += 5; // Aumenta la distancia entre niveles

    // Procesar hijo derecho primero (se imprime arriba)
    imprimirArbol(raiz->der, espacio, 1);

    // Imprimir nodo actual después del espacio
    printf("\n");
    for (int i = 5; i < espacio; i++) printf(" ");
    
    if (dir == 0) // Nodo raíz
        printf(ANSI_BOLD ANSI_COLOR_MAGENTA "%d(R)" ANSI_COLOR_RESET, raiz->clave);
    else if (dir == 1) // Hijo derecho
        printf(ANSI_BOLD ANSI_COLOR_CYAN "/ %d" ANSI_COLOR_RESET, raiz->clave);
    else // Hijo izquierdo
        printf(ANSI_BOLD ANSI_COLOR_YELLOW "\\ %d" ANSI_COLOR_RESET, raiz->clave);

    // Procesar hijo izquierdo
    imprimirArbol(raiz->izq, espacio, -1);
}


void guardarArbolRecursivo(Nodo *raiz, FILE *archivo) {
    if (raiz == NULL) {
        fprintf(archivo, "%d\n", MARCADOR_NULO);
        return;
    }
    fprintf(archivo, "%d\n", raiz->clave);
    guardarArbolRecursivo(raiz->izq, archivo);
    guardarArbolRecursivo(raiz->der, archivo);
}

bool guardarArbol(Nodo *raiz, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        perror(ANSI_COLOR_RED "Error al abrir archivo para guardar" ANSI_COLOR_RESET);
        return false;
    }
    guardarArbolRecursivo(raiz, archivo);
    fclose(archivo);
    printf(ANSI_COLOR_GREEN "Árbol guardado en %s exitosamente.\n" ANSI_COLOR_RESET, nombreArchivo);
    return true;
}

Nodo *cargarArbolRecursivo(FILE *archivo) {
    int clave;
    if (fscanf(archivo, "%d", &clave) != 1) { // EOF o error de lectura
        return NULL;
    }
    if (clave == MARCADOR_NULO) {
        return NULL;
    }
    Nodo *raiz = crearNodo(clave);
    raiz->izq = cargarArbolRecursivo(archivo);
    raiz->der = cargarArbolRecursivo(archivo);
    return raiz;
}

Nodo *cargarArbol(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        // No es un error si el archivo no existe la primera vez
        // perror(ANSI_COLOR_YELLOW "Advertencia al abrir archivo para cargar" ANSI_COLOR_RESET);
        return NULL;
    }
    Nodo *raiz = cargarArbolRecursivo(archivo);
    fclose(archivo);
    if (raiz)
      printf(ANSI_COLOR_GREEN "Árbol cargado desde %s exitosamente.\n" ANSI_COLOR_RESET, nombreArchivo);
    else
      printf(ANSI_COLOR_YELLOW "No se cargó ningún árbol (archivo vacío o formato incorrecto).\n" ANSI_COLOR_RESET);
    return raiz;
}


void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear"); // Funciona en Linux/Mac
#endif
}

void esperarTecla() {
    printf(ANSI_COLOR_YELLOW "\nPresione Enter para continuar..." ANSI_COLOR_RESET);
    // Limpiar buffer de entrada residual antes de getchar()
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Consume hasta newline o EOF
    getchar(); // Espera el Enter
}

// Lee un entero de forma segura
int leerEntero(const char *mensaje) {
    int valor;
    char buffer[100];
    int valido;
    do {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &valor) == 1) {
                // Verificar si hay caracteres extra después del número
                char extra;
                if (sscanf(buffer, "%d %c", &valor, &extra) == 1) {
                     valido = 1;
                } else {
                    printf(ANSI_COLOR_RED "Entrada inválida. Por favor, ingrese solo un número.\n" ANSI_COLOR_RESET);
                    valido = 0;
                }
            } else {
                printf(ANSI_COLOR_RED "Entrada inválida. Por favor, ingrese un número entero.\n" ANSI_COLOR_RESET);
                valido = 0;
            }
        } else {
             printf(ANSI_COLOR_RED "Error de lectura.\n" ANSI_COLOR_RESET);
             valido = 0; // Podría ser EOF, manejar según necesidad
             exit(EXIT_FAILURE); // Salir en caso de error grave de entrada
        }
    } while (!valido);
    return valor;
}

void mostrarBanner() {
    printf(ANSI_BOLD ANSI_COLOR_GREEN);
    printf("*********************************************************\n");
    printf("*                                                       *\n");
    printf("*        🌳  Super Árbol Binario de Búsqueda 🌳        *\n");
    printf("*                                                       *\n");
    printf("*********************************************************\n");
    printf(ANSI_COLOR_RESET);
}


OpcionMenu menu() {
    int op;
    printf(ANSI_BOLD ANSI_COLOR_BLUE "\n--- MENÚ PRINCIPAL ---\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "1.  Ingresar Nodo\n");
    printf("2.  Buscar Nodo\n");
    printf("3.  Eliminar Nodo\n");
    printf(ANSI_COLOR_MAGENTA "--- Recorridos ---\n");
    printf("4.  Mostrar Preorden\n");
    printf("5.  Mostrar Inorden\n");
    printf("6.  Mostrar Postorden\n");
    printf("7.  Mostrar Nivel-Orden\n");
    printf(ANSI_COLOR_YELLOW "--- Visualización e Información ---\n");
    printf("8.  Imprimir Árbol Gráfico\n");
    printf("9.  Calcular Altura del Árbol\n");
    printf("10. Suma Total de Claves\n");
    printf("11. Suma de Claves de Hojas\n");
    printf("12. Contar Nodos Totales\n");
    printf("13. Contar Hojas\n");
    printf("14. Contar Nodos Internos\n");
    printf("15. Contar Nodos Mayores/Menores que un Valor\n");
    printf("16. Encontrar Clave Mínima y Máxima\n");
    printf("17. Contar Nodos en un Rango\n");
    printf(ANSI_COLOR_GREEN "--- Persistencia ---\n");
    printf("18. Guardar Árbol a Archivo\n");
    printf("19. Cargar Árbol desde Archivo\n");
    printf(ANSI_COLOR_RED "--- Gestión ---\n");
    printf("20. Destruir Árbol (Vaciar)\n");
    printf("0.  Salir\n" ANSI_COLOR_RESET);
    
    op = leerEntero(ANSI_BOLD "Seleccione una opción: " ANSI_COLOR_RESET);
    return (OpcionMenu)op;
}


int main() {
    OpcionMenu op;
    int clave, valor, minVal, maxVal;
    Nodo *arbol = NULL;
    Nodo *encontrado = NULL;

    // Intentar cargar el árbol al inicio
    arbol = cargarArbol(NOMBRE_ARCHIVO);
    if (arbol) esperarTecla();


    do {
        limpiarPantalla();
        mostrarBanner();
        if (arbol == NULL) {
            printf(ANSI_COLOR_YELLOW "El árbol está actualmente vacío.\n" ANSI_COLOR_RESET);
        }
        op = menu();
        limpiarPantalla(); // Limpiar para mostrar resultado de la opción
        mostrarBanner();   // Mostrar banner de nuevo

        switch (op) {
            case INGRESAR:
                clave = leerEntero("Ingrese el valor a guardar en el árbol: ");
                arbol = insertar(arbol, clave);
                break;
            case BUSCAR:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío.\n" ANSI_COLOR_RESET); break; }
                clave = leerEntero("Ingrese el valor a buscar: ");
                encontrado = buscar(arbol, clave);
                if (encontrado != NULL) {
                    printf(ANSI_COLOR_GREEN "Valor %d encontrado en el árbol.\n" ANSI_COLOR_RESET, clave);
                } else {
                    printf(ANSI_COLOR_RED "Valor %d NO encontrado en el árbol.\n" ANSI_COLOR_RESET, clave);
                }
                break;
            case ELIMINAR:
                 if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío.\n" ANSI_COLOR_RESET); break; }
                clave = leerEntero("Ingrese el valor a eliminar: ");
                arbol = eliminarNodo(arbol, clave); // eliminarNodo maneja mensajes
                break;
            case PREORDEN:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío.\n" ANSI_COLOR_RESET); break; }
                printf(ANSI_BOLD ANSI_COLOR_CYAN "\nRecorrido Preorden: " ANSI_COLOR_RESET);
                preorden(arbol);
                printf("\n");
                break;
            case INORDEN:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío.\n" ANSI_COLOR_RESET); break; }
                printf(ANSI_BOLD ANSI_COLOR_CYAN "\nRecorrido Inorden (ordenado): " ANSI_COLOR_RESET);
                inorden(arbol);
                printf("\n");
                break;
            case POSTORDEN:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío.\n" ANSI_COLOR_RESET); break; }
                printf(ANSI_BOLD ANSI_COLOR_CYAN "\nRecorrido Postorden: " ANSI_COLOR_RESET);
                postorden(arbol);
                printf("\n");
                break;
            case NIVELORDEN:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío.\n" ANSI_COLOR_RESET); break; }
                printf(ANSI_BOLD ANSI_COLOR_CYAN "\nRecorrido por Niveles: " ANSI_COLOR_RESET);
                nivelOrden(arbol);
                printf("\n");
                break;
            case IMPRIMIR_ARBOL:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío.\n" ANSI_COLOR_RESET); break; }
                printf(ANSI_BOLD ANSI_COLOR_YELLOW "\n--- Representación Gráfica del Árbol --- \n" ANSI_COLOR_RESET);
                printf(ANSI_COLOR_MAGENTA "(El árbol se muestra rotado 90 grados a la izquierda. La raíz está a la izquierda)\n" ANSI_COLOR_RESET);
                imprimirArbol(arbol, 0, 0);
                printf("\n\n");
                break;
            case ALTURA_ARBOL:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío.\n" ANSI_COLOR_RESET); break; }
                printf(ANSI_BOLD ANSI_COLOR_YELLOW "\nLa altura del árbol es: %d\n" ANSI_COLOR_RESET, altura(arbol));
                break;
            case SUMA_CLAVES:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío.\n" ANSI_COLOR_RESET); break; }
                printf(ANSI_BOLD ANSI_COLOR_YELLOW "\nLa suma de todas las claves es: %d\n" ANSI_COLOR_RESET, sumaClaves(arbol));
                break;
            case SUMA_HOJAS:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío.\n" ANSI_COLOR_RESET); break; }
                printf(ANSI_BOLD ANSI_COLOR_YELLOW "\nLa suma de las claves de las hojas es: %d\n" ANSI_COLOR_RESET, sumaHojas(arbol));
                break;
            case CONTAR_NODOS:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío.\n" ANSI_COLOR_RESET); break; }
                printf(ANSI_BOLD ANSI_COLOR_YELLOW "\nEl número total de nodos es: %d\n" ANSI_COLOR_RESET, contarNodos(arbol));
                break;
            case CONTAR_HOJAS:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío.\n" ANSI_COLOR_RESET); break; }
                printf(ANSI_BOLD ANSI_COLOR_YELLOW "\nEl número de hojas es: %d\n" ANSI_COLOR_RESET, contarHojas(arbol));
                break;
            case CONTAR_NODOS_INTERNOS:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío.\n" ANSI_COLOR_RESET); break; }
                printf(ANSI_BOLD ANSI_COLOR_YELLOW "\nEl número de nodos internos es: %d\n" ANSI_COLOR_RESET, contarNodosInternos(arbol));
                break;
            case CONTAR_MAYORES_MENORES:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío.\n" ANSI_COLOR_RESET); break; }
                valor = leerEntero("Ingrese el valor de referencia: ");
                printf(ANSI_BOLD ANSI_COLOR_YELLOW "\nResultados para el valor de referencia %d:\n" ANSI_COLOR_RESET, valor);
                printf("- Nodos con clave mayor que %d: %d\n", valor, contarMayoresQue(arbol, valor));
                printf("- Nodos con clave menor que %d: %d\n", valor, contarMenoresQue(arbol, valor));
                break;
            case ENCONTRAR_MIN_MAX:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío.\n" ANSI_COLOR_RESET); break; }
                printf(ANSI_BOLD ANSI_COLOR_YELLOW "\nClave mínima en el árbol: %d\n" ANSI_COLOR_RESET, encontrarMinimo(arbol));
                printf(ANSI_BOLD ANSI_COLOR_YELLOW "Clave máxima en el árbol: %d\n" ANSI_COLOR_RESET, encontrarMaximo(arbol));
                break;
            case CONTAR_EN_RANGO:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío.\n" ANSI_COLOR_RESET); break; }
                minVal = leerEntero("Ingrese el valor mínimo del rango: ");
                maxVal = leerEntero("Ingrese el valor máximo del rango: ");
                if (minVal > maxVal) {
                    printf(ANSI_COLOR_RED "Error: El valor mínimo no puede ser mayor que el máximo.\n" ANSI_COLOR_RESET);
                } else {
                    printf(ANSI_BOLD ANSI_COLOR_YELLOW "\nNúmero de nodos con claves entre %d y %d (inclusive): %d\n" ANSI_COLOR_RESET, 
                           minVal, maxVal, contarEnRango(arbol, minVal, maxVal));
                }
                break;
            case GUARDAR_ARBOL:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol vacío. Nada que guardar.\n" ANSI_COLOR_RESET); break; }
                guardarArbol(arbol, NOMBRE_ARCHIVO);
                break;
            case CARGAR_ARBOL:
                destruirArbol(&arbol); // Liberar memoria del árbol actual antes de cargar uno nuevo
                printf("Intentando cargar árbol desde %s...\n", NOMBRE_ARCHIVO);
                arbol = cargarArbol(NOMBRE_ARCHIVO);
                if (arbol == NULL) {
                    printf(ANSI_COLOR_YELLOW "No se pudo cargar el árbol o el archivo está vacío/no existe.\n" ANSI_COLOR_RESET);
                }
                break;
            case DESTRUIR_ARBOL_OP:
                if (!arbol) { printf(ANSI_COLOR_RED "Árbol ya está vacío.\n" ANSI_COLOR_RESET); break; }
                destruirArbol(&arbol);
                printf(ANSI_COLOR_GREEN "Árbol destruido. Toda la memoria ha sido liberada.\n" ANSI_COLOR_RESET);
                break;
            case SALIR:
                printf(ANSI_BOLD ANSI_COLOR_GREEN "\n¡Gracias por usar el Super Árbol! Guardando antes de salir...\n" ANSI_COLOR_RESET);
                if (arbol) { // Solo guardar si hay algo que guardar
                    guardarArbol(arbol, NOMBRE_ARCHIVO);
                }
                destruirArbol(&arbol); // Siempre liberar memoria al salir
                printf(ANSI_BOLD ANSI_COLOR_GREEN "Memoria liberada. ¡Hasta pronto!\n" ANSI_COLOR_RESET);
                break;
            default:
                printf(ANSI_COLOR_RED "\nOpción no válida. Por favor, intente de nuevo.\n" ANSI_COLOR_RESET);
        }
        if (op != SALIR) {
            esperarTecla();
        }

    } while (op != SALIR);

    return 0;
}