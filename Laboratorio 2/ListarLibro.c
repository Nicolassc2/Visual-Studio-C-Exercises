#include <stdio.h>
#include <stdlib.h>
#include "libros.h"

int cantidad_libros = 10000;

struct Libro *libros = NULL;

void inicializar_libros() {
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

int main(){
    inicializar_libros();
    for (int i = 0; i < libros[i].id; i++){
    printf("------------------------------\n");
    printf(" ID: %d\n Titulo: %s\n Autor: %s\n Año: %d\n Cantidad: %d\n", 
        libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].cantidad);
    } // Aquí podrías agregar código para probar la funcionalidad de los libros.
    printf("------------------------------\n");
    free(libros);
    return 0;
}