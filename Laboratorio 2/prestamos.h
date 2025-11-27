#ifndef PRESTAMOS_H
#define PRESTAMOS_H

#include "socios.h"
#include "libros.h"

#define MAX_PRESTAMOS 200
#define MAX_PRESTAMOS_POR_SOCIO 3

struct Prestamo {
    int idSocio;
    int idLibro;
    int activo;     // 1 = prestado, 0 = devuelto
};

void registrarPrestamo(struct Prestamo prestamos[], int *cantPrestamos,
                       struct Socio socios[], int cantSocios,
                       struct Libro libros[], int cantLibros);

void devolverPrestamo(struct Prestamo prestamos[], int cantPrestamos,
                      struct Libro libros[], int cantLibros);

void listarPrestamos(struct Prestamo prestamos[], int cantPrestamos);

int contarPrestamosDeSocio(struct Prestamo prestamos[], int cantPrestamos, int idSocio);

#endif
