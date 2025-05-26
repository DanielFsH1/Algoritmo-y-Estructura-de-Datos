// Cola Dinámica Circular de enteros sin nodos de cabecera con 2 apuntadores de referencia (triple apuntador), con enlace doble entre nodos.
//
// Estructura de un nodo de la cola
// Un nodo de la cola contiene un valor entero y dos punteros: uno al siguiente nodo y otro al nodo anterior.
//
// Estructura de la cola
// La cola en sí misma es una estructura que contiene punteros al primer y último nodo, así como un contador del número de nodos.
//
// Operaciones sobre la cola
// Las operaciones típicas sobre la cola incluyen:
// - Inicialización de la cola
// - Comprobación de si la cola está vacía
// - Inserción de un nuevo nodo al final de la cola
// - Eliminación de un nodo del frente de la cola
// - Liberación de toda la memoria utilizada por la cola
//
// Notas
// - Esta implementación de una cola dinámica circular permite un uso eficiente de la memoria al no requerir nodos de cabecera.
// - El uso de punteros dobles entre nodos permite una fácil inserción y eliminación de nodos en la cola.
// - La cola es circular, lo que significa que el último nodo está conectado de vuelta al primer nodo, formando un círculo.