#include <stdio.h>
#include <stdlib.h>
#include "libros_archivo.h"

void guardarLibrosArchivo(struct Libro libros[], int cantidad) {
    FILE *f = fopen("libros.dat", "wb");

    if (f == NULL) {
        printf("\nError al abrir archivo para guardar.\n");
        return;
    }

    fwrite(&cantidad, sizeof(int), 1, f);
    fwrite(libros, sizeof(struct Libro), cantidad, f);

    fclose(f);

    printf("\nLibros guardados correctamente en archivo.\n");
}

int cargarLibrosArchivo(struct Libro libros[]) {
    FILE *f = fopen("libros.dat", "rb");

    if (f == NULL) {
        printf("\nNo existe archivo de libros. Se iniciará vacío.\n");
        return 0;
    }

    int cantidad = 0;

    fread(&cantidad, sizeof(int), 1, f);
    fread(libros, sizeof(struct Libro), cantidad, f);

    fclose(f);

    printf("\nLibros cargados correctamente desde archivo.\n");

    return cantidad;
}
