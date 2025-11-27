#include <stdio.h>
#include "prestamos.h"

// cantidad de prestamos que tiene un socio
int contarPrestamosDeSocio(struct Prestamo prestamos[], int cantPrestamos, int idSocio) {
    int contador = 0;
    for (int i = 0; i < cantPrestamos; i++) {
        if (prestamos[i].idSocio == idSocio && prestamos[i].activo == 1)
            contador++;
    }
    return contador;
}

// registrar prestamo del socio
void registrarPrestamo(struct Prestamo prestamos[], int *cantPrestamos,
                       struct Socio socios[], int cantSocios,
                       struct Libro libros[], int cantLibros)
{
    if (*cantPrestamos >= MAX_PRESTAMOS) {
        printf("\nNo se pueden registrar más préstamos.\n");
        return;
    }

    int idSocio, idLibro;

    printf("\nID del socio que pide el libro: ");
    scanf("%d", &idSocio);
    getchar();

    // Verificar si el socio existe
    int existeSocio = 0;
    for (int i = 0; i < cantSocios; i++) {
        if (socios[i].id == idSocio) {
            existeSocio = 1;
            break;
        }
    }
    if (!existeSocio) {
        printf("\nNo existe un socio con ese ID.\n");
        return;
    }

    // Verificar cantidad de préstamos
    if (contarPrestamosDeSocio(prestamos, *cantPrestamos, idSocio) >= MAX_PRESTAMOS_POR_SOCIO) {
        printf("\nEl socio alcanzó el máximo de préstamos permitidos (%d).\n",
               MAX_PRESTAMOS_POR_SOCIO);
        return;
    }

    printf("ID del libro a prestar: ");
    scanf("%d", &idLibro);
    getchar();

    // Verificar si existe el libro
    int existeLibro = 0;
    for (int i = 0; i < cantLibros; i++) {
        if (libros[i].id == idLibro)
            existeLibro = 1;
    }
    if (!existeLibro) {
        printf("\nNo existe un libro con ese ID.\n");
        return;
    }

    // Verificar stock 
    // prestarLibro decrementa el stock si puede
    int stockAnterior = 0;

    for (int i = 0; i < cantLibros; i++) {
        if (libros[i].id == idLibro)
            stockAnterior = libros[i].disponible;
    }

    prestarLibro(libros, cantLibros, idLibro);

    // Si no se restó stock, significa que no había
    int stockActual = 0;
    for (int i = 0; i < cantLibros; i++) {
        if (libros[i].id == idLibro)
            stockActual = libros[i].disponible;
    }

    if (stockActual == stockAnterior) {
        printf("\nNo se pudo registrar el préstamo porque no hay stock.\n");
        return;
    }

    // Si llegó hasta aca, se pudo registrar el prestamo
    struct Prestamo nuevo;
    nuevo.idSocio = idSocio;
    nuevo.idLibro = idLibro;
    nuevo.activo = 1;

    prestamos[*cantPrestamos] = nuevo;
    (*cantPrestamos)++;

    printf("\nPréstamo registrado correctamente.\n");
}

// devolver libro (prestamo)
void devolverPrestamo(struct Prestamo prestamos[], int cantPrestamos,
                      struct Libro libros[], int cantLibros)
{
    int idSocio, idLibro;
    printf("\nID del socio: ");
    scanf("%d", &idSocio);
    getchar();

    printf("ID del libro a devolver: ");
    scanf("%d", &idLibro);
    getchar();

    for (int i = 0; i < cantPrestamos; i++) {
        if (prestamos[i].idSocio == idSocio &&
            prestamos[i].idLibro == idLibro &&
            prestamos[i].activo == 1)
        {
            prestamos[i].activo = 0; // marcar como devuelto
            devolverLibro(libros, cantLibros, idLibro);
            printf("\nLibro devuelto correctamente.\n");
            return;
        }
    }

    printf("\nNo existe un préstamo activo con esos datos.\n");
}

// mostrar prestamos activos.
void listarPrestamos(struct Prestamo prestamos[], int cantPrestamos)
{
    printf("\n--- Préstamos Activos ---\n");
    int hay = 0;

    for (int i = 0; i < cantPrestamos; i++) {
        if (prestamos[i].activo == 1) {
            printf("Socio ID: %d  -->  Libro ID: %d\n",
                   prestamos[i].idSocio,
                   prestamos[i].idLibro);
            hay = 1;
        }
    }

    if (!hay)
        printf("No hay préstamos activos.\n");
}
