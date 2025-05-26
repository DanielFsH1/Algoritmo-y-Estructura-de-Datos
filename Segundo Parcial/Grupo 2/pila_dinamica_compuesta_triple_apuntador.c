// Pila Dinámica de dato compuesto sin nodo de cabecera (apuntador triple), con enlace simple entre nodos.
//
// Este archivo contiene la implementación de una pila dinámica que almacena datos compuestos
// sin necesidad de un nodo de cabecera. Se utiliza un apuntador triple para gestionar los nodos
// de la pila, y cada nodo contiene un enlace simple al siguiente nodo en la pila.
//
// Estructura del nodo:
// - Un campo para almacenar el dato compuesto.
// - Un apuntador al siguiente nodo en la pila.
//
// Operaciones soportadas:
// - Inicialización de la pila.
// - Verificación de si la pila está vacía.
// - Inserción de un nuevo elemento en la pila (push).
// - Eliminación del elemento superior de la pila (pop).
// - Obtención del elemento superior de la pila sin eliminarlo (top).
//
// Notas:
// - La pila se implementa de manera que permite el crecimiento dinámico, es decir, no tiene un
//   tamaño fijo y puede crecer o reducirse según sea necesario.
// - Se debe tener cuidado con la gestión de memoria, asegurando que no haya fugas de memoria
//   al añadir o eliminar nodos de la pila.
//
// Ejemplo de uso:
//   Pila miPila;
//   inicializar(&miPila);
//   int dato1 = 10, dato2 = 20;
//   push(&miPila, &dato1);
//   push(&miPila, &dato2);
//   int* datoSuperior = (int*)top(&miPila);
//   printf("Dato en la cima de la pila: %d\n", *datoSuperior);
//   pop(&miPila);
//   destruirPila(&miPila); // Liberar memoria utilizada por la pila.