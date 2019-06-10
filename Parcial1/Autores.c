#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Autores.h"





void init_Autores(eAutores autores[], int tam)
{
    int CodigoAutor[5] = {1001, 1002, 1003, 1004, 1005};
    char nombre[5][31]= {"Gabriel","julio","Laura","Jorge ","Ernesto"};
    char apellido[5][31]= {" Marquez","Cortazar","Esquivel","Borges","Sabato"};


    for(int i=0; i<tam; i++)
    {
        autores[i].CodigoAutor=CodigoAutor[i];
        strcpy(autores[i].nombre, nombre[i]);
        strcpy(autores[i].apellido, apellido[i]);

    }
}


int obtener_Autor(eAutores autor[], int tam, int idAutor, char nombre[],char apellido[])
{

    int encontro = 0;

    for(int i=0; i < tam; i++)
    {

        if(idAutor == autor[i].CodigoAutor)
        {
            strcpy(nombre, autor[i].nombre);
            strcpy(apellido, autor[i].apellido);
            encontro = 1;
            break;
        }
    }

    return encontro;
}


void mostrar_Autores(eAutores autor[],int tam)
{
    printf("ID  Nombre   Apellido\n");
    for (int i=0; i<tam; i++)
    {
        printf("%d %12s %12s\n",autor[i].CodigoAutor,autor[i].nombre,autor[i].apellido);
    }
}

