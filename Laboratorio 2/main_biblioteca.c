#include <stdio.h>
#include <stdlib.h>

#include "socios.h"
#include "libros.h"
#include "prestamos.h"
#include "reporte_general.h"
#include "libros_archivo.h"

int main() {

    struct Libro libros[MAX_LIBROS];
    struct Socio socios[MAX_SOCIOS];
    struct Prestamo prestamos[MAX_PRESTAMOS];
    
    int cantLibros = 0;
    int cantSocios = 0;
    int cantPrestamos = 0;
    int opcion;
    int idLibro;

    do {
        printf("\n===========================================\n");
        printf("          SISTEMA DE BIBLIOTECA\n");
        printf("===========================================\n");
        printf("[1] Agregar libro\n");
        printf("[2] Listar libros\n");
        printf("[3] Prestar libro\n");
        printf("[4] Devolver libro\n");
        printf("[5] Agregar socio\n");
        printf("[6] Listar socios\n");
        printf("[7] Reporte general de biblioteca\n");
        printf("[8] Ordenar libros por id\n");
        printf("[11] Guardar libros en archivo\n");
        printf("[12] Cargar libros desde archivo\n");
        printf("[0] Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // limpiar ENTER

        switch(opcion) {
        //  del 1 al 4 opciones de libros
        case 1:
            agregarLibro(libros, &cantLibros);
            break;

        case 2:
            listarLibros(libros, cantLibros);
            break;

        case 3:
            printf("Ingrese ID del libro que desea prestar: ");
            scanf("%d", &idLibro);
            getchar();
            prestarLibro(libros, cantLibros, idLibro);
            break;

        case 4:
            printf("Ingrese ID del libro a devolver: ");
            scanf("%d", &idLibro);
            getchar();
            devolverLibro(libros, cantLibros, idLibro);
            break;

        // del 5 al 6 opciones de socios
        case 5:
            agregarSocio(socios, &cantSocios);
            break;

        case 6:
            listarSocios(socios, cantSocios);
            break;
        case 7:
            generarReporte(libros, cantLibros, socios, cantSocios, prestamos, cantPrestamos);
            break;
         case 8:
            ordenarLibrosPorID(libros, cantLibros);
            break;
         //9 y 10 parte de archivos   
        case 9:
            guardarLibrosArchivo(libros, cantLibros);
            break;
        case 10:
            cantLibros = cargarLibrosArchivo(libros);
            break;


        case 0:
            printf("\nSaliendo del sistema...\n");
            break;

        default:
            printf("\nOpción inválida, intente nuevamente.\n");
        }

    } while(opcion != 0);

    return 0;
}
