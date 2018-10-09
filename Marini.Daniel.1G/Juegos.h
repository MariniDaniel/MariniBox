#ifndef INPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char descripcion[50];


}eCategoria;



typedef struct
{

    eCategoria id;
    int codigoJuego;
    char descripcion[51];
    int importe;
    int isEmpty;
}eJuegos;

typedef struct
{
    char codigoAlquiler[51];
    int codigoJuego;
    char codigoCliente[51];
    char fecha[51];
    int isEmpty;

}eAlquiler;


int MenuJuegos();
void inicializarJuego(eJuegos* lista,int len);
int primerEspacioligre(eJuegos* lista, int len);
int addJuego(eJuegos* lista, int len, int* altaBanderaJuego);
int findJuego(eJuegos* lista, int len,int codigo);
void BajaJuego(eJuegos* lista, int len);
void imprimirListaJuegos(eJuegos* lista,int len);
void ordenarJuegos(eJuegos* lista, int len);
void modificarJuego(eJuegos* lista,int len);


void cargarCategoria(eCategoria categorias[]);

#endif // INPUT_H_INCLUDED
