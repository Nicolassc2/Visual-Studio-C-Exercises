#include <stdlib.h>
#include "libros.h"

int cantidad_libros = 10000;

struct Libro *libros = NULL;

void inicializar_libros() {
    libros = malloc(cantidad_libros * sizeof(struct Libro));

    if (libros == NULL){
        printf("Error al ingresar en la memoria.\n");
        return 1;
    }

    libros[0] = (struct Libro){00001,"El Libro de la Selva", "Rudyard Kipling",1894,5};
    libros[1] = (struct Libro){00002,"El Principito", "Antoine de Saint-Exupéry",1943,0};
}