// Lista Dinámica Circular de dato compuesto sin nodos de cabecera con 2 apuntadores de referencia (triple apuntador), con enlace doble entre nodos.
//
// Estructura de un nodo:
/// - Dato: Compuesto, puede ser de cualquier tipo.
/// - Apuntador al nodo siguiente.
/// - Apuntador al nodo anterior.
//
// Estructura de la lista:
/// - Apuntador al primer nodo.
/// - Apuntador al último nodo.
///
/// Operaciones:
/// - Inicializar la lista.
/// - Insertar un nuevo nodo.
/// - Eliminar un nodo.
/// - Buscar un nodo.
/// - Mostrar la lista.
///
/// Notas:
/// - La lista se considera vacía si el apuntador al primer nodo es nulo.
/// - El último nodo apunta de vuelta al primer nodo, formando un enlace circular.
/// - Se debe tener cuidado con la gestión de memoria, liberando los nodos eliminados.