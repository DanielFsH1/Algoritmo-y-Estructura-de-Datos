// Cola Dinámica Circular de enteros con 2 nodos de cabecera (2 apuntadores de referencia), con enlace doble entre nodos.
//
// Este archivo implementa una cola utilizando una lista doblemente enlazada circularmente.
// Se utilizan dos nodos de cabecera para mantener la referencia tanto al primer como al último nodo de la cola.
// Esto permite una fácil inserción y eliminación de nodos en ambas extremidades de la cola.
//
// Estructura de un nodo:
// - valor: el valor entero almacenado en el nodo.
// - siguiente: un puntero al siguiente nodo en la cola.
// - anterior: un puntero al nodo anterior en la cola.
//
// Operaciones soportadas:
// - inicializar_cola: Inicializa la cola estableciendo los nodos de cabecera y apuntando su siguiente y anterior entre sí.
// - encolar: Agrega un nuevo valor a la cola.
// - desencolar: Elimina un valor de la cola.
// - es_vacia: Verifica si la cola está vacía.
// - limpiar_cola: Elimina todos los nodos de la cola, liberando la memoria utilizada.
// - destruir_cola: Destruye la cola, liberando la memoria de los nodos de cabecera y de la cola en sí.