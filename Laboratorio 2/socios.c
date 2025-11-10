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

int main() {
    struct Socio socios[MAX_SOCIOS];
    int cantidad_socios = 0;

    int opcion;

    do {
        printf("\n====== MENU SOCIOS ======\n");
        printf("1. Agregar socio\n");
        printf("2. Listar socios\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // limpiar ENTER

        switch (opcion) {
            case 1:
                agregarSocio(socios, &cantidad_socios);
                break;

            case 2:
                listarSocios(socios, cantidad_socios);
                break;

            case 0:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción inválida.\n");
        }

    } while (opcion != 0);

    return 0;
}

