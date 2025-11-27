#ifndef REPORTE_H
#define REPORTE_H

#include "libros.h"
#include "socios.h"
#include "prestamos.h"

void generarReporte(
    struct Libro libros[], int cantLibros,
    struct Socio socios[], int cantSocios,
    struct Prestamo prestamos[], int cantPrestamos
);

#endif
