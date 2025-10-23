#ifndef LIBROS_H
#define LIBROS_H
struct Libro {
int id;
char titulo[30];
char autor[50];
int anio;
int cantidad;
};
extern struct Libro *libros;
extern int cantidad_libros;

#endif
