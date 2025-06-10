#include <stdio.h>

/*
 * Simulacion sencilla de un planificador Round Robin.
 * El programa solicita por consola la cantidad de procesos, el
 * quantum y la duracion de cada proceso. Luego va mostrando paso
 * a paso como se van ejecutando hasta que todos terminan.
 */

#define MAX_PROCESOS 100

// Estructura para representar un proceso
typedef struct {
    int id;                // Identificador del proceso
    int tiempo_restante;   // Tiempo que falta por ejecutar
} Proceso;

// Cola circular para almacenar los procesos
typedef struct {
    Proceso procesos[MAX_PROCESOS];
    int inicio;
    int fin;
} Cola;

/* Funciones auxiliares para manipular la cola de procesos */

// Prototipos
/* Inicializa los indices de la cola vaciandola */
void inicializar_cola(Cola *c);
/* Comprueba si no hay procesos encolados */
int cola_vacia(const Cola *c);
/* Inserta un proceso al final de la cola */
void encolar(Cola *c, Proceso p);
/* Extrae un proceso del inicio de la cola */
Proceso desencolar(Cola *c);
/* Ejecuta todos los procesos aplicando el algoritmo Round Robin */
void round_robin(Cola *c, int quantum);

int main() {
    Cola cola;
    int n, quantum;

    /* Preparamos la cola inicialmente vacia */
    inicializar_cola(&cola);

    /* ---- Entrada de datos ---- */
    printf("Numero de procesos: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_PROCESOS) {
        printf("Cantidad de procesos invalida\n");
        return 1;
    }

    /* Quantum de tiempo para cada proceso */
    printf("Quantum: ");
    if (scanf("%d", &quantum) != 1 || quantum <= 0) {
        printf("Valor de quantum invalido\n");
        return 1;
    }

    /* Solicitar la duracion de cada proceso */
    for (int i = 0; i < n; i++) {
        Proceso p;
        printf("Duracion del proceso %d: ", i + 1);
        if (scanf("%d", &p.tiempo_restante) != 1 || p.tiempo_restante <= 0) {
            printf("Duracion invalida\n");
            return 1;
        }
        p.id = i + 1;
        /* Encolamos cada nuevo proceso */
        encolar(&cola, p);
    }

    printf("\n--- Iniciando simulacion ---\n");
    round_robin(&cola, quantum);

    return 0;
}

// Inicializa la cola
void inicializar_cola(Cola *c) {
    c->inicio = 0;
    c->fin = 0;
}

// Devuelve 1 si la cola esta vacia
int cola_vacia(const Cola *c) {
    return c->inicio == c->fin;
}

// Agrega un proceso al final de la cola
void encolar(Cola *c, Proceso p) {
    c->procesos[c->fin] = p;
    c->fin = (c->fin + 1) % MAX_PROCESOS;
}

// Extrae el proceso al inicio de la cola
Proceso desencolar(Cola *c) {
    Proceso p = c->procesos[c->inicio];
    c->inicio = (c->inicio + 1) % MAX_PROCESOS;
    return p;
}

// Ejecuta los procesos utilizando el algoritmo Round Robin
// mostrando por pantalla el avance de tiempo de cada uno
void round_robin(Cola *c, int quantum) {
    int tiempo_actual = 0;

    while (!cola_vacia(c)) {
        /* Tomamos el siguiente proceso de la cola */
        Proceso p = desencolar(c);

        /* Tiempo que el proceso va a ejecutar en esta ronda */
        int ejecutado = p.tiempo_restante > quantum ? quantum : p.tiempo_restante;

        printf("Proceso %d ejecuta %d unidades (t = %d -> ", p.id, ejecutado, tiempo_actual);
        /* Actualizamos el tiempo global y el restante del proceso */
        tiempo_actual += ejecutado;
        p.tiempo_restante -= ejecutado;
        printf("%d) ", tiempo_actual);

        if (p.tiempo_restante > 0) {
            printf("restan %d\n", p.tiempo_restante);
            /* Si aun queda tiempo por ejecutar, lo reencolamos */
            encolar(c, p);  // El proceso regresa al final de la cola
        } else {
            printf("finalizado\n");
        }
    }
}
