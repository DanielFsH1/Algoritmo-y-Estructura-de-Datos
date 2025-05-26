// Cola Dinámica de dato compuesto sin nodo de cabecera (apuntador triple), con enlace simple entre nodos.
//
// Este archivo contiene la implementación de una cola dinámica que almacena datos compuestos
// sin necesidad de un nodo de cabecera. Cada nodo en la cola contiene un apuntador triple que
// se utiliza para enlazar los nodos entre sí, formando así la estructura de la cola.
//
// Estructura de un nodo:
// ----------------------
// | Apuntador Siguiente  | ---> Apunta al siguiente nodo en la cola.
// | Dato Compuesto       | ---> Almacena el dato compuesto.
// | Apuntador Anterior   | ---> Apunta al nodo anterior en la cola.
// ----------------------
//
// Operaciones soportadas:
// ----------------------
// - Inicializar Cola
// - Verificar si la Cola está Vacía
// - Insertar en la Cola
// - Eliminar de la Cola
// - Obtener el Frente de la Cola
// - Limpiar Cola
//
// Notas:
// ------
// - Esta implementación no utiliza un nodo de cabecera, por lo que las operaciones de inserción
//   y eliminación son ligeramente diferentes en comparación con una cola tradicional con nodo
//   de cabecera.
// - Se debe tener cuidado al manipular los apuntadores para evitar pérdidas de memoria o
//   referencias a nodos inválidos.
//
// Autor: [Tu Nombre]
// Fecha: [Fecha de Creación]
//
// Historial de Cambios:
// ---------------------
// [Fecha] - [Descripción del Cambio]