// Cola Dinámica de enteros con nodo de cabecera, con enlace simple entre nodos.

// Definición del nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Definición de la cola
class Cola {
private:
    Nodo* frente;
    Nodo* atras;
public:
    Cola();
    ~Cola();
    void encolar(int elemento);
    void desencolar();
    int obtenerFrente();
    bool esVacia();
};