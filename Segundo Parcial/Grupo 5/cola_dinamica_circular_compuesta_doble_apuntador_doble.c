// Cola Dinámica Circular de dato compuesto sin nodos de cabecera con 2 apuntadores de referencia (doble apuntador), con enlace doble entre nodos.
//
// Estructura de un nodo
// typedef struct nodo {
//     tipo_dato_compuesto dato;
//     struct nodo * siguiente;
//     struct nodo * anterior;
// } Nodo;
//
// Estructura de la cola
// typedef struct {
//     Nodo * frente;
//     Nodo * fondo;
// } Cola;
//
// Funciones de la cola
// void inicializarCola(Cola * cola);
// int colaVacia(Cola * cola);
// void encolar(Cola * cola, tipo_dato_compuesto dato);
// tipo_dato_compuesto desencolar(Cola * cola);
// void limpiarCola(Cola * cola);
// void destruirCola(Cola * cola);
// void recorrerCola(Cola * cola, void (*funcion)(tipo_dato_compuesto));