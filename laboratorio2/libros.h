#ifndef LIBROS_H
#define LIBROS_H

struct Libro {
    int id;
    char titulo[100];
    char autor[100];
    int anio;
    int cantidad;
};

extern struct Libro *libros;
extern int cantidad_libros;

void inicializar_libros(struct Libro *libros, int cantidad_libros);

#endif