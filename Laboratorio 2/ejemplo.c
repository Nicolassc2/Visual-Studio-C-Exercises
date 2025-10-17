#include <stdio.h>
#include "libros.h"


void existelibro(int busqueda){ //Busca si existe el libro dentro del registro de libros.
    int encontrado = 0;
    
    for(int i = 0; i < 20; i++){ //Recorre todo el arreglo de ese registro.
    if(busqueda == libros[i].id){ //Debe comparar solamente mediante ID del libro.
        printf("Este libro está registrado en la biblioteca.\n");
        encontrado = 1;
        break;
    }
}
    
    if(!encontrado){
        printf("Este libro no está registrado en la biblioteca.\n");
    }

}

int main(){
    int buscador;

    printf("Ingrese el ID del libro que desea buscar.\n");
    scanf("%d", &buscador);

    existelibro(buscador);

    return 0;
}
