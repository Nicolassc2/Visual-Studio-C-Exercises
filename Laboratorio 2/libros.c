#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libros.h"

//  funcion agregar libro

void agregarLibro(struct Libro libros[], int *cantidad) {
    if (*cantidad >= MAX_LIBROS) {
        printf("\nNo se pueden agregar más libros.\n");
        return;
    }

    struct Libro nuevo;

    printf("\n--- Registro de Nuevo Libro ---\n");
    
    printf("ID del libro: ");
    scanf("%d", &nuevo.id);
    getchar();

    printf("Título: ");
    fgets(nuevo.titulo, MAX_TEXTO, stdin);
    nuevo.titulo[strcspn(nuevo.titulo, "\n")] = 0;

    printf("Autor: ");
    fgets(nuevo.autor, MAX_TEXTO, stdin);
    nuevo.autor[strcspn(nuevo.autor, "\n")] = 0;

    printf("Año: ");
    scanf("%d", &nuevo.anio);
    getchar();

    printf("Cantidad total de ejemplares: ");
    scanf("%d", &nuevo.cantidad);
    getchar();

    nuevo.disponible = nuevo.cantidad;

    libros[*cantidad] = nuevo;
    (*cantidad)++;

    printf("\nLibro agregado correctamente.\n");
}

//  funcion listar libros

void listarLibros(struct Libro libros[], int cantidad) {
    if (cantidad == 0) {
        printf("\nNo hay libros cargados.\n");
        return;
    }

    printf("\n--- Lista de Libros ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("ID: %d\n", libros[i].id);
        printf("Título: %s\n", libros[i].titulo);
        printf("Autor: %s\n", libros[i].autor);
        printf("Año: %d\n", libros[i].anio);
        printf("Cantidad total: %d\n", libros[i].cantidad);
        printf("Disponibles: %d\n", libros[i].disponible);
        printf("------------------------\n");
    }
}

// funcion prestar libro

void prestarLibro(struct Libro libros[], int cantidad, int idLibro) {
    for (int i = 0; i < cantidad; i++) {
        if (libros[i].id == idLibro) {
            
            if (libros[i].disponible > 0) {
                libros[i].disponible--;
                printf("\nEl libro '%s' fue prestado correctamente.\n", libros[i].titulo);
            } else {
                printf("\nNO HAY STOCK disponible del libro '%s'.\n", libros[i].titulo);
            }
            return;
        }
    }

    printf("\nNo se encontró un libro con ese ID.\n");
}

//  funcion devolver libro

void devolverLibro(struct Libro libros[], int cantidad, int idLibro) {
    for (int i = 0; i < cantidad; i++) {
        if (libros[i].id == idLibro) {

            if (libros[i].disponible < libros[i].cantidad) {
                libros[i].disponible++;
                printf("\nSe devolvió correctamente el libro '%s'.\n", libros[i].titulo);
            } else {
                printf("\nEl libro '%s' ya estaba completo en stock.\n", libros[i].titulo);
            }
            return;
        }
    }

    printf("\nNo existe un libro con ese ID.\n");
}
// funcion para ordenar libro por id 
void ordenarLibrosPorID(struct Libro libros[], int cantidad) {
    struct Libro aux;

    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (libros[j].id > libros[j+1].id) {
                aux = libros[j];
                libros[j] = libros[j+1];
                libros[j+1] = aux;
            }
        }
    }

    printf("\nLibros ordenados por ID.\n");
}
