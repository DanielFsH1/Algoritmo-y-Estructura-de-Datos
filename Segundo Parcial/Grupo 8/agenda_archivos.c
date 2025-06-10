#include <stdio.h>
#include <string.h>

// Agenda con almacenamiento en archivo de texto
#define MAX_CONTACTOS 100
#define ARCHIVO "agenda.txt"

typedef struct {
    char nombre[50];
    char apellidos[50];
    char direccion[100];
    char telefono[20];
    char correo[50];
    char cumple[20];
} Contacto;

void leer_linea(char *buffer, int tam) {
    fgets(buffer, tam, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void cargar_agenda(Contacto agenda[], int *n) {
    FILE *f = fopen(ARCHIVO, "r");
    if (!f) return;
    while (*n < MAX_CONTACTOS && fscanf(f, "%49[^|]|%49[^|]|%99[^|]|%19[^|]|%49[^|]|%19[^\n]\n",
               agenda[*n].nombre, agenda[*n].apellidos, agenda[*n].direccion,
               agenda[*n].telefono, agenda[*n].correo, agenda[*n].cumple) == 6) {
        (*n)++;
    }
    fclose(f);
}

void guardar_agenda(Contacto agenda[], int n) {
    FILE *f = fopen(ARCHIVO, "w");
    if (!f) return;
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s|%s|%s|%s|%s|%s\n",
                agenda[i].nombre, agenda[i].apellidos, agenda[i].direccion,
                agenda[i].telefono, agenda[i].correo, agenda[i].cumple);
    }
    fclose(f);
}

void agregar_contacto(Contacto agenda[], int *n) {
    if (*n >= MAX_CONTACTOS) {
        printf("Agenda llena\n");
        return;
    }
    printf("Nombre: ");
    leer_linea(agenda[*n].nombre, sizeof(agenda[*n].nombre));
    printf("Apellidos: ");
    leer_linea(agenda[*n].apellidos, sizeof(agenda[*n].apellidos));
    printf("Direccion: ");
    leer_linea(agenda[*n].direccion, sizeof(agenda[*n].direccion));
    printf("Telefono: ");
    leer_linea(agenda[*n].telefono, sizeof(agenda[*n].telefono));
    printf("Correo: ");
    leer_linea(agenda[*n].correo, sizeof(agenda[*n].correo));
    printf("Cumpleanos: ");
    leer_linea(agenda[*n].cumple, sizeof(agenda[*n].cumple));
    (*n)++;
    guardar_agenda(agenda, *n);
}

void mostrar_agenda(Contacto agenda[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nContacto %d\n", i + 1);
        printf("Nombre: %s %s\n", agenda[i].nombre, agenda[i].apellidos);
        printf("Direccion: %s\n", agenda[i].direccion);
        printf("Telefono: %s\n", agenda[i].telefono);
        printf("Correo: %s\n", agenda[i].correo);
        printf("Cumpleanos: %s\n", agenda[i].cumple);
    }
}

void modificar_contacto(Contacto agenda[], int n) {
    int idx;
    printf("Indice de contacto a modificar (1-%d): ", n);
    scanf("%d", &idx);
    getchar();
    if (idx < 1 || idx > n) {
        printf("Indice invalido\n");
        return;
    }
    idx--;
    printf("-- Modificando contacto --\n");
    printf("Nombre (%s): ", agenda[idx].nombre);
    leer_linea(agenda[idx].nombre, sizeof(agenda[idx].nombre));
    printf("Apellidos (%s): ", agenda[idx].apellidos);
    leer_linea(agenda[idx].apellidos, sizeof(agenda[idx].apellidos));
    printf("Direccion (%s): ", agenda[idx].direccion);
    leer_linea(agenda[idx].direccion, sizeof(agenda[idx].direccion));
    printf("Telefono (%s): ", agenda[idx].telefono);
    leer_linea(agenda[idx].telefono, sizeof(agenda[idx].telefono));
    printf("Correo (%s): ", agenda[idx].correo);
    leer_linea(agenda[idx].correo, sizeof(agenda[idx].correo));
    printf("Cumpleanos (%s): ", agenda[idx].cumple);
    leer_linea(agenda[idx].cumple, sizeof(agenda[idx].cumple));
    guardar_agenda(agenda, n);
}

void eliminar_contacto(Contacto agenda[], int *n) {
    int idx;
    printf("Indice de contacto a eliminar (1-%d): ", *n);
    scanf("%d", &idx);
    getchar();
    if (idx < 1 || idx > *n) {
        printf("Indice invalido\n");
        return;
    }
    idx--;
    for (int i = idx; i < *n - 1; i++) {
        agenda[i] = agenda[i + 1];
    }
    (*n)--;
    guardar_agenda(agenda, *n);
}

int main() {
    Contacto agenda[MAX_CONTACTOS];
    int cantidad = 0;
    cargar_agenda(agenda, &cantidad);
    int opcion;
    do {
        printf("\n1. Agregar\n2. Modificar\n3. Eliminar\n4. Mostrar\n5. Salir\nOpcion: ");
        scanf("%d", &opcion);
        getchar();
        switch(opcion) {
            case 1:
                agregar_contacto(agenda, &cantidad);
                break;
            case 2:
                if (cantidad > 0)
                    modificar_contacto(agenda, cantidad);
                else
                    printf("Agenda vacia\n");
                break;
            case 3:
                if (cantidad > 0)
                    eliminar_contacto(agenda, &cantidad);
                else
                    printf("Agenda vacia\n");
                break;
            case 4:
                mostrar_agenda(agenda, cantidad);
                break;
        }
    } while(opcion != 5);
    return 0;
}
