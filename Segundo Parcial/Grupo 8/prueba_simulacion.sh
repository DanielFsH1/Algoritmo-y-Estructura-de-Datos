#!/bin/sh
# Compila y ejecuta la simulacion con datos de ejemplo

# Compilacion del programa
if ! gcc simulacion_sistema_operativo.c -o simulacion; then
    echo "Error al compilar" >&2
    exit 1
fi

# Datos de prueba: 3 procesos, quantum 2, duraciones 3,4,2
cat <<EOD | ./simulacion
3
2
3
4
2
EOD
