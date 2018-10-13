#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

#define TAM 5


int main()
{
    system("color f0");
    //error 1 ok 0
    int opcion;
    int retorno;
    char respuesta = 's';

    eJuego juegos[TAM];
    eCliente clientes[TAM];
    eCategoria categorias[TAM];
    eAlquileres alquiler[TAM];

    inicializarClientes(clientes, TAM);
    inicializarAlquileres(alquiler, TAM);
    cargarCategorias(categorias, TAM);
    cargarJuegos(juegos, TAM, categorias, TAM);
    do
    {
        opcion = menu();

        switch(opcion)
        {
        case 1:
            retorno = altaCliente(clientes, TAM);

            if(retorno == 1)
            {
                printf("\nNo se puede dar mas de alta,espacio lleno.\n");
            }
            break;
        case 2:
            retorno = hayClientes(clientes, TAM);
            if(retorno == 0)
            {

                retorno = bajaCliente(clientes, TAM);
                if(retorno == 1)
                {
                    printf("\nNo existe el cliente ingresado\n");
                }

            }
            else
            {
                printf("\n No hay clientes para dar de baja\n");
            }
            break;
        case 3:
            retorno = hayClientes(clientes, TAM);
            if(retorno == 0)
            {
                retorno = modificarCliente(clientes, TAM);
                if(retorno == 1)
                {
                    printf("\nNo existe el cliente ingresado\n");
                }
            }
            else
            {
                printf("\nNo hay clientes para modificar\n");
            }
            break;
        case 4:
            retorno = hayClientes(clientes, TAM);
            if(retorno == 0)
            {
                listarClientes(clientes, TAM);
            }
            else
            {
                printf("\nNo hay Clientes para listar\n");
            }
            break;
        case 5:
            retorno = altaAlquiler(alquiler, TAM, juegos, TAM, clientes, TAM,categorias);
            if(retorno == 1)
            {
                printf("\nNo hay clientes dados de alta.\n");
            }
            break;
        case 6:
            retorno = hayAlquileres(alquiler, TAM);
            if(retorno == 0)
            {
                listarAlquileres(alquiler, TAM, clientes, TAM, juegos, TAM, categorias, TAM);
            }
            else
            {
                printf("\nNo hay alquileres para listar\n");
            }
            break;
        case 7:

                listarCategorias(categorias,TAM);


            break;

        case 8:
//            mostrarJuegosDeMesa(juegos,TAM,categorias,TAM);
            break;
        case 9:
            exit(0);
            break;
        default:
            break;
        }

        do
        {
            fflush(stdin);
            printf("\nDesea continuar? [s/n]\n");
            scanf("%c", &respuesta);
        }
        while(respuesta != 's' && respuesta != 'n');
    }
    while(respuesta == 's');
    return 0;
}



