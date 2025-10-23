#include <stdio.h>
#include "librosysocios.h"
#include "listar_libros.h"

int main() {
    struct Libro libros[100];
    int cantidad_Libros = 10000;
    int opcion;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Registrar libro\n");
        printf("2. Listar libros\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
               // registrarLibro(libros, &cantidad_Libros);
                break;
            case 2:
             inicializar_libros();
                break;
        }
    } while (opcion != 0);

    return 0;
    return 0;
}
