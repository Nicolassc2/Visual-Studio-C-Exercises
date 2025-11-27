#include <stdio.h>
#include <string.h>
#include "reporte_general.h"

void generarReporte(
    struct Libro libros[], int cantLibros,
    struct Socio socios[], int cantSocios,
    struct Prestamo prestamos[], int cantPrestamos
) {
    int totalLibros = cantLibros;
    int totalDisponibles = 0;
    int totalPrestados = 0;

    // Cantidad total y disponibles
    for (int i = 0; i < cantLibros; i++) {
        totalDisponibles += libros[i].disponible;
        totalPrestados += (libros[i].cantidad - libros[i].disponible);
    }
// Préstamos activos
    int prestamosActivos = 0;
    for (int i = 0; i < cantPrestamos; i++) {
        if (prestamos[i].activo == 1)
            prestamosActivos++;
    }
// Libro más prestado
    int maxPrestamos = -1;
    int idLibroMasPrestado = -1;

    for (int i = 0; i < cantLibros; i++) {
        int prestadosDeEste = libros[i].cantidad - libros[i].disponible;
        if (prestadosDeEste > maxPrestamos) {
            maxPrestamos = prestadosDeEste;
            idLibroMasPrestado = i;
        }
    }
// Socio con más préstamos
    int maxPrestamosSocio = -1;
    int idSocioMax = -1;

    for (int i = 0; i < cantSocios; i++) {
        int prestamosSocio = 0;

        for (int j = 0; j < cantPrestamos; j++) {
            if (prestamos[j].activo == 1 && prestamos[j].idSocio == socios[i].id)
                prestamosSocio++;
        }

        if (prestamosSocio > maxPrestamosSocio) {
            maxPrestamosSocio = prestamosSocio;
            idSocioMax = i;
        }
    }
// esto es lo que se muetra en el main
    printf("\n==============================================\n");
    printf("            REPORTE GENERAL DE LA BIBLIOTECA  \n");
    printf("==============================================\n");

    printf("Total de libros registrados:     %d\n", totalLibros);
    printf("Total disponibles:               %d\n", totalDisponibles);
    printf("Total prestados:                 %d\n", totalPrestados);
    printf("Total socios registrados:        %d\n", cantSocios);
    printf("Préstamos activos:               %d\n", prestamosActivos);

    if (idLibroMasPrestado != -1) {
        printf("\nLibro más prestado: %s (ID %d) - %d préstamos\n",
               libros[idLibroMasPrestado].titulo,
               libros[idLibroMasPrestado].id,
               maxPrestamos);
    }

    if (idSocioMax != -1) {
        printf("Socio con más préstamos: %s (ID %d) - %d préstamos activos\n",
               socios[idSocioMax].nombre,
               socios[idSocioMax].id,
               maxPrestamosSocio);
    }

    printf("==============================================\n");
}
