#ifndef LIBROS_ARCHIVO_H
#define LIBROS_ARCHIVO_H

#include "libros.h" 

void guardarLibrosArchivo(struct Libro libros[], int cantidad);
int  cargarLibrosArchivo(struct Libro libros[]);

#endif
