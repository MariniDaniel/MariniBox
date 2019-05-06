#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAM_SOCIOS 5
#define TAM_LIBROS 10
#define TAM_AUTORES 10
#define TAM_PRESTAMOS 10
#include "Socios.h"

int main()
{
    //Parcial Numero 1 primera parte 2019 1c
    //Prestamos de un libreo
    //Todos libreos de un autor
    //Cual es el autor que se presto mas libros
    //Todos los orestamos de hombres
    //Todos los prestamos de mujeres
    //Numeros de telefono de quien alquilo tal libro

    eSocio listaSocios[TAM_SOCIOS];
    eLibro listaLibros[TAM_LIBROS];
    eAutores listaAutores[TAM_AUTORES];
    ePrestamo listaPrestamos[TAM_PRESTAMOS];


    int opcion;


    inicializar_Socios(listaSocios,TAM_SOCIOS);
    init_Autores(listaAutores,TAM_AUTORES);
    init_Libros(listaLibros,TAM_LIBROS);




    do
    {

        //Menu Primera parte
        printf("Bienvenidos Al Primer ABM 2019\n");
        printf("  ----ABM  Socios---- \n\n");
        printf("1- Alta Socios \n");
        printf("2- Listar Socios \n");
        printf("3- Modificar Socios \n");
        printf("4- Baja Socios \n");
        printf("5- Listar Libros \n");
        printf("6-Prestamos no hecho\n");
        printf("7- Salir  \n\n");
        printf("Ingrese opcion:   ");
        fflush(stdin);
        scanf("%d", &opcion);


        switch(opcion)
        {
        case 1:

            alta_Socios(listaSocios,TAM_SOCIOS);

            break;
        case 2:

            if(hay_Socios_Cargados(listaSocios,TAM_SOCIOS)==0)
            {
                system("cls");
                ordenar_Socios(listaSocios,TAM_SOCIOS);

            }
            else
            {
                printf("\nPrimero realize la alta de un empleado\n\n");

            }


            break;
        case 3:
            if(hay_Socios_Cargados(listaSocios,TAM_SOCIOS)==0)
            {
                system("cls");
                modificar_Socios(listaSocios,TAM_SOCIOS);


            }
            else
            {
                printf("\nPrimero realize la alta de un empleado\n\n");

            }


            break;
        case 4:
            if(hay_Socios_Cargados(listaSocios,TAM_SOCIOS)==0)
            {
                system("cls");

                baja_Socios(listaSocios,TAM_SOCIOS);


            }
            else
            {
                printf("\nPrimero realize la alta de un empleado\n\n");

            }


            break;
        case 5:
            mostrar_Libros(listaLibros,TAM_LIBROS);
            break;


        case 6:
            if(hay_Socios_Cargados(listaSocios,TAM_SOCIOS)==0)
            {
                system("cls");

                //alta_Prestamos()


            }
            else
            {
                printf("\nPrimero realize la alta de un empleado\n\n");

            }


            break;
        case 7:
            printf("\nADIOS\n");
            break;
        default:
            printf("\nERROR! Por favor ingrese una opcion valida del 1 al 6\n");
            break;

        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(opcion!=6);



    return 0;
}
