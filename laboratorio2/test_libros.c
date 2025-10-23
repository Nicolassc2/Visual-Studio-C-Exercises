#include <stdio.h>
#include <stdlib.h>
#include "libros.h"

//void existelibro(int busqueda);

int main(void){
    struct Libro *libros = NULL;

    int buscador;

    inicializar_libros(libros, 5);

    //printf("Ingrese el ID del libro que desea buscar.\n");
    //scanf("%d", &buscador);

    //existelibro(buscador);

    for(int i = 0; i < 5; i++){
        printf("ID: %d\n Titulo: %s\n Autor: %s\n Año: %d\n Cantidad: %d\n", 
        libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].cantidad);
    }

    free(libros);
    return 0;
}