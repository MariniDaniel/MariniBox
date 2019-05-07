#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Socios.h"
#define TAM_SOCIOS 5
#define TAM_LIBROS 10
#define TAM_AUTORES 10
#define TAM_PRESTAMOS 10
#define VERDAD 1
#define ERROR -1
#define EXITO 0




int main()
{
    //Parcial Numero 1 primera parte 2019 1c


    eSocio listaSocios[TAM_SOCIOS];
    eLibro listaLibros[TAM_LIBROS];
    eAutores listaAutores[TAM_AUTORES];
    ePrestamo listaPrestamos[TAM_PRESTAMOS];


    int opcion;
    int orden;
    int es;


    inicializar_Socios(listaSocios,TAM_SOCIOS);
    init_Autores(listaAutores,TAM_AUTORES);
    init_Libros(listaLibros,TAM_LIBROS);
    inicializar_Prestamo(listaPrestamos,TAM_PRESTAMOS);



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
        printf("6- Listar Autores \n");
        printf("7- Alta Prestamos\n");
        printf("8- Listar Prestamos  \n\n");

        printf("9- Libros solicitados por un socio D \n\n");
        printf("10 -Socios que solicitaron prestamo de un libro C \n\n");
        printf("11 - Listar socios ordenamos por apellido- vacio J \n\n");


        printf("14- Salir  \n\n");
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
            mostrar_Autores(listaAutores,TAM_AUTORES);
            break;

        case 7:
            if(hay_Socios_Cargados(listaSocios,TAM_SOCIOS)==0)
            {
                system("cls");

                alta_Prestamos(listaPrestamos,listaSocios,listaLibros,TAM_SOCIOS,TAM_LIBROS,TAM_PRESTAMOS);


            }
            else
            {
                printf("\nPrimero realize la alta de un empleado\n\n");

            }


            break;
        case 8:
            if(hay_Socios_Cargados(listaSocios,TAM_SOCIOS)==0)
            {
                system("cls");
                mostrar_Prestamos(listaPrestamos,TAM_PRESTAMOS);

            }
            else
            {
                printf("\nPrimero realize un prestamo\n\n");

            }


            break;
        case 9:
            if(hay_Socios_Cargados(listaSocios,TAM_SOCIOS)==0)
            {
                system("cls");
                alquileresPorSocio(listaPrestamos,TAM_PRESTAMOS,listaSocios,TAM_SOCIOS,listaLibros,TAM_LIBROS);//PUNTO D

            }
            else
            {
                printf("\nPrimero realize un prestamo\n\n");
            }


            break;
        case 10:
            if(hay_Socios_Cargados(listaSocios,TAM_SOCIOS)==0)
            {
                system("cls");
                   libroPorSocio(listaPrestamos,TAM_PRESTAMOS,listaSocios,TAM_SOCIOS,listaLibros,TAM_LIBROS); //PUNTO C

            }
            else
            {
                printf("\nPrimero realize un prestamo\n\n");
            }

            break;
                break;
        case 11:
            if(hay_Socios_Cargados(listaSocios,TAM_SOCIOS)==0)
            {
                system("cls");
                orden = getOrder();
                es= sortSocios(listaSocios,TAM_SOCIOS,orden);
                if(es == ERROR)
                {
                    printf("Error al ordenar la lista de empleados.\n\n");
                }

                es = mostrar_Socios(listaSocios,TAM_SOCIOS);
                if(es == ERROR)
                {
                    printf("Error al imprimir los Socios.\n\n");
                }   //J
            }
            else
            {
                printf("\nPrimero realize un prestamo\n\n");
            }


            break;
        case 14:
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
    while(opcion!=14);



    return 0;
}








