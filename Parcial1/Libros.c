#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Libros.h"


int elegir_libro(eLibro listaLibro[], int tamLibro,eAutores listaAutores[],int tamAutor)
{
    int idLibro;
    int retorno= -1;

    mostrar_Libros_Con_Autor(listaLibro,tamLibro,listaAutores,tamAutor);
    printf("\n Seleccione un libro: ");
    scanf("%d", &idLibro);

    for(int i=0; i < tamLibro; i++)
    {
        if(listaLibro[i].CodigoLibro==idLibro )
        {
            retorno=idLibro;
            break;
        }
    }

    return retorno;
}

void cargarDescripcion_Libro(eLibro listaLibros[], int tamLibros, int idLibro, char titulo[])
{
    for(int i=0; i < tamLibros; i++)
    {
        if( listaLibros[i].CodigoLibro == idLibro)
        {
            strcpy(titulo, listaLibros[i].titulo);
            break;
        }
    }
}




void mostrar_LibroCon_Autor(eAutores autores[], int tamAutor, eLibro libros)
{
    char nombreAutor[31];
    char apellidoAutor[31];

    obtener_Autor(autores, tamAutor, libros.codigoAutor, nombreAutor,apellidoAutor);

    printf("%2d   %15s   %s-%s  \n", libros.CodigoLibro, libros.titulo,nombreAutor,apellidoAutor);

}



int mostrar_Libros_Con_Autor(eLibro libros[], int tamLibro, eAutores autores[], int tamAutor)
{

    int retorno=-1;

    printf("Codigo        Titulo         Autor   \n\n");
    for(int i=0; i < tamLibro; i++)
    {
        mostrar_LibroCon_Autor(autores,tamAutor,libros[i]);

        retorno=0;
    }

    if( retorno == -1)
    {
        printf("\nNo hay libros que mostrar\n");
    }

    return retorno;
}






void mostrarCantLibrosXAutor(eLibro libros[], int tamLibros, eAutores autores[], int tamAutores)
{

    int contador;
    system("cls");

    for(int i=0; i< tamAutores; i++ )
    {
        contador = 0;
        printf("Autor: %s-%s\n\n", autores[i].nombre,autores[i].apellido);

        for(int j=0; j < tamLibros; j++)
        {
            if(autores[i].CodigoAutor == libros[j].codigoAutor)
            {
                contador++;
            }
        }

        printf("Cantidad: %d\n\n", contador);
    }
}


void init_Libros(eLibro libros[], int tam)
{
    int CodigoLibro[10] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    char titulo[10][31]= {"metro 2033","juego de tronos","martin fierro","cuentos","harry potter","lucas","codigo da vinci","inferno","el perfume","el principito"};
    int codigoAutor[10] = { 1001, 1003, 1002, 1002, 1004, 1005, 1004, 1003, 1005, 1001};


    for(int i=0; i<tam; i++)
    {
        libros[i].CodigoLibro=CodigoLibro[i];

        strcpy(libros[i].titulo, titulo[i]);

        libros[i].codigoAutor=codigoAutor[i];



    }
}






