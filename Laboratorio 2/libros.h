#ifndef LIBROS_H
#define LIBROS_H

#include <stdbool.h>   

#define MAX_TEXTO 50
#define MAX_LIBROS 100

struct Libro {
    int id;
    char titulo[MAX_TEXTO];
    char autor[MAX_TEXTO];
    int anio;
    int cantidad;       // stock total
    int disponible;     // stock disponible
};

// Funciones para libros
void agregarLibro(struct Libro libros[], int *cantidad);
void listarLibros(struct Libro libros[], int cantidad);
void prestarLibro(struct Libro libros[], int cantidad, int idLibro);
void devolverLibro(struct Libro libros[], int cantidad, int idLibro);
void ordenarLibrosPorTitulo(struct Libro libros[], int cantidad);
void ordenarLibrosPorID(struct Libro libros[], int cantidad);


#endif

