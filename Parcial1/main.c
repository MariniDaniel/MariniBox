#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAM_SOCIOS 30
#define TAM_LIBROS 10
#define TAM_AUTORES 5
#define TAM_PRESTAMOS 30
#include "Informes.h"

int main()
{

    eSocio listaSocios[TAM_SOCIOS];
    eLibro listaLibros[TAM_LIBROS];
    eAutores listaAutores[TAM_AUTORES];
    ePrestamo listaPrestamos[TAM_PRESTAMOS];


    int opcion;


    inicializar_Prestamo(listaPrestamos,TAM_PRESTAMOS);
    inicializar_Socios(listaSocios,TAM_SOCIOS);
    init_Autores(listaAutores,TAM_AUTORES);
    init_Libros(listaLibros,TAM_LIBROS);




    do
    {

        system("color F0");
        printf("  *** ABM  SociosParcial1 ***\n\n");
        printf("1- Alta Socios\n");
        printf("2- Listar Socios\n");
        printf("3- Modificar Socios\n");
        printf("4- Baja Socios\n");
        printf("5- Prestamos\n");
        printf("6- Informes\n\n");
        printf("7- Hardcodear Datos\n\n");
        printf("8- Salir\n\n");
        printf("Ingrese opcion: ");
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
                printf("\nPor favor cargue un socio antes de entrar\n\n");

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
                printf("\nPor favor cargue un socio antes de entrar\n\n");

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
                printf("\nPor favor cargue un socio antes de entrar\n\n");

            }


            break;
            case 5:
             if(hay_Socios_Cargados(listaSocios,TAM_SOCIOS)==0)
            {
                system("cls");

                menu_Prestamos(listaPrestamos,TAM_PRESTAMOS,listaSocios,TAM_SOCIOS,listaLibros,TAM_LIBROS,listaAutores,TAM_AUTORES);


            }
            else
            {
                printf("\nPor favor cargue un socio antes de entrar\n\n");

            }


            break;
            case 6:
             if(hay_Socios_Cargados(listaSocios,TAM_SOCIOS)==0)
             {

             menu_Informe(listaPrestamos,TAM_PRESTAMOS,listaSocios,TAM_SOCIOS,listaLibros,TAM_LIBROS,listaAutores,TAM_AUTORES);

             }

            else
            {
                printf("\nPor favor cargue un socio antes de entrar\n\n");

            }
            break;
        case 7:
           init_Socios(listaSocios,TAM_SOCIOS);
           init_Prestamo(listaPrestamos,TAM_PRESTAMOS);

            printf("SOCIOS Y PRESTAMOS HARDCODEADOS\n");
            break;
             case 8:
            printf("\nADIOS\n");
            break;
        default:
            printf("\nERROR! Por favor ingrese una opcion valida <1-8>\n");
            break;

        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(opcion!=8);



    return 0;
}
