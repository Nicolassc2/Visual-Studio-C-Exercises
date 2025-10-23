#include <stdio.h>
#include <stdlib.h>
#include "libros.h"

//int cantidad_libros = 5;
//struct Libro *libros = NULL;

void inicializar_libros(struct Libro *libros, int cantidad_libros){
    libros = malloc(cantidad_libros * sizeof(struct Libro));

    if (libros == NULL){
        printf("Error al ingresar en la memoria.\n");
        return;
    }

    libros[0] = (struct Libro){1,"El Libro de la Selva", "Rudyard Kipling",1894,5};
    libros[1] = (struct Libro){2,"El Principito", "Antoine de Saint-Exupéry",1943,0};
    libros[2] = (struct Libro){3,"Cien Años de Soledad", "Gabriel García Márquez",1967,3};
    libros[3] = (struct Libro){4,"Don Quijote de la Mancha", "Miguel de Cervantes",1605,2};
    libros[4] = (struct Libro){5,"1984", "George Orwell",1949,4};
}