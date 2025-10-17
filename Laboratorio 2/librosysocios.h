#ifndef LIBROSYSOCIOS_H
#define LIBROSYSOCIOS_H

#include <stdbool.h>

struct Libro {
int id;
char titulo[30];
char autor[50];
int anio;
int cantidad;
};

struct Socio {
int id;
char nombre[20];
char apellido[30];
char correo[50];
};

#endif