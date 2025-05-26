// Cola Dinámica de dato compuesto sin nodos de cabecera con 2 apuntadores de referencia (triple apuntador), con enlace doble entre nodos.
//
// Estructura de un nodo de la cola
// Un nodo de la cola contiene un dato y dos punteros: uno al siguiente nodo en la cola y otro al nodo anterior.
//
// Operaciones de la cola
// Las operaciones básicas de la cola (enqueue, dequeue, etc.) se implementan manipulando los punteros de los nodos de manera adecuada.
//
// Notas
// - Esta implementación no utiliza nodos de cabecera.
// - Se requiere un manejo cuidadoso de los punteros para evitar fugas de memoria o corrupción de datos.
//
// Ejemplo de uso
// Cola* miCola = crearCola();
// encolar(miCola, dato1);
// encolar(miCola, dato2);
// dato = desencolar(miCola);