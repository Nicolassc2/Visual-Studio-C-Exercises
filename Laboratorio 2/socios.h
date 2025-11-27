#ifndef SOCIOS_H
#define SOCIOS_H

#define MAX_TEXTO 50
#define MAX_SOCIOS 100

struct Socio {
    int id;
    char nombre[MAX_TEXTO];
    char correo[MAX_TEXTO];
};
// funciones para agregar y listar socios
void agregarSocio(struct Socio socios[], int *cantidad);
 void listarSocios(struct Socio socios[], int cantidad);

#endif
