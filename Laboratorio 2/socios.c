#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socios.h"

void agregarSocio(struct Socio socios[], int *cantidad) {
    if (*cantidad >= MAX_SOCIOS) {
        printf("\nNo se pueden agregar más socios (límite alcanzado).\n");
        return;
    }

    struct Socio nuevo;

    printf("\n--- Registro de Nuevo Socio ---\n");
    printf("ID del socio: ");
    scanf("%d", &nuevo.id);
    getchar();  // limpiar ENTER

    printf("Nombre del socio: ");
    fgets(nuevo.nombre, MAX_TEXTO, stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = 0;

    printf("Correo del socio: ");
    fgets(nuevo.correo, MAX_TEXTO, stdin);
    nuevo.correo[strcspn(nuevo.correo, "\n")] = 0;

    socios[*cantidad] = nuevo;
    (*cantidad)++;

    printf("\nSocio agregado correctamente!\n");
}

void listarSocios(struct Socio socios[], int cantidad) {
    if (cantidad == 0) {
        printf("\nNo hay socios cargados.\n");
        return;
    }

    printf("\n--- Lista de Socios ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("ID: %d\n", socios[i].id);
        printf("Nombre: %s\n", socios[i].nombre);
        printf("Correo: %s\n", socios[i].correo);
        printf("-------------------------\n");
    }
}
