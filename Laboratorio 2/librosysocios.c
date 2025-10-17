#include <stdbool.h>

struct Libro {
int id;
char titulo[30];
char autor[50];
int anio;
bool disponible;
};

struct Socio {
int id;
char nombre[20];
char apellido[30];
char correo[50];
};