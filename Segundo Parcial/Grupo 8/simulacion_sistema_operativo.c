#include <stdio.h>

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

// Prototipos
void inicializar_cola(Cola *c);
int cola_vacia(const Cola *c);
void encolar(Cola *c, Proceso p);
Proceso desencolar(Cola *c);
void round_robin(Cola *c, int quantum);

int main() {
    Cola cola;
    int n, quantum;

    inicializar_cola(&cola);

    printf("Numero de procesos: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_PROCESOS) {
        printf("Cantidad de procesos invalida\n");
        return 1;
    }

    printf("Quantum: ");
    if (scanf("%d", &quantum) != 1 || quantum <= 0) {
        printf("Valor de quantum invalido\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        Proceso p;
        printf("Duracion del proceso %d: ", i + 1);
        if (scanf("%d", &p.tiempo_restante) != 1 || p.tiempo_restante <= 0) {
            printf("Duracion invalida\n");
            return 1;
        }
        p.id = i + 1;
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

// Ejecuta los procesos utilizando Round Robin
void round_robin(Cola *c, int quantum) {
    int tiempo_actual = 0;

    while (!cola_vacia(c)) {
        Proceso p = desencolar(c);
        int ejecutado = p.tiempo_restante > quantum ? quantum : p.tiempo_restante;

        printf("Proceso %d ejecuta %d unidades (t = %d -> ", p.id, ejecutado, tiempo_actual);
        tiempo_actual += ejecutado;
        p.tiempo_restante -= ejecutado;
        printf("%d) ", tiempo_actual);

        if (p.tiempo_restante > 0) {
            printf("restan %d\n", p.tiempo_restante);
            encolar(c, p);  // El proceso regresa al final de la cola
        } else {
            printf("finalizado\n");
        }
    }
}
